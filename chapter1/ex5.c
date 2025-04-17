#include<stdio.h>
/* Program to print the table in reverse order, from 300 to 0*/
int main(void)
{
	int fahr, celsius;
	int upper, lower, step;

	lower = 300;
	upper = 0;
	step = 20;
	fahr = lower;
	printf("Fahernheit Celsius\n");
	printf("-----------------\n");

	while (fahr >= upper) {  // while condition is True
		celsius =  5 * (fahr-32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr - step;
	}
}
