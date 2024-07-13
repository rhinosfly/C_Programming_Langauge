#include "65hashfuncs.h"

int main()
{
  
  install("one", "01");
  install("two", "02");

  printf("%s\n", lookup("one")->defn);
  undef("one");
  printf("%s\n", lookup("one")->defn);
}

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
  unsigned hashval;

  for(hashval = 0; *s != '\0'; s++)
    hashval = *s +31 * hashval;
  return hashval % HASHSIZE;
}


struct nlist *lookup(char *s)
{
  struct nlist *np;
  
  for(np = hashtab[hash(s)]; np != NULL; np = np->next)
    if(strcmp(s, np->name) == 0)
      return np;
  return NULL;
}

struct nlist *install(char *name, char *defn)
{
  struct nlist *np;
  unsigned hashval;

  if((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof (*np));
    if(np == NULL || (np->name = mystrdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else
    free((void *) np->defn);
  if((np->defn = mystrdup(defn)) == NULL)
    return NULL;
  return np;
}

char *mystrdup(char *s)
{
  char *p;

  p = (char *) malloc(strlen(s)+1);
  if(p != NULL)
    strcpy(p, s);
  return p;
}

void undef(char *s)
{
  struct nlist *np;
  
  if((np = lookup(s)) == NULL)
    printf("warning: '%s' does not exist\n", s);
  else if(np->next != NULL) {
    printf("senario 2\n");
    *np = *np->next;
  }
  else {
    printf("else\n");
    hashtab[hash(s)] = NULL;
  }
}
