#include <stdio.h>
#define MAXLINE 100
int mygetline(char *line, int maxlen);

int main()
{
  int day, month, year;
  char monthname[20];
  char line[MAXLINE];
  
  while(mygetline(line, MAXLINE) > 0) {
    if(sscanf(line, "hello%d %s %d", &day, monthname, &year) == 3)
      printf("valid: %s\n", line);
    else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
      printf("valid: %s\n", line);
    else
      printf("invalid: %s\n", line);
  }
  return 0;
}

int mygetline(char *line, int maxlen)
{
  int c, i;

  for(i = 0; (c = getchar()) != EOF && c != '\n' && i < maxlen; i++)
    line[i] = c;
  line[i] = '\0';
  return i;
}
