#pg =	136
CFLAGS = -g -Wall
CC=gcc
VPATH = /home/linus/Documents/c/func 
ALL = 20funcs 30keycount 31keycount 40keycount 50wordcount 51varcount 52refTable 53wordcount 60hashfuncs 65hashfuncs 66processor

all: $(ALL)
getch.o:	getch.c
20funcs:	20funcs.c
30keycount:	30keycount.c getch.o
31keycount:	31keycount.c getch.o
40keycount:	40keycount.c getch.o
50wordcount:	50wordcount.c getch.o
51varcount:	51varcount.c getch.o
52refTable:	52refTable.c getch.o
53wordcount:	53wordcount.c getch.o
60hashfuncs:	60hashfuncs.c
65hashfuncs:	65hashfuncs.c
66processor:	66processor.c 66hashfuncs.o getch.o
66hashfuncs.o:	66hashfuncs.c


clean:
	rm $(ALL) *.o
