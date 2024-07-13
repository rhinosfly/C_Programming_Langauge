#include <stdio.h>
#include "60hashfuncs.h"

/*
  test hash functions
*/
int main()
{
  struct nlist *np;
  
  np = install("one", "01");
  install("two", "02");

  printf("%s\n", lookup("one")->defn);
  printf("%s\n", np->defn);
}
