#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];	//buffer for ungetch
int bufp = 0;		//next free position in buf

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(c == EOF)
    printf("error: can't ungetch EOF");
  else {
    if(bufp >= BUFSIZE)
      printf("error/ungetch: too many characters/n");
    else
      buf[bufp++] = c;
  }
}
