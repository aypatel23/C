/* There is no error checking in day_of_year or month_day. Remedy this defect */

#include<stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
	int year = 2024; // A leap year
	int month = 3;   // March
	int day = 1;     // 1st

	int yearday, m, d;

	// 1. Convert Date -> Day of Year
	yearday = day_of_year(year, month, day);
	printf("Date: %d-%02d-%02d is day %d of the year.\n", year, month, day, yearday);

	// 2. Convert Day of Year -> Date
	// We pass the addresses of m and d so the function can modify them
	month_day(year, yearday, &m, &d);
	printf("Day %d of %d is Month: %d, Day: %d.\n", yearday, year, m, d);

	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

