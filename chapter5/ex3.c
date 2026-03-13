/* Write a pointer version of the function strcat that we showed in Chapter 2:strcat(s,t) copies the string t to the end of s.*/

// Chapter2 version//
/* strcat: concatenate t to end of s; s must be big enough */

/*
 * void strcat(char s[], char t[])
 * {
 *	int i, j;
 *	i = j = 0;
 *	while (s[i] != '\0') // find end of s
 *	i++;
 *	while ((s[i++] = t[j++]) != '\0') // copy t
 *	;
 *	}
 */

#include<stdio.h>

void my_strcat(char *s, char *t)
{
	while (*s != '\0') {
		s++;
	}
	while ((*s++ = *t++) != '\0')
		;
}

int main(void)
{
	char s[100] = "Hello, ";
	char t[] = "World!";

	my_strcat(s, t);

	printf("Combined string: %s\n", s);

	return 0;
}
