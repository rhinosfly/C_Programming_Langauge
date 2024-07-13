CFLAGS= -Wall -g
CLIBS=-lm
CC=gcc
#page: 79
ALL= 10grep 11grep 20atof 22atof 30calculator 31calculator 34calculator 35calculator 37calc 38calc 39calc 50calc 6a1calc 80block_test a0printd
VPATH=/home/linus/Documents/c/func

all: $(ALL)
10grep: p1grep.c
11grep: c1grep.c
20atof: 20atof.c
22atof: 22atof.c
30calculator: 30calculator.c
31calculator: 31calculator.c
34calculator: 34calculator.c
35calculator: 35calculator.c
37calc: 37calc.c
38calc: 38calc.c
39calc: 39calc.c
50files = 50main.o 50getop.o 50stack.o 50getch.o 50command.o
50calc: $(50files)
	$(CC) $(CFLAGS) $(CLIBS) -o $(50files)
50main.o:	50main.c 50calc.h
50getop.o:	50getop.c 50calc.h
50command.o:	50command.c 50calc.h
50stack.o:	50stack.c 50calc.h
50getch.o:	50getch.c 50calc.h

6a1calc:	6a1calc.c
80block_test: 	80block_test.c
a0printd:	a0printd.c
clean:
	rm$(ALL) *.o 
