/* Modify the sort program to handle a -r flag, which indicates sorting in reverse(decreasing) order. Be sure that -r works with -n.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000 /*max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse); // Added reverse parameter
void my_qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *s1, char *s2);
int my_getline(char s[], int lim);
void my_swap(void *v[], int i, int j);

/* sort input lines */
//int main(void)
int main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	int reverse = 0; // 1 if reverse sort
	int rc = 0;

	/* Loop through arguments to handle -n and -r in any order */
	while (--argc > 0 && (*++argv)[0] == '-') {
		int c;

		while ((c = *++argv[0])) {
			switch (c) {
			case 'n':
				numeric = 1;
				//option |= numeric; // too cute!
				break;
			case 'r':
				reverse = 1;
				//option |= numeric;
				break;
			default:
				printf("sort: illegal option %c\n", c);
				return 1;
			}
		}
	}

	if ((nlines == readlines(lineptr, MAXLINES)) >= 0) {
		if (reverse & numeric) {
			my_qsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*, void*))(numcmp));
		} else {
			my_qsort((void **) lineptr, 0, nlines-1,
				(int (*)(void*, void*))(strcmp));
				//(int (*)(void*,void*))(numcmp));
		}

		/* from the book:
		 * my_qsort((void**) lineptr, 0, nlines-1,
		 * (int (*)(void*,void*))(numeric ? numcmp : strcmp));
		 */

		writelines(lineptr, nlines, reverse);
		// return 0;
	} else {
		printf("input too big to sort\n");
		//return 1;
		rc = -1;
	}

	return rc;
}

//int_sort(int *, int *);  // if int > int ....
//float_sort(int *, int *);  // if int > int ....

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right,
		int (*comp)(void *, void *))
{
	int i, last;

	void my_swap(void *v[], int, int);
	if (left >= right) /* do nothing if array contains */
		return; /* fewer than two elements */
	my_swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			my_swap(v, ++last, i);
	my_swap(v, left, last);
	my_qsort(v, left, last-1, comp);
	my_qsort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void my_swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = my_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p == malloc(len)) == NULL) // instead of alloc using malloc as alloc is from standard library
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strscpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
	int i;

	if (reverse) {
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lineptr[i]);
	} else {
		for (i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
	}
}

int my_getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
