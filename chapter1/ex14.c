/* Write a program to print a histogram of the frequencies of different characters in its input. */

#include<stdio.h>
#define TOTAL_CHARS 128 /* ASCII character are 128 */

int main(void)
{
	int c, i, j;
	int chars[TOTAL_CHARS];

	for (i = 0; i < TOTAL_CHARS; i++)
		chars[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c >= 0 && c < TOTAL_CHARS) {
			chars[c] = chars[c] + 1;
			printf("c is %i, count is %i\n", c, chars[c]);
		}
	}

	/* while ((c = getchar()) != EOF) { */
	/*   printf("prints this line while true\n");*/
	/*   printf("prints this line out of the loop\n");*/
	/*   }*/
	for (c = 0; c < TOTAL_CHARS; c++) {
		printf("%2c", c);
		printf("%2i\n", chars[c]);
		//count = chars[c];

		for (j = 0; j < chars[c]; j++) {
			putchar('*');
			putchar('\n');
		}
	}
}
