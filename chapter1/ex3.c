#include <stdio.h>
/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version with header*/
int main(void)
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
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}
