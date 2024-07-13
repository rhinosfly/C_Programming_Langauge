#include <stdio.h>

int atoi(char s[]);

int main()
{
  char s[] = "123456789abcdef0";

  printf("%x\n", atoi(s));

  return 0;
}

int atoi(char s[])
{
  int i, n;

  n = 0;
  for(i = 0; s[i] >= '0' && s[i] <= 'f'; ++i)
    n = 0x10 * n + (s[i] - '0');
  return n;
}
