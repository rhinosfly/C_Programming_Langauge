#include "60hashfuncs.h"

int main()
{
  struct nlist *np;
  
  np = install("one", "01");
  install("two", "02");

  printf("%s\n", lookup("one")->defn);
  printf("%s\n", np->defn);
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
