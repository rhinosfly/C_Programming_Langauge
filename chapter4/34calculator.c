#include <stdio.h>
#include <stdlib.h>

#define MAXOP 	100	// max size of operand or operator
#define NUMBER	'0'	//signal that a number was found

int getop(char []);
	// get next operator or numeric operand
void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack
/*
reverse polish calculator; extra commands: print top of stack, duplicate top of stack, swap top two elements, clear stack
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
      printf("\t%.8g\n", pop());
      break;
    case '$':
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
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
void command(void);
//execute correct command

int getop(char s[])
{
  int i, c, d, x;
  x = 1;	//other operation
  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if(c == '$') {
    command();
  }
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

void print(void);
//print top of stack
void duplicate(void);
//duplicate top element of stack
void swap(void);
//swap top two elements of stack
void clear(void);
//clear stack

void command(void)
{
  int c;
  
  while ((c = getch()) == ' ' || c == '\t')
    ;
  if(c != '\n')
    while(getch() != '\n')
      ;
  switch(c) {
  case 'p':
  case 'P':
    print();
    break;
  case 'd':
  case 'D':
    duplicate();
    break;
  case 's':
  case 'S':
    swap();
    break;
  case 'c':
  case 'C':
    clear();
    break;
  default:
    printf("error: not a valid command\n");
    break;
  }
}

void print(void)
{
  if(sp > 0)
    printf("%g\n",val[sp-1]);
  else
    printf("error: stack empty\n");
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
