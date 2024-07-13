/*find all lines matching pattern ; edit*/
#include <stdio.h>
#define MAXLINE 1000		/* max input line length */

int gettline(char line[], int max);
/*getline: get line into s, return length */
int strindex(char s[], char t[]);
/* sterindex: return index of t in s, -1 in none */

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
  for(i = 0; s[i] != '\0'; i++) {
    for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if(k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}
  
