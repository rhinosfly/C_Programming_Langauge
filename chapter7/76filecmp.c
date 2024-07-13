#include <stdio.h>
#include <string.h>

#define MAXLINE 100

// main: compare two files; print the first line that differs
int main(int argc, char *argv[])
{
  FILE *file1;
  FILE *file2;
  char line1[MAXLINE];
  char line2[MAXLINE];
  char *c1;
  char *c2;
  
  if(argc == 2) {
    file1 = stdin;
    file2 = fopen(*++argv, "r");
  }
  else if(argc == 3) {
    file1 = fopen(*++argv, "r");
    file2 = fopen(*++argv, "r");
  }
  else {
    printf("error: too many or too few arguments\n");
    return (1);
  }

  do {
    c1 = fgets(line1, MAXLINE, file1);
    c2 = fgets(line2, MAXLINE, file2);
    if(c1 == NULL && c2 == NULL) {
      printf("files are the same\n");
      return 0;
    }
  } while(!strcmp(line1, line2));
  printf("files are different\n");
  printf("%s%s", line1, line2);
  return 0;
}
