/* There is no error checking in day_of_year or month_day. Remedy this defect */

#include<stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
	int yearday, month, day;
	int test_year = 2021;

	// 1. Convert Date -> Day of Year
	yearday = day_of_year(test_year, 0, 1);
	if (yearday != -1)
		printf("%d\n", yearday);
	else
		printf("Error: Invalid date.\n");

	// 2. Convert Day of Year -> Date
	month_day(test_year, yearday, &month, &day);
	if (month != -1)
		printf("Year: %d, Yearday: %d, Month: %d, Day: %d\n", test_year, yearday, month, day);
	else
		printf("Error: Invalid day of the year.\n");

	return 0;
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0; // leap can only be 0 or 1

	if (year < 1 || month < 1 || month > 12) {
		return -1;
	}

	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

	if(year < 1 || yearday < 1 || yearday > (leap ? 366 : 365)) {
		*pmonth = -1;
		*pday = -1;
		return;
	}

	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	
	*pmonth = i;
	*pday = yearday;
}

