/*  Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab. When
either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

#include<stdio.h>

#define TABSIZE 4

int main(void)
{
	int nt, pos;
	int c;

	nt = 0;
	pos = 1;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			nt = TABSIZE + ((pos -1) % TABSIZE);

			while (nt > 0) {
				putchar('#');
				pos++;
				nt--;
			}
		} else if (c == '\n') {
			putchar(c);
			pos = 1;
		} else {
			putchar(c);
			pos++;
		}
	}
}


