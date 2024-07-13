#include <stdio.h>

/*
  copy inp to outp; replace blanks with one blank
*/

int main()
{
  int x,y;

  while((x = getchar()) != EOF){
    if(x == ' '){
      y = getchar();
      while(y = ' '){
	y = getchar();
      }
      putchar(y);
    }
    putchar(x);
  }
}
