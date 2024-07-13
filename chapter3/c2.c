#include <stdio.h>
#define MAX 100

/* convert characters to escape sequences with switch; and opposite */

void getstr(char s[]);
void escape(char s[],char t[]);
void escape1(char s[],char u[]);

int main()
{
  char s[MAX];
  char t[MAX];
  char u[MAX];
  
  getstr(s);
  escape(s,t);
  printf("\"%s\"\n",t);
  
  getstr(s);
  escape1(s,u);
  printf("\"%s\"\n",u);
  
  return 0;

}

/* write one line of input to string */
void getstr(char s[])
{
  int i, c;
  
  for(i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  s[i] = '\0';
}

/* convert characters to escape chacters > other string */
void escape(char s[],char t[])
{
  int i,j;

  for(i = j = 0; s[i] != '\0'; i++)
    switch (s[i]) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      break;
    default:
      t[j++] = s[i];
      break;
    }
}

/* convert  escape character into characers > other string */
void escape1(char s[], char u[])
{
  int i,j;
  for(i = j = 0; s[i] != '\0'; i++) {
    if(s[i] == '\\') {
      switch (s[i+1]) {
      case 'n':
	u[j++] = '\n';
	break;
      case 't':
	u[j++] = '\t';
	break;
      case '\\':
	u[j++] = '\\';
	break;
      default:
	u[j++] = s[i--];
	break;
      }
      i++;
    }
    else
      u[j++] = s[i];
  }
  u[i] = '\0';
}
