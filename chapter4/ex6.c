/* Add commands for handling variables. (It's easy to provide twenty-six variables with single-letter names.) Add a variable for the most recently printed value.*/

#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <ctype.h>
#include <math.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
int getop(char []);
void push(double);
double pop(void);
int sp;

/* reverse Polish calculator */
int main(void)
{
	int type, i;
	int var = 0;
	double op1, op2, v;
	char s[MAXOP];
	double variable[26];

	for (i = 0; i < 26; i++) {
		variable[i] = 0;
	}

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
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
			else
				printf("error: zero divisor for modulus\n");
			break;
		case 'p'://command to print the top
			op2 = pop();
			printf("top element: %.8f)\n", op2);
			push(op2); //push it back onto the stack
			break;
		case 'd': // command to duplicate
			op2 = pop();
			push(op2);
			push(op2);
			break;
		case 's': // command to swap the top two elements
			op1 = pop(); // topmost
			op2 = pop(); // second topmost
			push(op1);
			push(op2);
			break;
		case 'c': //command to clear the stack
			sp = 0; // stack pointer
			printf("stack cleared\n");
			break;
		case 'i': // sine function: (sine(x) = opposite/hypotenuse) where x must be in radian where radians = degrees * (pi / 180)
			push(sin(pop()));
			break;
		case 'e':// Exponential Function which is e^x, where e = 2.7182
			push(exp(pop()));
			break;
		case 'w': // power: raise base to the n-th power, int power(int base, int n)
			op2 = pop();
			push(pow(pop(), op2));
			break;
		case '=':
			pop();
			if (var >= 'A' && var <= 'Z') {
				variable[var - 'A'] = pop();
				push(variable[var - 'A']);
			} else {
				printf("error: no variable name\n");
			}
			break;
		case '\n':
			v = pop();
			printf("\t%.8g\n", v);
			break;
		default:
			if (type >= 'A' && type <= 'Z') {
				push(variable[type - 'A']);
			} else if (type == 'v') {
				push(v);
			} else {
				printf("error: unknown command %s\n", s);
			}
			break;
		}
		var = type;
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

int getch(void);
void ungetch(int);
/* getop: get next character or numeric operand */
int getop(char s[])
{
	int i = 0;
	int next, c;

	/* skip white space */
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	/* Not a number, not '.', not '-'. Returns an operator (like '+', '*', '/')*/
	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	/* Handle - operator*/
	if (c == '-') {
		next = getch();
		if (!isdigit(next) && next != '.')
			return c;
		c = next;
	} else {
		c = getch();
	}

	while (isdigit(s[++i] = c))
		c = getch();

	if (c == '.') { /* collect fraction part */
		c = getch();
	}
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp; /* next free position in buf */
int getch(void) /* get a (possibly pushed-back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


