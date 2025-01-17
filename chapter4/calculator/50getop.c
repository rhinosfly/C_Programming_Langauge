#include <stdio.h>
#include <ctype.h>
#include "50calc.h"

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
