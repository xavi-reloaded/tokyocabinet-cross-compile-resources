#pragma once

#include <tchar.h>

class CygwinLoader
{
public:
	static const int PADDING = 16384;
	BYTE m_pPadding[PADDING];	// Must be on the stack
public:
	CygwinLoader(LPCTSTR strModuleName = NULL)
		: m_hCygwin(NULL)
		, m_pfnDLLInit(NULL)
		//, m_pStack(NULL)
		, m_pTop(NULL)
		, m_nSize(0)
	{
		if (strModuleName)
			_tcscpy_s(m_strModuleName, MAX_PATH, strModuleName);
		else
			_tcscpy_s(m_strModuleName, MAX_PATH, _T("cygwin1"));
	}
	~CygwinLoader()
	{
		Restore();
	}
public:
	typedef void (*cygDLLInit)(void);
public:
	TCHAR m_strModuleName[MAX_PATH];
	HMODULE m_hCygwin;
	cygDLLInit m_pfnDLLInit;
	//LPVOID m_pStack;
	LPVOID m_pTop;
	UINT_PTR m_nSize;
public:
	bool Initialise(bool bShareStdHandles = false)
	{
		if (m_hCygwin)
			return true;

		if (bShareStdHandles)
			SetEnvironmentVariable(_T("CYGWIN"), _T("tty"));

		m_hCygwin = GetModuleHandle(m_strModuleName);
		if (m_hCygwin == NULL)
			return false;

		m_pfnDLLInit = (cygDLLInit)GetProcAddress(m_hCygwin, "cygwin_dll_init");
		if (m_pfnDLLInit == NULL)
		{
			CloseHandle(m_hCygwin);
			m_hCygwin = NULL;
			return false;
		}

		void *pTop/*, *pStack*/;

		__asm
		{
			mov eax, fs:[4];
			mov pTop, eax;

			//mov pStack, esp;
		}

		//m_pStack	= pStack;
		m_pTop		= pTop;
		m_nSize		= (((ptrdiff_t)pTop - ((ptrdiff_t)m_pPadding + PADDING))/* - (sizeof(*this) + (2 * sizeof(LPVOID)) + (2 * sizeof(int)))*/);
		m_nSize		= min(m_nSize, PADDING);

		if (m_nSize)
			memcpy_s(m_pPadding, PADDING, (LPVOID)((ptrdiff_t)pTop - m_nSize), m_nSize);

		(m_pfnDLLInit)();	// Clobbers the top of the stack (doesn't seem to in my tests with VC9 ?!)

		return true;
	}
	void Restore(void)
	{
		if ((m_nSize == 0) || (m_pTop == NULL))
			return;

		memcpy((LPVOID)((ptrdiff_t)m_pTop - m_nSize), m_pPadding, m_nSize);
	}
};
