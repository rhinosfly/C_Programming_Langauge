#include <stdio.h>

int main()
{
  char str[20];
  int d;
  int i, n = 5;
  int r;
  
  for(i = 0; i < n; i++)
    r = scanf("%s%d", &str, &d);
  printf("%s, %d\n", str, d);
  return 0;
}
