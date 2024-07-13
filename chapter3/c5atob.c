#include <stdio.h>
#include "/home/linus/Documents/c/func/reverse.c"
#define EXN 31
#define MAX 1000
#define EXB 16

/* func atob(n,s,b) converts int to string in base:b */

void atob(int n, char s[], int b);

int main()
{
  int n = EXN;
  char s[MAX];
  int b = EXB;

  atob(n,s,b);
  printf("%s\n",s);
  
  return 0;
}

void atob(int n, char s[], int b)
{
  int i,x,sign;
  
  if((sign = n) < 0)
    n = -n;
  i = 0;
  do {    
    if((x = n % b) > 9)
      x = (x - 9) + ('A' - '1');
    s[i++] = x  + '0';
  } while((n /= b) > 0);
  if(sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
  
