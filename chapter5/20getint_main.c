#include <stdio.h>
#include "20getint.h"
/*
  call getint
*/

int main()
{
  int n;

  getint(&n);
  printf("n = %d\n&n = %d\n", n, &n);
  
  return 0;
}
