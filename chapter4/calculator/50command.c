#include <stdio.h>
#include <math.h>
#include "50calc.h"

int checkstr(char[], char[]);
//check if strings are the same
void print(void);
//print top of stack
void pop1(void);
//pop and print
void duplicate(void);
//duplicate top element of stack
void swap(void);
//swap top two elements of stack
void clear(void);
//clear stack
void ungets(void);
//push string onto buf with getch and ungetch

#define VARNUM 26
  char var[VARNUM];
  char set[VARNUM];

void command(char c)
{
  char d;
  char s[MAXOP];
  int x; 	//varnum position
  int i;
  
  //get command
  s[0] = c;	
  for(i = 1; (d = getch()) != '\n' && d != ' ' && d != '\t'; i++)
    s[i] = d;
  s[i] = '\0';
  ungetch(d);

  if(s[0] == '$') { 	// assign variable
    x = s[1] - 'a';	//find x
    if(s[1] >= 'a' && s[1] <= 'z') {	//valid variable
      push(var[x] = pop());
      set[x] = 1;
    }
    else
      printf("error/command: invalid variable\n");
  }
    
  //if is variable (1 character), 
  else if(i == 1) {
    x = s[0] - 'a';
    if(set[x] == 1)
      push(var[x]);
    else
      printf("error/command: unassigned variable\n");
  }
  
  //find and execute command
    //math.h
  else if(checkstr(s,"sin"))
    push(sin(pop()));
  else if(checkstr(s,"cos"))
    push(cos(pop()));
    //system
  else if(checkstr(s, "ungets"))
    ungets();
  else if(checkstr(s, "print"))
    print();
  else if(checkstr(s, "pop"))
    pop1();
  else if(checkstr(s, "duplicate"))
    duplicate();
  else if(checkstr(s, "swap"))
    swap();
  else if(checkstr(s, "clear"))
    clear();
  else
    printf("error/command: unknown command\n");
}

int checkstr(char s[], char t[])
{
  int i;
  
  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0') {
      return 1;
    }
  return 0;
}

void ungets(void)
{
  int i;
  char s[MAXVAL];
  
  for(i = 1; (s[i] = getch()) != '\n'; i++)
    ;
  s[0] = '\0';
  for(; s[i] != '\0'; i--)
    ungetch(s[i]);
}

extern int sp;
extern double val[];

void print(void)
{
  if(sp > 0)
    printf("\t%.8g\n", val[sp-1]);
  else
    printf("error/print: stack empty\n");
}

void pop1(void)
{
  printf("\t%.8g\n", pop());
}

void duplicate(void)
{
  if(sp > 0) {
    val[sp] = val[sp - 1];
    sp++;
    printf("duplicate complete\n");
  } else
    printf("error/duplicate: stack empty");
}

void swap(void)
{
  double x;

  if(sp > 1) {
    x = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = x;
    printf("swap complete\n");
  } else
    printf("error/swap: less than two elements in stack");
}

void clear(void)
{
  sp = 0;
  printf("clear complete\n");
}
