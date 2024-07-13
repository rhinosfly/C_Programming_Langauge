#include <stdio.h>
#define MAX 100

/* expand(s1,s2): expand shorthand sets to full character lists */

void get(char s[]);
void expand( char s1[], char s2[]);

int main()
{
  char s1[MAX];
  char s2[MAX];
  get(s1);
  expand(s1,s2);
  printf("\"%s\" -> \"%s\"\n",s1,s2);
  return 0;
}

  void get(char s[])
{
  int i,c;
  for(i = 0; (c = getchar()) != '\n'; i++)
    s[i] = c;
  s[i] = '\0';
}
  
void expand(char s1[], char s2[])
{
  int i = 0;
  int j = 0;
  int k,l,h;
  int sw = 0; 	   /* 0 = low; 1 = high */
  int low,high;
  
  while(s1[i] != '\0') {
    if(s1[i] == '-') {
      if(i == 0)
        low = '0';
      else {
	low = high;
	j--;
      }
      sw ^= 1;	/* switch between 1 and 0 */
      i++;
    } 
    switch(sw) {	 /* set high and low */
    case 0:
      low = s1[i];
      sw ^= 1;
      i += 2;
      break;
    case 1:
      high = s1[i];
      if(high == '\0')
	break;
      sw ^= 1;
      /* fill s2 from high to low */
      for(l = h= 0; (k = low + h + l) <= high; j++) {
        while((k > '9' && k < 'A') || (k > 'Z' && k < 'a')) {
	  l++;
	  k = low + h + l;
	}
        s2[j] = k;
	h++;
      }
      i++;
      break;
    }
  }

  if(s1[--i] == '-'){
    high = 'z';
    for(l = h = 0;(k = low + h + l) <= high; j++) {
      while((k > '9' && k < 'A') || (k > 'Z' && k < 'a')) {
        l++;
	k = low + h + l;
      }
      s2[j] = k;
      h++;
    }
  }
  s2[j] = '\0';
}
