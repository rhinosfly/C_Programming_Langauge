#include <unistd.h>
#include <stdio.h>

int getchar1(void);
int getchar2(void);

int main()
{
  char c;

  while((c = getchar2()) != EOF)
    write(1, &c, 1);
}


int getchar1(void)
{
  char c;
  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


int getchar2()
{
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n = 0;

  if(n == 0) {	// buffer is empty
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
