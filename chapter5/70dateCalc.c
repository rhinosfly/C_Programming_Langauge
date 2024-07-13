#include <stdio.h>
#include "getint.h"

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
char *month_name(int n);
/*

 */
int main()
{
  int year = 2020;
  int month = 5;
  int day = 16;
  int yearday = 65;	// 3/5 leap
  month_day(year, yearday, &month, &day);
  printf("date = %s %dth\n", month_name(month), day);
  printf("day_of_year = %d\n", day_of_year(year,month,day));
  return 0;
}

static char daytab[2][13] = {
  {0,31,28,31,30,31,30,31,31,30,31,30,31},
  {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/* day_of_year: set day of year from month and day */
int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year%4==0 && year%100!=0 || year%400==0;
  if(month < 1 || month > 12) {
    printf("error: invalid month");
    return -1;
  }
  if(day < 1 || day > daytab[leap][month]) {
    printf("error: invalid day");
    return -1;
  }
  for(i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  int i, leap;

  leap = year%4==0 && year%100!=0 || year%400==0;
  if(yearday < 1 || (yearday > 365 && !leap) || yearday > 366) {
    printf("error: invalid day");
    return;
  }    
  for(i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}

/* month_name: return name of n-th month */
char *month_name(int n)
{
  static char *name[] = {"illlegal month", "january", "febuary", "march", "april",
			 "may", "june", "july", "august",
			 "september", "october", "november", "december"};
  return (n < 1 || n > 12) ? name[0] : name[n];
}
