#include <stdio.h>
#define MAX 100

int get(char line[]);
void cut(char line[], char line1[],int len);
int save(char final[], char line1[], int count);

int main()
{
  int len;
  int count;
  char line[MAX];
  char line1[MAX];
  char final[MAX];

  count = 0;
  while((len = get(line)) > 1) {
    cut(line,line1,len);
    count = save(final,line1,count);
  }
  printf("\n%s\n",final);
}

int get(char line[])
{
  int c, i;

  for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if(c == '\n'){
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void cut(char line[], char line1[], int len)
{
  int i, c;

  for(i = len - 2; line[i] == ' ' || line[i] == '\t'; --i)
    {}
  /* line[i] != (' '||'\n') */
  for(c = 0; c <=1+ i; ++c)
    line1[c] = line[c];
}

int save(char final[], char line1[], int count)
{
  int i;

  i = 0;
  while((final[count] = line1[i]) != '\0') {
    ++i;
    ++count;
  }
  return count;
}
