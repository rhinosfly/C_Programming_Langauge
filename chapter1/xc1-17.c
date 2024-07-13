#include <stdio.h>
#define MIN 8
#define MAX 100

int length(char line[]);
int save(char final[], char line[],  int count);

int main()
{
  int len;
  int count;
  char line[MAX];
  char final[MAX];

  count = 0;
  while((len = length(line)) > 0)
    if(len > MIN)
      count = save(final, line, count);
  printf("\n%s\n",final);
}

int length(char line[])
{
  int c, i;

  for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    line[i] = c;
  if(c == '\n'){
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

int save(char final[], char line[], int count)
{
  int i;

  i = 0;
  while((final[count] = line[i]) != '\0') {
    ++i;
    ++count;
  }
  return count;
}
