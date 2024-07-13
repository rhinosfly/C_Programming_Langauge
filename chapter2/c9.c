#include <stdio.h>

/* count the number of bits in argument */

int main()
{
  int x = getchar();
  int y = x;
  int i = 0;
  int b;

  for(b = 0; x !=0; x>>=1)
    if(x & 01)
      b++;
  printf("%d\n",b);

  while(y != 0)
    {
      y &= (y-1);
      i++;
    }
  printf("%d\n",i);
  return 0;
}
  
