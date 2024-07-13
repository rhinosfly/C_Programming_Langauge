#include <stdio.h>
#include <stdlib.h>

#define MAXOP 	100	// max size of operand or operator
#define NUMBER	'0'	//signal that a number was found
//save test1
int getop(char []);
	// get next operator or numeric operand
void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack

// reverse polish calculator; includes %(modulus) operator and negatives
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

int getop(char s[])
{
  int i, c, d, x;
  x = 1;	//other operation
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