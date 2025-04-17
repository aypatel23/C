/* Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include<stdio.h>
#define MAX_WORD_LEN 20

int main(void)
{
	int c, len, i, j;
	int nlength[MAX_WORD_LEN];      // declare array nlength of size MAX_WORD_LEN to hold lengths of words seen from input

	// Array defination
	// int ndigit[10];
	// values ndigit = [13, 47, 9, 3, ...]
	// positions ndigit = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

	len = 0;

	for (i = 0; i < MAX_WORD_LEN; ++i)
		nlength[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (len <= MAX_WORD_LEN) {
				++nlength[len];
				len = 0;
			}
		} else {
			++len;  // len = len +1
		}
	}


	for (i = 0; i < MAX_WORD_LEN; ++i) {      // Changed ++i from i++ and it fixed //
		printf("%2d ", i);

		for (j = 0; j < nlength[i]; ++j)
			printf("|");
		printf("\n");
	}

}


