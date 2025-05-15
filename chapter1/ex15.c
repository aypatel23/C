/*  Rewrite the temperature conversion program of Section 1.2 to use a function for conversion. */

#include<stdio.h>

// declaration or the function signature
void convert(void);

int main(void)
{ // begining of function namespace main

	convert();

	return 0;
} // end of function namespace main

// function definition
// function that prints a table of temperature conversions
void convert(void)
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	printf("Fahrenheit Celsius\n");
	printf("------------------\n");
	while (fahr <= upper) {
		celsius =  5 * (fahr-32) / 9;
		printf("%d %d\n", fahr, celsius);
		fahr = fahr + step;
	}
}

