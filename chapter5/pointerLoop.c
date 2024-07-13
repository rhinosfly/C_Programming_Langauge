#include <stdio.h>
int main()
{
  char s[] = "hello!\n";
  
  while(*s++)
    printf("*s = %d\n", *s);
}
