#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

#define MAXWORD 100

void minprintf(char *fmt, ...);

/*
  simplified printf; more features
*/
int main()
{
  int x;
  
  x = 1 + 1;
  minprintf("%3d, %4f, %9s\n",x,3.4,"hello");
  return 0;
}

// minprintf: minimal printf with variable argument list
void minprintf(char *fmt, ...)
{
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;
  int fw;
  int len;

  va_start(ap, fmt);
  for(p = fmt; *p; p++) {
    if(*p != '%') {
      putchar(*p);
      continue;
    }
    fw = 0;
    if(isdigit(*++p)) {
      fw = *p - '0';
      p++;
    }
    switch(*p) {
    case 'd':
      ival = va_arg(ap, int);
      printf("%*d", fw, ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%*f", fw, dval);
      break;
    case 's':
      sval = va_arg(ap, char *);
      for(len = 0; sval[len]; len++)
	;
      fw -= len;
      for(;fw > 0; fw--)
	putchar(' ');
      for(; *sval; sval++)
	putchar(*sval);
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);
}
