CFLAGS=-ansi -Wall
CC=gcc
#64
ALL=p3 c1 p4 c2 c3 c4 c5atob c6atoi
VPATH=/home/linus/Documents/c/func

all: $(ALL)
p3: p3.c
c1: c1.c
p4: p4.c
c2: c2.c
c3: c3.c
c4: c4.c
c4.c: reverse.c
reverse.c: reverse.h
c5atob: c5atob.c
c5atob.c: reverse.c
c6atoi: c6atoi.c
c6atoi.c: reverse.c getd.c

all: $(ALL)

clean:
	rm$(ALL)
