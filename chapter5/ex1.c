/*As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character back on the input. */

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
int getint(int *pn);

int main(void)
{
	int n, array[SIZE], getint_result;

	printf("Enter up to %d integers(e.g.,123 +45 -678).\n", SIZE);
	printf("Type a non-numeric character (like 'x') to stop.\n\n");

	for (n = 0; n < SIZE; ) {
		getint_result = getint(&array[n]);

		if (getint_result > 0) {
			printf("Stored integer [%d]: %d\n", n, array[n]);
			n++; // Only increment index if we successfully got a number
		} else if (getint_result == 0) {
			// Check if we hit the end of input or just bad data
			printf("Found non-numeric data. Stopping.\n");
			break;
		} else if (getint_result == EOF) {
			printf("End of File reached.\n");
			break;
		}
	}

	printf("\nProgram finished. Processed %d numbers.\n", n);
	return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{

	int c, sign, temp;

	while (isspace(c = getch()))   /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);                /* it is not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		temp = c;              /* Store the sign (+ or -) */
		c = getch();           /* Step 1: Assignment (Get the next char) */
		if (!isdigit(c)) {     /* Step 2: Pure Condition (Is it a digit?) */
			if (c != EOF) {
				ungetch(c);/* push back the non-digit */
			}
			ungetch(temp); /*push back the sign*/
			return 0;
		}
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	printf("value of *pn is %d\n", *pn);
	*pn *= sign;  // *pn = *pn * sign

	if (c != EOF)
		ungetch(c);

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
