#include <stdio.h>

/*
  print histogram of length of words in input
*/

#define IN  1   /* inside a word */
#define OUT 0   /* outside a word*/

int main()
{
  int c,state;

  state = OUT;
  while((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      printf("\n");
    }
    else if (state == OUT) {
      state = IN;
      printf("|");
    }
    else
      printf("|");
}
