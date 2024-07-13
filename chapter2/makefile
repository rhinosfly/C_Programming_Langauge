CFLAGS=-ansi -Wall
CC=gcc

ALL= c1 c2 m7 c3 c4 m9 c6 c7 c9 c10
VPATH=/home/linus/Documents/c/func

all: $(ALL)
c1:   c1.c
c2:   c2.c
m7:   m7.c
c3:   c3.c
c4:   c4.c
#detobi: detobi.c
m9:   m9.c
c6:   c6.c
c6.c: getd.c
getd.c: getd.h
c7:   c7.c
c7.c: getd.c
c9:   c9.c
c10:  c10.c

clean:
	rm$(ALL)
