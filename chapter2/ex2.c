/* Write a loop equivalent to the for loop above without using && or ||. */

/* The for loop in book:
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 s[i] = c; */


#include<stdio.h>

int main(void)
{
/*	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
		s[i] = c;
*/
	int i=0;
	int lim = 1000;
	int c;
	char s[lim];

	while (i < lim-1) {
		(c = getchar());

		if (c == EOF)
			break;
		else if (c == '\n')
			break;

		s[i] = c;
		i++;
	}

	s[i] = '\0';

	printf("The loop terminated successfully. The string is: %s\n", s);
	return 0;
}



