#include <stdio.h>
#include <string.h>
#include "40alloc.h"

#define MAXLINES 1000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
/* read input lines */
void writelines(char *lineptr[], int nlines);
// write output lines
void qsort(char *lineptr[], int left, int right);
// quicksort

/*
  sort input lines
*/

int main()
{
  int nlines;	// number of input lines read

  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000	//max length of any input line
int mygetline(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = mygetline(line, MAXLEN)) > 0)
    if(nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';	//delete newline
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

//writelines: write output lines
void writelines(char *lineptr[], int nlines)
{
  while(nlines-- > 0)
    printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right)
{
  int i, last;
  void swap(char *v[], int i, int j);

  if(left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for(i = left+1; i <= right; i++)
    if(strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v,left,last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

void swap(char *v[], int i, int j)
{
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int mygetline(char *s, int lim)
{
  int c, i;

  for(i = 0; i<lim-1 && (c = getchar()) != EOF && c!= '\n'; i++)
    s[i] = c;
  if(c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
