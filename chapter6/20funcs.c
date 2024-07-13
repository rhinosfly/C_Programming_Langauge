#include <stdio.h>

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

//makepoint: make point from x and y
struct point makepoint(int x, int y);

int main()
{
  struct point pt;
  struct point maxpt = { 320, 200 };
  pt = makepoint(5,10);

  struct point *pp;
  pp = &maxpt;

  printf("%d\n",pt.x);
  printf("%d, %d\n", (*pp).x, (*pp).y);
  printf("%d, %d\n", pp->x, pp->y);
}

struct point makepoint(int x, int y)
{
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}
