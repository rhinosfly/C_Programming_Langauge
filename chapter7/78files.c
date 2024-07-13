#include <stdio.h>
#include <ctype.h>
#include "../func/getch.h"

#define WIDTH 10 //not including newline
#define HIGHT 10 //not including title
#define TITLELEN WIDTH-3

FILE *newfile(FILE *fp); //newfile: open new file with page#; return new file pointer
int myputc(int c, FILE *fp); //myputc: call putc in accordance with defaults

/*
  write input into multiple files with title and page count
*/
int main()
{
  char c,d;
  int state;
  FILE *fp;

  fp = newfile(fp);
  while((c = getch()) != EOF) {
    state = myputc(c, fp);
    if(state == EOF)
      fp = newfile(fp);
  }
  myputc(EOF, fp);
  fclose(fp);
  return 0;
}

int gettitle(char *title, int titlelen); //gettitle: returns length

FILE *newfile(FILE *fp)
{
  static int pagecount = 0;
  static int isopen = 0;
  char title[TITLELEN+1];
  int titlelen;
  char filename[20];

  if(isopen) {
    fclose(fp);
    isopen = 0;
  }
  pagecount++;
  sprintf(filename, "78files%d.txt", pagecount);
  titlelen = gettitle(title, TITLELEN);
  fp = fopen(filename, "w");
  isopen = 1;
  fprintf(fp, "%s%*d\n", title, (WIDTH - titlelen), pagecount);
  
  return fp;
}

int gettitle(char *title, int maxlen)
{
  int i, len;
  int valid = 1;
  
  printf("Enter title: (must be less than %d characters and alphanumeric)\n", maxlen);
  do {
    for(len = 0; len < maxlen && (title[len] = getch()) != EOF && title[len] != '\n'; len++)
      ;
    for(i = 0; i < len; i++) {
      valid = isalnum(title[i]);
      if(!valid) {
	printf("%s: invalid title\nEntertitle:\n");
	break;
      }
    }
  }while(!valid);
  title[len] = '\0';
  return len;
}

int myputc(int c, FILE *fp)
{
  static int width = 0;
  static int hight = 0;

  if(width < WIDTH-1) {
    putc(c, fp);
    width++;
  }
  else {
    if(hight < HIGHT) {
      putc(c, fp);
      putc('\n', fp);
      width = 0;
      hight++;
    }
    else {
      putc(c, fp);
      putc('\n', fp);
      width = 0;
      hight = 0;
      return EOF;
    }
  }
  return 0;
}
