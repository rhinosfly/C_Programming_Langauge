/*find all lines matching pattern */ /*edit*/
#include <stdio.h>
#define MAXLINE 1000		/* max input line length */

int gettline(char line[], int max);
/*getline: get line into s, return length */
int strindex(char s[], char t[]);
/* sterindex: return index of t in s, -1 in none */
int len(char x[]);
/* len: return length of x */

char pattern[] = "ould";	/* pattern to search for */

int main()
{
  char line[MAXLINE];
  int found = 0;

  while(gettline(line, MAXLINE) > 0)
    if(strindex(line, pattern) >= 0 ) {
      printf("%s\n", line);
      found++;
    }
  printf("tmp\n");
  return found;
}

int gettline(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if(c =='\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

int strindex(char s[], char t[])
{
  int i, j, k;
  int slen = len(s);
  int tlen = len(t);
  
  for(i = slen-1; i >= 0; i--) {
    for(j = i, k = tlen-1; k >= 0 && s[j] == t[k]; j--, k--)
      ;
    if(k < 0)
      return (i - tlen +1);
  }
  return -1;
}
  
int len(char x[])
{
  int i;

  for(i = 0; x[i] != '\0'; i++)
    ;
  return i;
}
