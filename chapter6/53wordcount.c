#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../func/getch.h"
#define	MAXWORD 100
#define MAXWORDS 100

struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
};
struct tnode *addtree(struct tnode *, char *);
// 	addtree: add a node with w, at or below p
void treesort(struct tnode *);
void treeprint(struct tnode *);
//	treeprint: in order print of tree p
int getword(char *, int);
//	getword: get next word from input

/*
  count word frequency in input
*/
int main()
{
  struct tnode *root;
  char word[MAXWORD];

  root = NULL;
  while(getword(word, MAXWORD) != EOF)
    if(isalpha(word[0]))
      root = addtree(root, word);
  treesort(root);
  treeprint(root);
  return 0;
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
    p->count = 1;
    p->left = p->right = NULL;
  }
  else if((cond = strcmp(w, p->word)) == 0)
    p->count++;
  else if(cond < 0)
    p->left = addtree(p->left, w);
  else
    p->right = addtree(p->right, w);
  return p;
}

void  makearray(struct tnode *p, struct tnode **all, int *count);
void treesortR(struct tnode *p, struct tnode **all, int lenall);

void treesort(struct tnode *p)
{
  struct tnode *all[MAXWORDS];
  int lenall = 0;
  
  makearray(p, all, &lenall);
  treesortR(p,all,lenall);
}

void  makearray(struct tnode *p, struct tnode **all, int *count)
{
  if(p != NULL) {
    all[(*count)++] = p;
    makearray(p->left, all, count);
    makearray(p->right, all, count);
  }
}

void treesortR(struct tnode *p, struct tnode **all, int lenall)
{
  int i,morei,lessi;
  int cond;
  struct tnode *less[MAXWORDS];
  struct tnode *more[MAXWORDS];
  struct tnode *pivot = all[0];

  for(i = 1,morei = lessi = 0; i <= lenall-1; i++) {
    if(all[i]->count > pivot->count)
      more[morei++] = all[i];
    else if(all[i]->count < pivot->count)
      less[lessi++] = all[i];
    else {
      if((cond = strcmp(pivot->word, all[i]->word)) > 0)
	more[morei++] = all[i];
      else if( cond < 1)
	less[lessi++] = all[i];
      else
	printf("error: duplicate words\n");
    }
  }
    if(morei) {
      p->left = more[0];
      treesortR(p->left, more, morei);
    }
    else {
      p->left = NULL;
    }
    if(lessi) {
      p->right = less[0];
      treesortR(p->right, less, lessi);
    }
    else {
      p->right = NULL;
    }
}
  
void treeprint(struct tnode *p)
{
  if(p != NULL) {
    treeprint(p->left);
    printf("%4d %s\n", p->count, p->word);
    treeprint(p->right);
  }
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

int getword(char * word, int lim)
{
  int c, getch(void);
  void ungetch(int);
  char *w = word;

  while(isspace(c = getch()))
    ;
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
