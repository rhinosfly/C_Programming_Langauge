#pg =	112
CFLAGS = -g -ansi
CC=gcc
VPATH = /home/linus/Documents/c/func 
ALL = 20getint_main 22getfloat_main 30strlen 40alloc.o 50strfuncs.o 53strfuncs_main 60strSort 67strSort 70dateCalc 99dateCalc a01echo a02echo a03grep a04grep a0a0expr a0a3tail a10qsort a1a4qsort a20dcl a20undcl

all: $(ALL)
20getint_main: 	20getint_main.o 20getint.a
20getint_main.o:	20getint_main.c 20getint.h
20getint.o:	20getch.h 20getint.c
20getch.o:	20getch.c
20getint.a:	20getch.o 20getint.o
	ar rs 20getint.a 20getch.o 20getint.o
22getfloat_main: 22getfloat_main.o 22getfloat.o 20getch.o
22getfloat_main.o:	22getfloat_main.c 22getfloat.h
22getfloat.o:	22getfloat.c 20getch.h
30strlen:	30strlen.c
40alloc.o:	40alloc.c
50strfuncs.o:	50strfuncs.c
53strfuncs_main:  	53strfuncs_main.o 53strfuncs.o
53strfuncs_main.o:	53strfuncs_main.c 53strfuncs.h
53strfuncs.o:	53strfuncs.c
60strSort:	60strSort.c 40alloc.o
67strSort:	67strSort.c
70dateCalc:	70dateCalc.c
getint.o:	getint.c
99dateCalc:	99dateCalc.c
a01echo:	a01echo.c
a02echo:	a02echo.c
a03grep:	a03grep.c mygetline.o mygetline.h
mygetline.o:	mygetline.c
a04grep:	a04grep.c mygetline.o mygetline.h
a0a0expr:	a0a0expr.c
a0a3tail:	a0a3tail.c mygetline.o 40alloc.o
a10qsort:	a10qsort.c mygetline.o 40alloc.o
a1a4qsort:	a1a4qsort.c mygetline.o 40alloc.o
a20dcl:		a20dcl.c 20getch.o
a20undcl:	a20undcl.c 20getch.o

clean:
	rm $(ALL) *.o *.a
