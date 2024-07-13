#include <stdio.h>

/* convert decimal int to binary */
/* IN PROGRESS */

int get();		/* get int from input */
int atoi(char s[])	/* get in from string */
int fmax(int num);	/* find greatest 2^n less than num */
int pow(int base,int power); /* calculate power*/

int main()
{
  int num = get();
  int max = fmax(num);
  
}

int get()
{
  char s[];
  int i,c;
  int num;

  for(i = 0; (c = getchar()) != EOF; i++)
    s[i] = c;
  s[i] = '\0';
  num = atoi(s);
  return num;
}

int atoi(char s[])
{
  int i, n;

  n = 0;
  for(i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
  return n;
}

int fmax(int num)
{
  int i,n;

  n = 0;
  for(i = 0; n <= num; i++)
    n = pow(2,i);
  return n;
}

int pow(int base,int power)
{
  int i,p;

  p = 1;
  for(i = 1; i <= power; ++i)
    p = p * base;
  return p;
}
