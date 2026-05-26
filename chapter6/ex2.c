/*  Write a program that reads a C program and prints in alphabetical order each group of variable names that are identical in the first 6 characters, but different somewhere
thereafter. Don't count words within strings and comments. Make 6 a parameter that can be set from the command line.*/


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define BUFSIZE 100 /* buffer size for ungetch */
#define YES 1
#define NO 0

/*
 * Write a program that reads a C program and prints in alphabetical order
 * each group of variable names that are identical in the first 6 characters
 * but different somewhere thereafter. Don't count words within strings and
 * comments. Make 6 a parameter that can be set from the command line.
 */

static char buf[BUFSIZE]; /* buffer for ungetch */
static int bufp; /* next free position in buf */
struct tnode { /* the tree node */
	char *word; /* points to the text */
	int match; /* match found */
	struct tnode *left; /* left child */
	struct tnode *right; /* right child */
};

static struct tnode *addtreex(struct tnode *, char *, int num, int *);
static void treexprint(struct tnode *t);
static struct tnode *talloc(void);
static int compare(char *s, struct tnode *p, int num, int *found);
/* getword and its helpers */
static int getword(char *, int);
static int getch(void);
static void ungetch(int);

/* print in alphabetic order each group of variable names */
/* identical in the first num characters (default 6) */
int main(int argc, char *argv[])
{
	struct tnode *root;
	char word[MAXWORD];
	int found = NO;	/* match found? */
	int num;	/* number of the first identical characters */

	num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0]+1) : 6;
	root = NULL;
	while (getword(word, MAXWORD) != EOF) {
		if (isalpha(word[0]) && strlen(word) >= num)
			root = addtreex(root, word, num, &found);
		found = NO;
	}
	treexprint(root);

	return 0;
}

/* add a node with w, at or below p */
static struct tnode *addtreex(struct tnode *p, char *w, int num, int *found)
{
	int cond;

	if (p == NULL) { /* a new word has arrived */
		p = talloc(); /* make a new word */
		p->word = strdup(w);
		p->match = *found;
		p->left = p->right = NULL;
	} else if ((cond = compare(w, p, num, found)) < 0) {
		p->left = addtreex(p->left, w, num, found);
	} else if (cond > 0) {
		p->right = addtreex(p->right, w, num, found);
	}

	return p;
}

/* talloc: make a tnode */
static struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

/* in order print of tree p */
static void treexprint(struct tnode *p)
{
	if (p != NULL) {
		treexprint(p->left);
		if (p->match) {
			printf("%s\n", p->word);
		}
		treexprint(p->right);
	}
}

/* compare words and update p-> match */
static int compare(char *s, struct tnode *p, int num, int *found)
{
	int i;
	char *t = p->word;

	for (i = 0; *s == *t; i++, s++, t++)
		if (*s == '\0')
			return 0;
	if (i >= num) { /*identical in first num chars? */
		*found = YES;
		p->match = YES;
	}

	return *s - *t;
}

/* get next word or character from input */
static int getword(char *word, int lim)
{
	int	c, d;
	char	*w = word;

	for ( ; ; ) {
		while (isspace(c = getch()))
			;
		if (c == '#') {
			while ((c = getch()) != '\n')
				if (c == EOF)
					return EOF;
			continue;

		}
		if (c == '/') {
			if ((d = getch()) != '*')
				ungetch(d);
			else
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
					} else
						break;
			continue;
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
		} else
			break;
	}
	for (*w++ = c; --lim > 1; w++)
		if (!isalnum(*w = getch()) && *w != '_') {
			ungetch(*w);
			break;
		}
	*w = '\0';

	return word[0];
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
