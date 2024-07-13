#include <stdio.h>

	/* convert char to lower case with conditional expression */

int main()
{
  char c = getchar();
  char c1 = c;
  printf("\n");

  	/* convert with if-else; (check) */
  if(c >='A' && c <= 'Z')
    printf("%c\n",(c + 'a'-'A'));
  else
    printf("%c\n",c);

  	/* convert with conditional expression */
  printf("%c\n", (c1 >= 'A' && c1 <= 'Z') ? c1 + 'a' - 'A' : c1);

  return 0;
}
