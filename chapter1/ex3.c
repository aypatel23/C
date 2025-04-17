/* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version with header*/

#include <stdio.h>
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
	while (fahr <= upper) {                           // This can be done with for loop
		celsius =  5 * (fahr-32) / 9;            //for (fahr=0; fahr<=300; fahr=fahr+20) {
		printf("%d\t%d\n", fahr, celsius);      //printf("%3d %6f\n", fahr, (5.0/9.0)*(fahr-32));
		fahr = fahr + step;
	}
	}
