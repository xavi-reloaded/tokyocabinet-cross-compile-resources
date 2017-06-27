# Makefile for sample programs of Hyper Estraier



#================================================================
# Setting Variables
#================================================================


# Generic settings
SHELL = /bin/sh

# Targets
MYBINS = tcrdbex tcrdbtblex

# Building binaries
CC = gcc
CFLAGS = -ansi -Wall -pedantic -I. -I..
C99FLAGS = -std=c99 -Wall -pedantic -I. -I..
LDFLAGS =
#LDFLAGS = ../tcrdb.o ../ttutil.o ~/getaddrinfo/getaddrinfo.o
#LDFLAGS = ~/getaddrinfo/getaddrinfo.o
#LIBS = -L. -L.. -ltokyotyrant -ltokyocabinet -lz -lresolv -lnsl -lpthread -lm -lc
#LIBS = -L. -L.. -ltokyocabinet -lz -lpthread -lm -lc -lbz2
LIBS = -L. -L.. -ltokyotyrant -ltokyocabinet -lz -lpthread -lm -lc -lbz2
LDENV = LD_RUN_PATH=/lib:/usr/lib:"$(HOME)/lib":/usr/local/lib:.:..



#================================================================
# Suffix rules
#================================================================


.SUFFIXES :
.SUFFIXES : .c .o

.c.o :
	$(CC) -c $(CFLAGS) $<



#================================================================
# Actions
#================================================================


all : $(MYBINS)


clean :
	rm -rf $(MYBINS) *.exe *.o a.out check.out gmon.out leak.log casket* *~


.PHONY : all clean



#================================================================
# Building binaries
#================================================================


tcrdbex : tcrdbex.o
	$(LDENV) $(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LIBS)


tcrdbtblex : tcrdbtblex.o
	$(LDENV) $(CC) $(CFLAGS) -o $@ $< $(LDFLAGS) $(LIBS)



# END OF FILE
