#include <stdio.h>

/* binary search; one test inside loop*/

int binsearch(int x, int v[], int n);

int main()
{
  int x = (getchar() - '0');
  int v[10] = {1,2,3,4,5,6,7,8,9,10};
  int n = 10;
  printf("position of x = %d\n",binsearch(x,v,n));
  return 0;
}

int binsearch(int x, int v[], int n)
{
  int low,high, mid;

  low = 0;
  high = n - 1;
  mid=(low+high)/2;
  while(mid != low) {    
    if(x < v[mid])
      high = mid;
    else
      low = mid;
    mid=(low+high)/2;
  }
  return(x == v[mid] ? mid : -1);
}
