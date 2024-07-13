#include<stdio.h>

/* determine range of char, short, int and long. signed and unsigned, from standard headers by direct computation */

main()
{
  printf("start test\n");
  
 /* signed int range 

  signed int i;
  signed int max;
  signed int myint;

  for(myint = 0; myint <= 0; --myint) {
    i = myint;
    if(i < max)
      max = i;
  }
  printf("%d",max);
  for(myint = 0; myint >= 0; ++myint) {
    i = myint;
    if(i > max)
      max = i;
  }
  printf(" %d\n",max);
  printf("end test1\n");
 
   unsigned int range */

  unsigned int i0;
  unsigned int j0;
  unsigned int myint0;

  i0 = 0;
  j0 = 1;
  for(myint0 = 0; i0 != j0; ++myint0) {
    /*
    ++i0;
    ++j0;*/
      printf("%d  ",myint0);
  }

  /*
  for(myint0 = 0; myint0 <= 0; --myint0) {
    i0 = myint0;
    if(i0 < max0)
      max0 = i0;
  }
  printf(" %d\n",max0);
  */
  printf("end test2\n");
}
