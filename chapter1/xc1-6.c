#include <stdio.h>

/*copy inpit to output; version1 */

int main()
{
  int c;

  while ((c = getchar()) != EOF)
    putchar(c);
  printf(getchar() != EOF);
}
