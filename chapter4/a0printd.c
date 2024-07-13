#include <stdio.h>

/*
  print integer using recusion
*/

int main()
{
  int x = 12345;
  printd(x);

  return 0;
}

void printd(int n)
{
  if(n < 0) {
    putchar('-');
    n = -n;
  }
  if(n / 10)
    printd(n / 10
