#include <stdio.h>
#include <string.h>

#define MAXLINES 100
#define MAXLEN 100	//max length of any input line

char *lineptr[MAXLINES];

int readlines(char *memory, char *lineptr[], int maxlines);
/* read input lines */
void writelines(char *lineptr[], int nlines);
// write output lines
void qsort(char *lineptr[], int left, int right);
// quicksort

/*
  ecersize 5-7: no alloc; array from main
*/

int main()
{
  int nlines;	// number of input lines read
  char memory[MAXLINES * MAXLEN];

  if((nlines = readlines(memory, lineptr, MAXLINES)) >= 0) {
    qsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

int mygetline(char *, int);
char *alloc(int);

int readlines(char *memory, char *lineptr[], int maxlines)
{
  int len, nlines;
  char line[MAXLEN];

  nlines = 0;
  while((len = mygetline(line, MAXLEN)) > 0)
    if(nlines >= maxlines)
      return -1;
    else {
      line[len-1] = '\0';	//delete newline
      strcpy(memory, line);
      lineptr[nlines++] = memory;
      memory += len;
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
