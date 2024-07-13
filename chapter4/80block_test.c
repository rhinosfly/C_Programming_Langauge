#include <stdio.h>

/*
  test how declaring variables inside if statements work
*/

int main()
{
  int x;
  int y;
  int i = 23;
  
  x = 2;
  y = 3;
  
  if(x < y) {
    int i;
    i = x + y;
    printf("\"true\" i = %d\n", i);
  }
  printf("external i = %d\n", i);
}
