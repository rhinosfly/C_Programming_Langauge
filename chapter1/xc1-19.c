#include <stdio.h>
#define MIN 1
#define MAX 1000

int length(char line[]);
void flip(char line[],char line1[], int len);
int save(char final[], char line[], int count);

int main()
{
  int len;
  int count;
  char line[MAX];
  char line1[MAX];
  char final[MAX];

  count = 0;
  while((len = length(line)) > 0)
    if(len > MIN)
      flip(line,line1,len);
      count = save(final, line1, count);
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

void flip(char line[], char line1[], int len)
{
  int i,c;

  c = 0;
  for(i = len - 2; i >= 0; --i){
    line1[c] = line[i];
    ++c;
  }
  line1[c] = '\n';
  ++c;
  line1[c] = '\0';
}

int save(char final[], char line1[], int count)
{
  int i;

  i = 0;
  while((final[count] = line1[i]) != '\0') {
    ++i;
    ++count;
  }
  printf("%d\n",count);
  return count;
}
