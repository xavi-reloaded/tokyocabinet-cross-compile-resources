

SHELL = /bin/sh
srcdir = .


CC = gcc
CPPFLAGS = 
CFLAGS = -g -O2 -DENABLE_PTHREAD
LDFLAGS = 
INCLUDES = -I$(srcdir)

DEFS = -DPACKAGE_NAME=\"\" -DPACKAGE_TARNAME=\"\" -DPACKAGE_VERSION=\"\" -DPACKAGE_STRING=\"\" -DPACKAGE_BUGREPORT=\"\" -DSTDC_HEADERS=1 -DHAVE_SYS_TYPES_H=1 -DHAVE_SYS_STAT_H=1 -DHAVE_STDLIB_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STRINGS_H=1 -DHAVE_INTTYPES_H=1 -DHAVE_STDINT_H=1 -DHAVE_UNISTD_H=1 -DHAVE_STRING_H=1 -DHAVE_MEMORY_H=1 -DHAVE_STDLIB_H=1 -DHAVE_MEMCPY=1 -DHAVE_MEMSET=1 -DH_ERRNO_DECLARED=1 
LIBS = 
LIBOBJS =  dummyin6$U.o

AUTOCONF = autoconf
AUTOCONF_FLAGS = 
ACLOCAL = aclocal
ACLOCAL_FLAGS = -I m4

PROGRAMS = gaitest gnitest

PACKAGE = getaddrinfo
DISTFILES = Makefile.in NEWS README aclocal.m4 configure configure.ac \
	dummyin6.c dummyin6.h gaitest.c gaitest.exp getaddrinfo.c \
	getaddrinfo.h gnitest.c gnitest.exp memset.c \
	m4/herrno.m4 m4/in6addr.m4 m4/sockaddrin6.m4 m4/sockinttypes.m4

LIB = lib$(PACKAGE).a
LIBOBJFILES = getaddrinfo.o

.PHONY: all
#all: $(PROGRAMS)
all : $(PROGRAMS) $(LIB)
	@echo "To invoke test program, type \`$(MAKE) check'"

lib$(PACKAGE).a : $(LIBOBJFILES)
	$(AR) $(ARFLAGS) $@ $(LIBOBJFILES)

.c.o:
	$(CC) -c $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $<

gaitest: gaitest.o getaddrinfo.o $(LIBOBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ gaitest.o getaddrinfo.o \
	    $(LIBOBJS) $(LIBS)

gnitest: gnitest.o getaddrinfo.o $(LIBOBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ gnitest.o getaddrinfo.o \
	    $(LIBOBJS) $(LIBS)

Makefile:  $(srcdir)/Makefile.in config.status
	CONFIG_HEADERS= CONFIG_LINKS= CONFIG_FILES=$@ $(SHELL) ./config.status

config.status: $(srcdir)/configure 
	$(SHELL) ./config.status --recheck

$(srcdir)/configure: $(srcdir)/configure.ac $(srcdir)/aclocal.m4
	cd $(srcdir) && $(AUTOCONF) $(AUTOCONF_FLAGS)

$(srcdir)/aclocal.m4:
	cd $(srcdir) && $(ACLOCAL) $(ACLOCAL_FLAGS)

.PHONY: install
install:
	@echo "nothing to be installed."

.PHONY: clean
clean:
	-rm -f $(PROGRAMS) *.o *.out

.PHONY: distclean
distclean: clean
	-rm -f config.status config.cache config.log Makefile

.PHONY: check test
check test: $(PROGRAMS)
	@rm -f gaitest.out
	./gaitest | sed 's/\(canonname = localhost\)\..*$$/\1/' > gaitest.out
	@if diff -c gaitest.exp gaitest.out >/dev/null 2>&1 ; then \
	    echo "getaddrinfo test passed" ; \
	else \
	    echo "getaddrinfo test failed" ; \
	fi
	@rm -f gnitest.out
	./gnitest > gnitest.out
	@if diff -c gnitest.exp gnitest.out >/dev/null 2>&1 ; then \
	    echo "getnameinfo test passed" ; \
	else \
	    echo "getnameinfo test failed" ; \
	fi

.PHONY: dist
dist: Makefile
	rm -rf $(PACKAGE).tar.gz $(PACKAGE)
	mkdir $(PACKAGE)
	mkdir $(PACKAGE)/m4
	for I in $(DISTFILES); do \
	    cp -p $$I getaddrinfo/$$I; \
	done
	tar cf - $(PACKAGE) | gzip -9c > $(PACKAGE).tar.gz 
	rm -rf $(PACKAGE)

gaitest.o: gaitest.c getaddrinfo.h dummyin6.h
gnitest.o: gnitest.c getaddrinfo.h dummyin6.h
getaddrinfo.o: getaddrinfo.c getaddrinfo.h dummyin6.h
dummyin6.o: dummyin6.c dummyin6.h
memset.o: memset.c

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
