#include <stdio.h>

int main()
{
  int x,y;

  while((x = getchar()) != EOF){
    y = 0;
    if(x == '\t'){
      y=1;
      printf("\\t");
    }
    if(x == '\b'){
      y=1;
      printf("\\b");
    }
    if(x == '\\'){
      y=1;
      printf("\\");
    }
    if(y == 0)
    putchar(x);
  }
}
