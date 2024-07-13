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

// reverse polish calculator
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
  else
    printf("error: stack full, can't push %g\n", f);
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
  int i;
  static int c;
  static int isdef_c = 0;

  //skip white space; get c if needed
  if(isdef_c)
    while ((s[0] = c) == ' ' || c == '\t')
      c = getchar();
  else
    while ((s[0] = c = getchar()) == ' ' || c == '\t')
      ;
  //not a number
  s[1] = '\0';
  if(!isdigit(c) && c != '.') {
    isdef_c = 0;
    return c;
  }
  //collext inger part
  i = 0;
  if(isdigit(c))	
    while(isdigit(s[++i] = c = getch()))
      ;
  //collect fraction part
  if(c == '.')		
    while(isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  isdef_c = 1;
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
