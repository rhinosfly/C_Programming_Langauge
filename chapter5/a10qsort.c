#include <stdio.h>
#include <string.h>
#include "../func/mygetline.h"
#include "40alloc.h"
#define MAXLINES 5000	/* max #lines to be stored */
char *lineptr[MAXLINES];     /*	pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *,char *);

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines;
  int numeric = 0;

  if(argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort((void **) lineptr, 0, nlines-1,
	    (int (*)(void*,void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  }else {
    printf("input too bif o sort\n");
    return 1;
  }
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
  void swap(void *v[], int, int);

  if(left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for(i = left+1; i <= right; i++)
    if((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  myqsort(v, left, last-1, comp);
  myqsort(v, last+1, right, comp);
}

#include <stdlib.h>

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if(v1 < v2)
    return -1;
  else if(v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j)
{
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

#define MAXLEN 1000	//max length of any input line

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
