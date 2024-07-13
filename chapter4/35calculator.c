#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 	100	// max size of operand or operator
#define NUMBER	'0'	//signal that a number was found

int getop(char []);
	// get next operator or numeric operand
void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack
void command(char);
	//execute function; with push and pop
	//or make a variable

/*
pg79; reverse polish calculator; add variables
 */

int main()
{
  int type;
  double op2;
  char s[MAXOP];
  while((type = getop(s)) != EOF) {
    switch(type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if(op2 != 0.0)
	push(pop() / op2);
      else
	printf("error: zero devisor");
      break;
    case '%':
      op2 = pop();
      if(op2 != 0.0)
	push((int) pop() % (int) op2);
      else
	printf("error: zero devisor");
      break;
    case '\n':
      ;
      break;
    default:
      if((type >= 'a' && type <= 'z') || type == '$') {
	command(type);
	break;
      }
      else {
	printf("error: unknown command %s\n", s);
	break;
      }
    }
  }
  return 0;
}
  
#define MAXVAL	100	// max depth of val stack

int sp = 0;		//next free stack position
double val[MAXVAL];	// value stack

void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else {
    printf("error: stack full, can't push %g\n", f);
  }
}

double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
//get a character
void ungetch(int);
//push character back on input
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
      printf("error: invalid variable\n");
  }
    
  //if is variable (1 character), 
  else if(i == 1) {
    x = s[0] - 'a';
    if(set[x] == 1)
      push(var[x]);
    else
      printf("error: unassigned variable\n");
  }
  
  //find and execute command
    //math
  else if(checkstr(s,"sin"))
    push(sin(pop()));
  else if(checkstr(s,"cos"))
    push(cos(pop()));
    //system
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
    printf("unknown command\n");
}

int checkstr(char s[], char t[])
{
  int i;
  
  for(i = 0; s[i] == t[i]; i++)
    if(s[i] == '\0' && t[i] == '\0') {
      return 1;
    }
  return 0;
}  

int getop(char s[])
{
  int i, c, d, x;
  
  x = 1;
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  
  if(c == '-') {
    if(isdigit(d = getch()))
      x = 0; 	//negative
    else
      x = 1; 	//subtraction
    ungetch(d);
  }
  if(!isdigit(c) && c != '.' && x) {
    return c;		//not a number
  }
  i = 0;
  if(isdigit(c) || c == '-')	//collext inger part
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c == '.')		//collect fraction part
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

 

#define BUFSIZE 100

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE)
    printf("ungetch: too many cgaracters/n");
  else
    buf[bufp++] = c;
}

void print(void)
{
  if(sp > 0)
    printf("\t%.8g\n", val[sp-1]);
  else
    printf("error: stack empty\n");
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
    printf("error: stack empty");
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
    printf("error: less than two elements in stack");
}

void clear(void)
{
  sp = 0;
  printf("clear complete\n");
}
