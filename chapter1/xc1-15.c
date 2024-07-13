#include <stdio.h>

#define MIN	0
#define MAX	300
#define STEP	20

float ftoc(float k);

/* temperature conversion with function */

int main()
{
  float i;

  for(i = MIN; i <= MAX; i = i + STEP)
    printf("%3.0f %6.1f\n", i, ftoc(i));
  return 0;
}

/* convert fhar to cel */

float ftoc(float fahr)
{
  float cel;

  cel = ((fahr - 32.0) * (5.0/9.0));
  return cel;
}
