#include <stdio.h>

/* print Fahrenheit-Celcius table
   for fahr = 0, 20, ..., 300*/
int main()
{
  printf("Celcius to Fahrenheit\n");
  
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;     /*lower limit of temperature table*/
  upper = 300;   /*upper limit*/
  step = 20;     /*step size*/

  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0/5.0)*celsius+32.0;
    printf("%3.0f\t%6.1f\n", celsius, fahr);
	   celsius = celsius + step;
  }
}
