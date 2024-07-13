#include <stdio.h>
#include "/home/linus/Documents/c/func/reverse.c"

/* convert int n to characters in char* s; handles largest negative */


int main()
{
  long int n = (1<<31);
  char s[100];
  int i, sign;
  
  if((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if(sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);

  printf("%s\n",s);
  
  return 0;
}
