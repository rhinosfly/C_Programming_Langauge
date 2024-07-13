#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../func/getch.h"
#define	MAXWORD 100
#define MAXLINES 100

struct tnode {
  char *word;
  int lines[MAXLINES];
  struct tnode *left;
  struct tnode *right;
};
int line = 1;
struct tnode *
addtree(struct tnode *, char *);
// 	addtree: add a node with w, at or below p
void
treeprint(struct tnode *);
//	treeprint: in order print of tree p
int
getword(char *, int);
//	getword: get next word from input

/*
  scan doc, create tree with words, counter for '\n', int[], with line numbers, print word: int[]
*/
int
main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while(getword(word, MAXWORD) != EOF)
      root = addtree(root, word);
  treeprint(root);
  return 0;
}

struct tnode *
talloc(void);
//	talloc: make a node
char *
mystrdup(char *);
//	strdup: make a duplicate of string
void addnum(int *);
//	addnum: add number to end of lines array

struct tnode *
addtree(struct tnode *p, char *w)
{
  int cond;

  if(p == NULL) {	// new word
    p = talloc();	// make a new node
    p->word = mystrdup(w);
    p->lines[0] = line;
    p->lines[1] = 0;	//marks end of array
    p->left = p->right = NULL;
  }
  else if((cond = strcmp(w, p->word)) == 0)
    addnum(p->lines);
  else if(cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

void addnum(int *lines)
{
  while(*lines++)
    ;
  *lines-- = 0;
  *lines = line;
}

void
treeprint(struct tnode *p)
{
  int i;
  
  if(p != NULL) {
    treeprint(p->left);
    printf("%s\t", p->word);
    for(i = 1; p->lines[i] != 0; i++)
      printf("%d, ",p->lines[i-1]);
    printf("%d\n",p->lines[i-1]);
    treeprint(p->right);
  }
}

#include <stdlib.h>

struct tnode *
talloc(void)
{
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *
mystrdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}

int
getword(char * word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()))
    if(c == '\n')
      line++;
  if(c != EOF)
    *w++ = c;
  if(!isalpha(c)) {
    *w = '\0';
    return c;
  }
  for(; --lim > 0; w++)
    if(!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }
  *w = '\0';
  return word[0];
}
