#include <stdio.h>
#include <string.h>
#include "../func/mygetline.h"
#define MAXLINE 1000

int mygetline(char *line, int max);

/* find: print lines that match patern from arg 1 */

int main(int argc, char *argv[])
{
  char line[MAXLINE];
  int found = 0;

  if(argc != 2)
    printf("usage: find pattern\n");
  else
    while(mygetline(line, MAXLINE) > 0)
      if(strstr(line, argv[1]) != NULL) {
	printf("%s", line);
	found++;
      }
  return found;
}
