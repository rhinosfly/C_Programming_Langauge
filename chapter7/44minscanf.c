#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "../func/getch.h"

#define MAXWORD 100

void minscanf(char *fmt, ...);

int main()
{
  int d;
  float f;
  char s[MAXWORD];
  
  minscanf("%d %f %s", &d, &f, s);
  
  printf("%d %f %s\n", d, f, s);
  return 0;
}

// minscanf: minimal scanf
void minscanf(char *fmt, ...)
{
  int i;
  va_list ap;
  char *p, *sval;
  char c;
  int *ival;
  float *dval;
  char buf[MAXWORD];

  va_start(ap, fmt);
  for(p = fmt; *p; p++) {
    if(*p != '%') {
      if((c = getch()) == *p)
	continue;
      else {
	printf("error: input deosn't match format");
	continue;
      }
    }
    switch(*++p) {
    case 'd':
      ival = va_arg(ap, int*);
      for(i = 0; isdigit(buf[i] = getch()); i++)
	;
      ungetch(buf[i]);
      buf[i] = '\0';
      *ival = atoi(buf);
      break;
    case 'f':
      dval = va_arg(ap, float*);
      for(i = 0; isdigit(buf[i] = getch()) || buf[i] == '.'; i++)
	;
      ungetch(buf[i]);
      buf[i] = '\0';
      *dval = atof(buf);
      break;
    case 's':
      for(sval = va_arg(ap, char *); !isspace(*sval = getchar()); sval++)
	;
      ungetch(*sval);
      *sval = '\0';
      break;
    default:
      printf("error: unrecognied letter");
      break;
    }
  }
  va_end(ap);
}
