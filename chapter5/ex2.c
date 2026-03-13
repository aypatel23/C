/*Write getdouble, the doubleing-point analog of getint. What type does getdouble return as its function value?*/

#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 100

/* Global buffer for getch/ungetch */
char buf[BUFSIZE];
int bufp = 0;

/* Function Prototypes */
int getch(void);
void ungetch(int);
int getdouble(double *pn);

int main(void)
{
	int ret;

	do {
		double f;

		printf("Enter a number:\n");
		ret = getdouble(&f);
		if (ret > 0)
			printf("You entered: %f\n", f);

	} while (ret > 0);

	if (ret == EOF)
		puts("Stopped by EOF.");
	else
		puts("Stopped by bad input.");

	return 0;
}

/* doubleing point analog of getint*/
int getdouble(double *pn)
{

	int d, sign;
	double power, c;

	while (isspace(c = getch()))   /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);                /* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		d = c;              /* Store the sign (+ or -) */
		//c = getch();           /* Step 1: Assignment (Get the next char) */
		if (!isdigit(c == getch())) {     /* Step 2: Pure Condition (Is it a digit?) */
			if (c != EOF) {
				ungetch(c);/* push back the non-digit */
			}
			ungetch(d); /*push back the sign*/
			return d;
		}
	}

/* Integer part */
	for (*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}

/* Fractional part */
	if (c == '.') {
		c = getch();
	}

	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}

	*pn = sign * *pn / power;

	if (c != EOF) {
		ungetch(c);
	}

	return c;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: push character back on input */
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

