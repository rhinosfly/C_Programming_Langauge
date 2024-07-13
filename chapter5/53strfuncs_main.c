#include <stdio.h>
#include "53strfuncs.h"
#define MAX 100
/*
  test 53strfuncs functions
*/

int main()
{
  char smain[] = "hello, ";
  char tmain[] = "world!";
  char s[MAX];
  char t[MAX];
  int x;

  copy(s, smain);
  copy(t, tmain);
  mystrcat(s, t);
  printf("mystrcat\n(%s)\n(%s)\n", s,t);
  x = mystrend(s,t);
  printf("mystrend\n(%s)\n(%s)\n%d\n", s,t,x);
  mystrncopy(s, smain, 5);
  mystrncopy(t, tmain, 5);
  printf("mystrncopy\n(%s)\n(%s)\n", s,t);
  mystrncat(s,t,3);
  printf("mystrncat\n(%s)\n(%s)\n", s,t);
  copy(s, smain);
  x = mystrncmp(tmain, smain, 4);
  printf("mystrncmp\n(%s)\n(%s)\n%d\n", tmain, smain,x);  
  
  return 0;
}
