#include <stdio.h>

/* The C Answer Book*/
static void expand(char s1[], char s2[]);

int main(void)
{
	char *s[] = {"a-z", "1-6", "a-e", "a-r-L", "1-9-1", "5-5", "z-a", NULL };
	char result[100];
	int i = 0;

	while (s[i]) {
		expand(s[i], result);
		printf("Unexpanded: %s\n", s[i]);
		printf("Expanded  : %s\n", result);
		++i;
	}
	return 0;
}

/* expand shorthand notation from s1 into s2 */
static void expand(char s1[], char s2[])
{
	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0') /* get next char from s1 */
		/*
		 *  if next character is '-' and the character after that
		 *  is greater than the current character in c then we
		 *  expand the shorthand notation
		 */
		if (s1[i] == '-' && s1[i+1] >= c) { /* ASCII only */
			i++;
			while (c < s1[i]) /* expand shorthand */
				/* Clever: we just increment letters without
				 *				 * instantiating the alphabet
				 *								 */
				s2[j++] = c++;
		} else
			s2[j++] = c; /* copy the character */
	s2[j] = '\0';
}


