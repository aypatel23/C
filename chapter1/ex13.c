#include <stdio.h>
/* count digits, white space, others */

/*
int main(void )
{
	int c, i, nwhite, nother;
	// values    ndigit = [13, 47, 9, 3, ...]
	// positions ndigit = [0,   1, 2, 3, 4, 5, 6, 7, 8, 9]
	int ndigit[10];

	nwhite = nother = 0;

	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF)
		if (c >= '0' && c <= '9') {
			++ndigit[c-'0']; 
			printf("Value of c-'0': %i\n", c-'0');
		}
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite; // nwhite = nwhite + 1
		else
			++nother; // nother = nother + 1
				  
	printf("digits =");

	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);

	printf(", white space = %d, other = %d\n",
			nwhite, nother);
}

*/

/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#define IN 1
#define OUT 0

# define MAX_WORD_LEN 20

int main(void)
{
	int c, len, i, j;
	int count[MAX_WORD_LEN] = {0};
	len = i = j  = 0;
	int state = OUT;

/* getting error if do array as this

	for (i = 0; i < 20; i++)
		nlength[i] = 0;
		*/


	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\t' || c == '\n') {
			if(state == IN && len >=1 && len <= 20) {
				count[len]++;
			}
			len = 0;
			state = OUT;
		}
		else if(state == OUT) {
			state = IN;
			len++;
		}else{
			len++;
		}
	}

printf("\n");
for(i = 1; i < 20; i++){
	printf("%2d | ", i);
	for(j = 0; j < count[i]; j++)
		printf("*");
	printf("\n");
}
}

