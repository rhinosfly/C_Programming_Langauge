#include <stdio.h>
#include "22getfloat.h"
/*
  call getfloat
*/

int main()
{
  float n;
  int placeCounter;

  placeCounter = getfloat(&n);
  //#define myprint(x)	printf("n = %." #x "f\n", n, x)
  //  myprint(placeCounter);
  printf("n = %f\n", n);
  
  return 0;
}
