#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);
int all;     /*total length */
all = 0;

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

  for(i = 0/*all*/; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
    s[i] = c;
    /*++all;*/
  }
  if(c == '\n') {
    s[i] = c;
    ++i;
    /*++all;*/
  }
  s[i] = '\0';
  printf("%d\n",i);
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
