#include <stdio.h>
#include "/home/linus/Documents/c/func/getd.c"

/* invert n bits starting at position p of x */

int invert(int, int, int);

int main()
{
  printf("x,p,n\n");
  int x = getd();
  int p = getd();
  int n = getd();
  int res = invert(x,p,n);
  printf("%d, %d, %d\n%d\n",x,p,n,res);
}

int invert(int x, int p, int n)
{
  return((x&~((~(~0<<n))<<(p+1-n))) | (((~(x>>(p+1-n)))&(~(~0<<n)))<<(p+1-n)));
}
