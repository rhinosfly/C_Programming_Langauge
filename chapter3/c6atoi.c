#include <stdio.h>
#include "/home/linus/Documents/c/func/reverse.c"
#include "/home/linus/Documents/c/func/getd.c"

/* convert int n to characters in char s; minimum field width: w */

void itoa(int n, char s[], int w);

int main()
{
  int n = getd();
  int w = getd();
  char s[100];

  itoa(n,s,w);
  printf("%s\n",s);
  
  return 0;
}

void itoa(int n, char s[], int w)
{
  int i, sign;
  
  if((sign = n) < 0)
    n = -n;
  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while((n /= 10) > 0);
  if(sign < 0)
    s[i++] = '-';
  while(i < w)
    s[i++] = ' ';
  s[i] = '\0';
  reverse(s);
}
  
