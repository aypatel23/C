/* Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable.*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100 /* maximum depth of val stack */
int sp; /* next free stack position */
double val[MAXVAL]; /* value stack */
/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

/* getop: get next character or numeric operand */
int getch(void);
int getop(char s[])
{
	int i = 0;
	int c;
	static int last_c = 0; /* This replaces the need for ungetch */

	/* 1. Get next character: check internal memory first, then call getch */
	if (last_c != 0) {
		c = last_c;
		last_c = 0;
	} else {
		c = getch();
	}

	/* 2. Skip white space */
	while ((s[0] = c) == ' ' || c == '\t') {
		c = getch();
	}

	s[1] = '\0';

	/* 3. Handle operators/commands */
	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}

	/* 4. Handle negative numbers vs minus operator */
	if (c == '-') {
		int next = getch();

		if (!isdigit(next) && next != '.') {
			last_c = next; /* Store for next getop call */
			return '-';
		}
		s[++i] = c = next; /* It's a negative number, keep going */
	}

	/* 5. Collect the numeric string */
	while (isdigit(s[++i] = c = getch()))
		;

	if (c == '.') { /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';

	/* 6. The "ungetch" replacement: Save the extra char in the static variable */
	if (c != EOF) {
		last_c = c;
	}

	return NUMBER;
}

/* getch remains exactly as you had it */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
