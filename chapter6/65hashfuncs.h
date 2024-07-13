#ifndef HASHFUNCS
#define HASHFUNCS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

unsigned hash(char *s);
//form hash value for string s
struct nlist *lookup(char *s);
// lookup: look for s in hashtab
char *mystrdup(char *);
// duplicate string
struct nlist *install(char *name, char *defn);
// install: put (name, defn) in hashtab
void undef(char *);

#endif
