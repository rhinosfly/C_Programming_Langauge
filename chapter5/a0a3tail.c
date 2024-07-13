#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../func/mygetline.h"
#include "40alloc.h"
#define MAXLINE 100

int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int n, int linenum);
/*
  print last n lines of input. n optional argument, 10 by default
*/
int main(int argc, char *argv[])
{
  int i, c, n, cycle = 0, linenum;
  char input[10];
  char *lineptr[MAXLINE];
  
  //get n
    if(argc == 1)
      n = 10;
    while(--argc > 0 && (*++argv)[0] == '-') {
      for(i = 1; (c = (*argv)[i]) >= '0' && c <= '9' && !cycle; i++)
	input[i-1] = c;
      if(!(*argv)[i]) {
	input[i-1] = '\0';
	n = atoi(input);
	if(n < 0) {
	  printf("find: negative line number %d\n", n);
	  n = 10;
	}
      } else {
	printf("find: illegal option %s\n", input);
	n = 10;
      }
      cycle = 1;
    }
    linenum = readlines(lineptr, MAXLINE);
    writelines(lineptr,n,linenum);
    return 0;
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

//writelines: write output line
void writelines(char *lineptr[], int n, int linenum)
{
  linenum -= n;
  while(n-- > 0)
    printf("%s\n", lineptr[linenum++]);
}
