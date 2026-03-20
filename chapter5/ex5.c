/* Write versions of the library functions strncpy, strncat, and strncmp, which operate on at most the first n characters of their argument strings. For example, strncpy(s,t,n) copies at most n characters of t to s. Full descriptions are in Appendix B.*/

#include<stdio.h>

/* This function copies at most $n$ characters from string t to s. */
char *my_strcpy(char *s, const char *t, int n)
{
	char *p = s;

	while (n > 0 && *t != '\0') {
		*p++ = *t++;
		n--;
	}
	printf("n is %d\n", n);
	while (n > 0) {
		*p++ = '\0';
		printf("Char from string s is %c\n", *p);
		n--;
	}
	return s;
}

/* This appends at most $n$ characters of string t to the end of string s.*/
char *my_strcat(char *s, const char *t, int n)
{
	char *p = s;

	while (*p != '\0')
		p++;
	while (n > 0 && *t != '\0') {
		*p++ = *t++;
		n--;
	}
	*p = '\0';
	return s;
}

/* This compares the first $n$ characters of two strings.*/
int my_strcmp(char *s, char *t, int n)
{
	for ( ; *s == *t; s++, t++) {
		if (*s == '\0' || --n <= 0) {
			return 0;
		}
	}

	return *s - *t;
}

int main(void)
{
	// 1. Test strncpy
	char s1[10] = "xxxxxxxx";
	char t1[] = "Hello";

	my_strcpy(s1, t1, 2);
	printf("Result: %s\n", s1);

	// 2. Test strcat
	char s[100] = "Hello, ";
	char t[] = "World!";

	my_strcat(s, t, 15);
	printf("Combined string: %s\n", s);

	// 3 test strncmp
	char s3[] = "Hel";
	char t3[] = "Hello";
	int match = my_strcmp(s3, t3, 2);

	if (match == 0) {
		printf("First %d characters of %s matches in %s at position %d\n", 2, t, s, match);
	} else {
		printf("Match not found\n");
	}
}
