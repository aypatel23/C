// In a two's complement number representation, our version of itoa does not
// handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why not.
// Modify it to print that value correctly, regardless of the machine on which it runs. 

/* itoa: convert n to characters in s */

#include<stdio.h>
#include<string.h>
#include <limits.h>
#include <stdlib.h>

#define MAXNUMBER 100

/* reverse: reverse string s in place */
void reverse(char s[])
{
	int c, i, j;
	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void itoa(int n, char s[])
{
	int i, sign;

	sign = n;
	printf("integer called variable sign is %d\n", sign);
	i = 0;
	do { /* generate digits in reverse order */
		s[i++] = abs(n % 10) + '0'; /* get next digit */
	} while ((n /= 10) != 0); /* delete it */
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

int main(void)
{
	int number;
	char str[MAXNUMBER];

	printf("Largest negative int is %d\n", INT_MIN);

	number = INT_MIN;
	//number = -420000000;

	itoa(number, str);
	printf("%s", str);

	return 0;
}
