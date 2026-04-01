/*  Rewrite appropriate programs from earlier chapters and exercises with pointers instead of array indexing.
 *  Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
 *  reverse (Chapter 3), and strindex and getop (Chapter 4) */

#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int getaline(char *s, int lim);
int strindex(char *s, char *t);
void reverse(char *s);

char pattern[] = "ould"; /* pattern to search for */

/* find all lines matching pattern */
int main(void)
{
	char line[MAXLINE];
	int found = 0;

	while (getaline(line, MAXLINE) > 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			reverse(line);
			printf("Reverse output:%s\n", line);
			found++;
		}
	return found;
}
/* getline: get line into s, return length */
int getaline(char *s, int lim)
{
	int c;
	char *p = s; // store the starting position

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
		*s++ = c; // store char at current address then move s to next address
	}

	if (c == '\n') {
		*s++ = c;
	}

	*s = '\0';
	return (int)(s - p);
}

/* strindex: return index of t in s, -1 if none */
int strindex(char *s, char *t)
{
	char *i, *j, *k;
	char *s_start = s;

	for (i = s; *i != '\0'; i++) {
		for (j = i, k = t; *k != '\0' && *j == *k; j++, k++)
			;

		if (k > t && *k == '\0')
			return (int)(i - s_start);
	}
	return -1;
}

/* reverse: reverse string s in place */
void reverse(char *s)
{
	char c, *i, *j;

	for (i = s, j = s + (strlen(s)-1); i < j; i++, j--) {
		c = *i;
		*i = *j;
		*j = c;
	}
}
