/* call and print atof */
#include <stdio.h>
#include <ctype.h>
#define MAX 100

double atof(char s[]);
/* atof: convert string s to double, accepts scientific notation */

int main()
{
  char s[MAX];
  int c,i;

  for(i = 0; (c = getchar()) != '\n'; i++)
    s[i] = c;
  s[i] = '\0';

  printf("result = %f\n", atof(s));

  return 0;
}

double atof(char s[])
{
  double val, power, exp, sign1;
  int i, sign;
  for(i = 0; isspace(s[i]); i++) //skip white space
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if(s[i] == '.')
    i++;
  for(power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  val = sign * val / power;
  if(s[i] == 'e' || s[i] == 'E') { //if exponent
    i++;
    sign = (s[i] == '-') ? -1 : 1;
    sign1 = (s[i] == '-') ? 0.1 : 10;
    if(s[i] == '+' || s[i] == '-')
      i++;
    for(exp = 0.0; isdigit(s[i]); i++)
      exp = 10.0 * exp + (s[i] - '0');
    for(exp *= sign; exp != 0; exp -= sign)
      val *= sign1;
  }
  return val;
}
