#include <stdio.h>
#include "/home/linus/Documents/c/func/getd.c"

int setbits(int, int, int, int);

/* call setbits */
int main()
{
  int x = getd();
  int y = getd();
  int p = getd();
  int n = getd();
  int res = setbits(x,y,p,n);
  printf("\n%d\n",res);
  
  return 0;
}

int setbits(int x,int y, int p, int n)
{
  return(((y & ~(~0 << n)) << (p-n)) | (~(~(~0 << n) <<(p-n))&x));
}
