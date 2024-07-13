#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void push(double);
	// push f onto value stack
double pop(void);
	//pop and return top value from stack

/* pg118; evaluate reverse polish notation from command line */
int main(int argc, char *argv[])
{
  double op2;
  while(--argc > 0) {
    if(isdigit(**++argv))
      push(atof(*argv));
    else
      switch(**argv) {
      case '+':
	push(pop() + pop());
	break;
      case 'x':
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
      default:
	printf("error: unknown command %s\n", *argv);
	break;
      }
  }
  printf("%.3g\n", pop());

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
