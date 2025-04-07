#include<stdio.h>
int main(void)

/* Write a program to copy its input to its output, replacing each string of one or
more blanks by a single blank. */

{
	int c;
	c = 0;
	while((c = getchar()) != EOF){
		if(c == ' '){
		putchar(c);
		while((c = getchar()) == ' ' && c != EOF);
	}
}
}
