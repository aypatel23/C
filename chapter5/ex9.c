/*  Rewrite the routines day_of_year and month_day with pointers instead of indexing.*/


#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void)
{
	int m, d, yd;
	int year = 2024;

	yd = day_of_year(year, 3, 1);
	printf("Day of year: %d\n", yd);

	month_day(year, yd, &m, &d);
	printf("Month: %d, Day: %d\n", m, d);

	return 0;
}

/* day_of_year: set day of year from month & day (pointer version) */
int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	// Set p to point to the start of the correct row in daytab
	p = daytab[leap];

	// Error checking
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > *(p + month))
		return -1;

	// Advance p and add days of preceding months to 'day'
	while (--month)
		day += *++p;  // day = day + *p++

	return day;
}

/* month_day: set month, day from day of year (pointer version) */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	// Point to the start of the correct row
	p = daytab[leap];

	// Error checking for yearday
	int days_in_year = leap ? 366 : 365;

	if (year < 1 || yearday < 1 || yearday > days_in_year) {
		*pmonth = -1;
		*pday = -1;
		return;
	}

	// Move p past the initial 0, then subtract month lengths from yearday
	while (yearday > *++p)
		yearday -= *p;

	*pmonth = (int)(p - daytab[leap]); // Pointer subtraction gives the index (month)
	*pday = yearday;
}
