#include <ctype.h>
#include "65hashfuncs.h"
#include "../func/getch.h"

#define MAXWORD 100

int getword(char *word, int lim);
/*
  emulate the c preprocessor with #define and #undef
*/

int main()
{
  enum { NONE,CMD, DEF, UNDEF, INSTALL};
  int cmd = NONE;
  char c;
  char word[MAXWORD];
  char name[MAXWORD];
  struct nlist *np;
  
  while((c = getword(word, MAXWORD)) != EOF) {
    if(cmd == CMD) {
      if(strcmp(word, "define") == 0)
	cmd = DEF;
      else if(strcmp(word, "undef") == 0)
	cmd = UNDEF;
      else {
	printf("warning: unknown command ignored\n");
	cmd = NONE;
      }
    }
    else if(cmd == DEF) {
      strcpy(name, word);
      cmd = INSTALL;
    }
    else if(cmd == UNDEF) {
      undef(word);
      cmd = NONE;
    }
    else if(cmd == INSTALL) {
      install(name, word);
      cmd = NONE;
    }
    else if(cmd == NONE && c == '#')
      cmd = CMD;
    else if(cmd == NONE) {
      if((np = lookup(word)))
	printf("%s ",np->defn);
      else
	printf("%s ",word);
    }
    else
      printf("error\n");
  }
  printf("\n");
}


int getword(char *word, int lim)
{
  int c,d, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()))
    ;
  if(c != EOF)
    *w++ = c;
  
  if(c == '/') {	// comment
    if((d = getch()) == '*') {
      w--;
      while(1) {
	if((c = getch()) == '*')
	  if((c = getch()) == '/') {
	    c = getch();
	    break;
	  }
	if(c == EOF)
	  break;
      }
    }
    else if(d == '/') {
      w--;
      while((c = getch()) != '\n' && c != EOF)
	;
      if(c == '\n')
	c = getch();
    }
    else
      ungetch(d);
  }
  if(c == '"') {
    while((*w++ = getch()) != '"')
      ;
    *w = '\0';
    return word[0];
  }
  
  if(!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for(; --lim > 0; w++)
    if(!isalnum(*w = getch()) && *w != '_') {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
