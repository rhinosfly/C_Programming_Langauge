#include <stdio.h>
#include <ctype.h>
#include "20getch.h"
/*
  getint: get next integer from input into *pn
*/

int getint(int *pn)
{
  int c,d, sign;

  //skip while space
  while(isspace(c = getch()))
    ;
  if(c == '+' || c == '-') {
    if(isdigit(d = getch())) {
      ungetch(d);
    }
    else {
      ungetch(d);
      ungetch(c);
      return 0;
    }
  }
      
  if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);		//not a number
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-')
    c = getch();
  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return c;
}
