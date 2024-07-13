#include <stdio.h>

/* get n bits from position p */
unsigned getbits(unsigned x, int p, int n);

/* call getbits and print bits */
int main()
{
  int x = 0555; /* 101-101-101 */
  int p = 4;
  int n = 3;

  printf("%o\n",getbits(x,p,n));

  return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
  return ( x >> (p + 1 -n)) & ~(~0 << n);
}
