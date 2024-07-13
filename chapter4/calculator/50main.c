#include <stdio.h>
#include <stdlib.h>
#include "50calc.h"

/*
pg79; reverse polish calculator; multiple files
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
	printf("error/devision: zero devisor");
      break;
    case '%':
      op2 = pop();
      if(op2 != 0.0)
	push((int) pop() % (int) op2);
      else
	printf("error/modulus: zero devisor");
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
	printf("error/main: unknown command %s\n", s);
	break;
      }
    }
  }
  return 0;
}
