#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../func/getch.h"
#define	MAXWORD 100
#define DEFAULTN 6

struct tnode {
  char *word;
  struct tnode *left;
  struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *);
// 	addtree: add a node with w, at or below p
void treeprint(struct tnode *);
//	treeprint: in order print of tree p
int getvar(char *word, int lim);
//	getvar: get next variable from input
/*
  get n
  getword
  if variable, store it 
  different trees for every set of n
  print
*/
int main(int argc, char *argv[])
{
  int n;
  struct tnode *root = NULL;
  char var[MAXWORD];
  
  //	get n
  if(argc > 1)
    n = atof(*++argv);
  else
    (n = DEFAULTN);

  while(getvar(var, MAXWORD) != EOF)
    root = addtree(root, var);
  treeprint(root);
  return 0;
}

int getword(char *word, int lim);
/* get next word */

int getvar(char *var, int lim)
{
  static char *keywords[] = {"int", "char", "float", "double",
      "long", "short", "signed", "unsigned", "struct"};
  static int keylen = sizeof keywords / sizeof keywords[0];
  int isvar = 0;
  int i;
  
  while(getword(var, lim) != EOF) {
    if(isvar) {
      isvar = 0;
      return 1;
    }
    else
      for(i = 0; i < keylen; i++)
	if(!strcmp(var, keywords[i]))
	  isvar = 1;
  }
  return EOF;
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
    if((d = getch()) == '*')
      while(1) {
	if((c = getch()) == '*')
	  if((c = getch()) == '/')
	     break;
	if(c == EOF)
	  break;
      }
    else if(d == '/')
      while((c = getch()) != '\n' && c != EOF)
	;
    else
      ungetch(d);
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

struct tnode *talloc(void);
//	talloc: make a node
char *mystrdup(char *);
//	strdup: make a duplicate of string

struct tnode *addtree(struct tnode *p, char *w)
{
  int cond;

  if(p == NULL) {	// new word
    p = talloc();	// make a new node
    p->word = mystrdup(w);
    p->left = p->right = NULL;
  }
  else if((cond = strcmp(w, p->word)) < 0)
    p->left = addtree(p->left, w);
  else if(cond > 0)
    p->right = addtree(p->right, w);
  return p;
}

 #include <stdlib.h>

struct tnode *talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *mystrdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}

void
treeprint(struct tnode *p)
{
  if(p != NULL) {
    treeprint(p->left);
    printf("%s\n",p->word);
    treeprint(p->right);
  }
}
