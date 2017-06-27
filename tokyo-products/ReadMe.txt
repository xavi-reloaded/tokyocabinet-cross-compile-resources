MinGW DLLs only contain TC utilities and TT client code. TC database code is omitted, as is TT server.
The MinGW package is only for connecting to a TT server from a Windows client.
The Cygwin package contains the full TC API, and the TT client API.
Compiled and packaged by Balint Seeber (balint at the domain spench dot net)

The original source is modified here to allow inclusion from a MSVC-project.
You should also have the relevant headers available (e.g. pthread.h)

Original source versions:
tokyocabinet-1.4.26
tokyotyrant-1.1.28
Copyright (C) 2006-2009 Mikio Hirabayashi

(As of 16/10/09, the newer TC/TT versions don't contain any new code/fixes that affect client connection to the server according to the changelog on SF.net)

MinGW DLLs compiled with Bloodshed Dev-C++ v4.9.9.2
Libs re-created with GNU dlltool (from Cygwin, must be version >= 2.18 to produce correct DLL import libs for VC)
The original source was also modified separately to allow it to compile under MinGW (e.g. replacing errno with WSAGetLastError and checking WSA error constants).
This 'compilation code' is different from the packaged 'inclusion code' since only the headers from the 'inclusion code' are used (although the packaged .c are modified, it was a failed attempt to create a native MSVC port).
The 'compilation code' can be found at: http://spench.net/drupal/software/tokyocabinet
