#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/*print longest input line */

int main()
{
  int len;	/* current line length */
  int max;	/* max length seen*/
  char line[MAXLINE]; /* current input line */
  char longest[MAXLINE]; /* longest line saved here*/

  max = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if(max > 0)   /*there was a line*/
    printf("%s\n", longest);
  return 0;
}

/* getline: read a line into s, retunr length */

int getline(char s[], int lim)
{
  int c, i;

    i = 0;
  if(i < lim - 1) {
    c = getchar();
    if(c != EOF)
      if(c != '\n') {
	s[i] = c;
	++i;
      }
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; asume to is big enough */

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while((to[i] = from[i]) != '\0')
    ++i;
}
