#include <stdio.h>
#define MAXLEN 100

int mystrlen(char *);
int mystrlen2(char *s);
//strlen/strlen2: return length of string

/*
  main: call strlen on string from input
*/

int main()
{
  char s[MAXLEN];
  int len;

  for(len = 0; (s[len] = getchar()) != EOF; len++)
    ;
  s[len] = '\0';
  printf("len = %d\nlen2 = %d\nlen3 = %d\n", len,mystrlen(s),mystrlen2(s));

  return 0;
}

int mystrlen(char *s)
{
  int n;

  for(n = 0; *s != '\0'; s++)
    n++;
  return n;
}

int mystrlen2(char *s)
{
  char *p = s;

  while(*p != '\0')
    p++;
  return p - s;
}
