/*  Extend atof to handle scientific notation of the form 123.45e-6 where a floating-point number may be followed by e or E and an optionally signed exponent. */

#include <ctype.h>
#include <stdio.h>
#include <math.h> // for pow()
#define MAXLINE 100

int getaline(char s[], int lim);

/* atof: convert string s to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exp_sign, exponent;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	//return sign * val / power;
	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E') {
		//i++;
		exp_sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-') {
			i++;
			printf("exp_sign is %d; index is %d\n", exp_sign, i);
		}
	}

	for (exponent = 0; isdigit(s[i]); i++) {
		exponent = 10 * exponent + (s[i] - '0'); // 123.456e-6 exponet == 6
		printf("exponent is %d\n", exponent);
	}

	if (exp_sign == 1) {
		while (exponent-- > 0) // exponent = 6
			val += 10;
	} else {
		while (exponent-- > 0) // neg exp e-6;  123.456e-6
			val /= 10;
	}
	return val;
}

int main(void)
{
	double sum;
	char line[MAXLINE];

	sum = 0;
	while (getaline(line, MAXLINE) > 0) {
		printf("\t%g\n", sum += atof(line));  // sum = sum + atof(line)
		//printf("Input is %.6s\n", line);
	}

	return 0;
}

/* getline: get line into s, return length */
int getaline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}
