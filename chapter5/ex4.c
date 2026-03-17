/* Write the function strend(s,t), which returns 1 if the string t occurs at the end of the string s, and zero otherwise.*/

#include<stdio.h>

static int strend(char *s, char *t)
{
	char *s_start = s;
	char *t_start = t;

	while (*s != '\0')
		s++;

	while (*t != '\0')
		t++;

	while (t >= t_start) {
		if (s < s_start || *s != *t) { // This handles the case where the t is actually longer than the whole string s
			return 0; // Mismatch found
		}
		t--;
		s--;
	}
	return 1; // match found
}


int main(void)
{
	char *s1 = "sending";
	char *s2 = "mail";
	char *s3 = "ending";

	printf("Does '%s' end with '%s'? Result: %d\n", s1, s2, strend(s1, s2));
	printf("Does '%s' end with '%s'? Result: %d\n", s1, s3, strend(s1, s3));
	return 0;
}

// already know length of biggest string is 7
// for (i = 7; i != 0; i--)
//	if s1[i] != s2[2]                 // sending == ending
//		error("not a match")



/*
 * static int strend(char *s, char *t)
 * {
 *	char *bs = s; // save beginning of strings
 *	char *bt = t;
 *
 *	for ( ; *s; s++) { // increment to the end of each string //
 *		;
 *	}
 *	for ( ; *t; t++) { // end of string t //
 *	;
 *	}
 *	for ( ; *s == *t; s--, t--) { // now we loop back from the end of each string //
 *	if (t == bt || s == bs) {
 *		break; // at the beginning of a string //
 *		}
 *	}// we break as soon as *s != *t, so we know the strings matched up to this point //
 *	if (*s == *t && t == bt && *s != '\0')
 *	return 1;
 *	else
 *	return 0;
 * }
*/

