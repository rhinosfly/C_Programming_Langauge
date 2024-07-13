#include <stdio.h>
#define MAX 1000

void get(char a[], char b[]);
void squeeze(char a[], char b[]);

/* remove string b from string a from input. print string a */

int main()
{
  char a[MAX],b[MAX];

  get(a,b);
  printf("\nstrings:\n(%s)\n(%s)\n",a,b);
  squeeze(a,b);
  printf("\nFinal: \n(%s)\n",a);

  return 0;
}

/* fill a and b with lines 1 and 2 of input */

void get(char a[], char b[])
{
  int i;
  
  for(i = 0; (a[i] = getchar()) != '\n'; i++)
    ;
  a[i] = '\0';
  for(i=0; (b[i] = getchar()) != EOF && b[i] != '\n'; i++)
    ;
  b[i] = '\0';
}

/* remove string b from string a */

void squeeze(char a[], char b[])
{
  int i,j,k;	/* incrementors */
  int x;	/* counter for coincidences */	

  for(i = j = 0; a[i] != '\0'; i++) {
    for(k = x = 0; b[k] != '\0'; k++)
      if(a[i] == b[k])
	x++;
    if(x == 0)
      a[j++] = a[i];
  }
	
  a[j] = '\0';
}

