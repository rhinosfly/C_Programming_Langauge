#include <stdio.h>

/*print histogram of character frequency in input*/

int main()
{
  int c, i,j, nwhite, nother;
  int ndigit[10];

  nwhite = nother = 0;
  for(i = 0; i < 10; ++i)
    ndigit[i] = 0;

  while((c = getchar()) != EOF)
    if(c >= '0'&& c<='9')
      ++ndigit[c-'0'];		/* why the {-'0'} ?*/
    else if(c == ' ' || c == '\n' || c == '\t')
      ++nwhite;
    else
      ++nother;

  for(i = 0; i < 10; ++i) {
    for(j = 0; j < ndigit[i]; j++)
      printf("|");
    printf("\n");
  }
  for(j=0; j < nwhite; j++)
    printf("|");
  printf("\n");
  for(j=0; j < nother; j++)
    printf("|");
  printf("\n");
}
