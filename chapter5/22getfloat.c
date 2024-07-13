#include <stdio.h>
#include <ctype.h>
#include "20getch.h"
/*
  getint: get next float from input into *pn
*/

int getfloat(float *pn)
{
  int c,d, sign, placeCounter;
  float power;

  //skip while space
  while(isspace(c = getch()))
    ;
  if(c == '+' || c == '-') {
    if(isdigit(d = getch()) || d == '.') {
      ungetch(d);
    }
    else {
      ungetch(d);
      ungetch(c);
      return 0;
    }
  }
      
  if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
    ungetch(c);		//not a number
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if(c == '+' || c == '-')
    c = getch();
  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if(c == '.')
    for(c = getch(), power = 10, placeCounter = 0; isdigit(c); c = getch(), (power *= 10), placeCounter++)
      *pn += ((c - '0') / power);
    *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return placeCounter;
}
