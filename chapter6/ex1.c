/*  Our version of getword does not properly handle underscores, string constants, comments, or preprocessor control lines. Write a better version.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define BUFSIZE 100 /* buffer size for ungetch */
#define NKEYS (sizeof(keytab) / sizeof(keytab[0])) /* # of words in keytab */

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp; /* next free position in buf */
/* struct key wastes 4 bytes to align memory boundary.
 * struct key already has optimized field layout.
 * 8 byte pointer, then 4 byte int.
 * We will always have 4 bytes leftover.
 */
static struct key {
	char *word;
	int count;
} keytab[] = {
	{"auto", 0},
	{"break", 0},
	{"auto", 0},
	{"case", 0},
	{"char", 0},
	{"continue", 0},
	{"default", 0},
	{"do", 0},
	{"double", 0},
	{"else", 0},
	{"enum", 0},
	{"extern", 0},
	{"float", 0},
	{"for", 0},
	{"goto", 0},
	{"if", 0},
	{"int", 0},
	{"long", 0},
	{"register", 0},
	{"return", 0},
	{"short", 0},
	{"signed", 0},
	{"sizeof", 0},
	{"static", 0},
	{"signed", 0},
	{"struct", 0},
	{"switch", 0},
	{"typedef", 0},
	{"union", 0},
	{"unsigned", 0},
	{"void", 0},
	{"volatile", 0},
	{"while", 0},
};

static int getword(char *, int);
static int binsearch(char *word, struct key tab[], int n);
static int getch(void);
static void ungetch(int);

/* count C keywords */
int main(void)
{
	int n;
	char word[MAXWORD];

	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0])) {
			if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
				keytab[n].count++;
			}
		}
	}

	for (n = 0; n < NKEYS; n++) {
		if (keytab[n].count > 0) {
			printf("%4d %s\n", keytab[n].count, keytab[n].word);
		}
	}

	return 0;
}

/* get next word or character from input */
static int getword(char *word, int lim)
{
	int	c, d;
	char	*w = word;

	for ( ; ; ) {
		while (isspace(c = getch())) {
			;
		}

		if (c == '#') {
			while ((c = getch()) != '\n') {
				if (c == EOF) {
					return EOF;
				}
				continue;
			}
		}

		if (c == '/') {
			if ((d = getch()) != '*') {
				ungetch(d);
			} else {
				for ( ; ; )
					if ((c = getch()) != '*') {
						if (c == EOF)
							return EOF;
						else
							continue;
					} else if ((c = getch()) != '/') {
						if (c == EOF)
							return EOF;
						else {
							ungetch(c);
							continue;
						}
					} else {
						break;
					}
				continue;
			}
		}

		if (c == '\'') {
			if ((c = getch()) == '\\')
				c = getch();
			if ((c = getch()) != '\'')
				return EOF;
			else
				continue;
		}

		if (c == '\"') {
			for ( ; ; )
				if ((c = getch()) == '\"')
					break;
				else if (c == '\\')
					c = getch();
				else if (c == EOF)
					return EOF;
			continue;
		}

		if (!isalpha(c)) {
			if (c == EOF)
				return c;
		} else {
			break;
		}
	}

	for (*w++ = c; --lim > 1; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	*w = '\0';

	return word[0];
}

/* find word in tab[0] ...tab[n-1] */
static int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low+high) / 2;
		if ((cond = strcmp(word, tab[mid].word)) < 0) {
			high = mid - 1;
		} else if (cond > 0) {
			low = mid + 1;
		} else {
			return mid;
		}
	}

	return -1; /* no match */
}

/* get a possibly pushed back character */
static int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
static void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
