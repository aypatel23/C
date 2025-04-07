#include<stdio.h>
int main(void)

/* Write a program to copy its input to its output, replacing each tab by \t, each
backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
unambiguous way. */
{

	int c;
	c = 0;
       while((c = getchar()) != EOF) {
	       if (c == '\\') {
		putchar('\\');
		putchar('\\');
	       }

		/*
	       if(c == ' '){
		       putchar(c);
		       while((c = getchar()) == '\t' && != EOF);
	       }
	       if(c == 'backspace'){
		       putchar(c);
		       while((c = getchar()) == '\b' && != EOF);
	       }
	       if(c == '\'){
		       putchar(c);
		       while((c = getchar()) == '\\' && != EOF);
	       }
	       */
       }
}
