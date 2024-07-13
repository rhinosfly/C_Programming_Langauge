#include<stdio.h>

#define MAXLINE	1000	/* max input line size */

int max;		/* max length seen */
char line[MAXLINE];	/* current input line*/
char longest[MAXLINE];	/* logest line */

int getline(void);
void copy(void);

/* print logest input line; specialized version */

int main()
{
  int len;
  extern int max;
  extern char longest[];

  max = 0;
  while ((len = getline()) > 0)
    if(len > max) {
      max = len;
      copy();
    }
  if(max > 0)		/* there was a line */
    printf("%s",longest);
  return 0;
}

int getline(void)
{
  int c, i;
  extern char line[];

  for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copy(void)
{
  int i;
  extern char line[], longest[];

  i = 0;
  while ((longest[i] = line[i]) != '\0')
    ++i;
}
