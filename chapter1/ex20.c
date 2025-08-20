/*Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter?*/

#include<stdio.h>

#define TABSIZE 8

int main(void) {
	int nb, pos, c;

	nb = 0;
	pos = 1;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {  // this is a	tab  this is a  tab
			nb = TABSIZE - ((pos -1) % TABSIZE);  // 8 - ((1-1) % 8) = 8 - (0 % 8) = 8

			while (nb > 0) {	// 8
				putchar('#');
				pos++;
				nb--;
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


 // this is a         tab  
 // for every TABSIZE spaces replace with a \t
