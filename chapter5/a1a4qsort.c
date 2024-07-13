#include <stdio.h>
#include <string.h>
#include "../func/mygetline.h"
#include "40alloc.h"
#define MAXLINES 5000	/* max #lines to be stored */

char *lineptr[MAXLINES];     /*	pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int dir_ord = 0;
int folding = 0;

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse);
int numcmp(char *,char *);
int mystrcmp(char *s1, char *s2);

/* sort input lines; add -r flag to reverse sort order */
int main(int argc, char *argv[])
{
  int c;
  int nlines;
  int numeric = 0;
  int reverse = 0;
  
  while(--argc > 0) {
    if((*++argv)[0] == '-')
      switch(c = (*argv)[1]) {
      case 'r':
	reverse = 1;
	break;
      case 'n':
	numeric = 1;
	break;
      case 'f':
	printf("folding\n");
	folding = 1;
	break;
      case 'd':
	dir_ord = 1;
	break;
      default:
	printf("warning: invalid flag '%s' ignored\n",*argv);
	break;
      }
    else
      printf("warning: invalid argument '%s' ignored\n",*argv);
  }
  
  if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort((void **) lineptr, 0, nlines-1,
	    (int (*)(void*,void*))(numeric ? numcmp : mystrcmp), reverse);
    writelines(lineptr, nlines);
    return 0;
  }else {
    printf("input too bif o sort\n");
    return 1;
  }
}

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *), int reverse)
{
  int i, last;
  void swap(void *v[], int, int);

  if(left >= right)
    return;
  swap(v, left, (left + right)/2);
  last = left;
  for(i = left+1; i <= right; i++)
    if(!reverse) {
      if((*comp)(v[i], v[left]) < 0)
	swap(v, ++last, i);
    }else
      if((*comp)(v[i], v[left]) > 0)
	swap(v, ++last, i);  
  swap(v, left, last);
  myqsort(v, left, last-1, comp, reverse);
  myqsort(v, last+1, right, comp, reverse);
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

void dircopy(char *, char *);

int mystrcmp(char *t1, char *t2)
{
  int dif = ('a' - 'A');
  char u1[10];
  char u2[10];
  char *s1 = u1;
  char *s2 = u2;

  if(dir_ord) {
    dircopy(t1,u1);
    dircopy(t2,u2);
  }else{
    strcpy(t1,u1);
    strcpy(t2,u2);
  }
  for(; *s1 == *s2 || (folding) ? (*s1 + dif == *s2 || *s1 - dif == *s2) : 0; s1++, s2++)
	if(*s1 == '\0')
	  return 0;
  return *s1 - *s2;
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

 void dircopy(char *t1, char *s1)
 {
   for(;*t1;t1++)
     if(*t1 >= 'A' && *t1 <= 'Z' || *t1 >= 'a' && *t1 <= 'z' || *t1 >= '0' && *t1 <= '9' || *t1 == ' ' || *t1 <= '\t')
       *s1++ = *t1;
 }
