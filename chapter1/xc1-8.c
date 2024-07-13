#include <stdio.h>

/*
  count blanks tabs and newlines from input
*/

int main()
{
  int c,space,tab,nl;

  nl = 0;
  space = 0;
  tab = 0;
  while((c = getchar()) != EOF){
    if(c == ' ')
      ++space;
    if(c == '\t')
      ++tab;
    if(c == '\n')
      ++nl;
  }
  printf("\n%d, %d, %d\n",space,tab,nl);
}
