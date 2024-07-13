#include <stdio.h>

#define IN  1   /*inside word*/
#define OUT 0   /* outside word */

/*
  print input one word per line
*/

int main()
{
  int c,nl,nw,nc, state;
  state = OUT;
  nl=nw=nc=0;
  while((c = getchar()) != EOF) {
    ++nc;
    if (c == ' ' || c == '\n' || c == '\t')
      state = OUT;
    else {
      if (state == OUT)	{
	state = IN;
	printf("\n");
	putchar(c);
      }
      else if(state == IN)
	putchar(c);
    }
  }
}
