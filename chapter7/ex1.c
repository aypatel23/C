/*Write a program that converts upper case to lower or lower case to upper,
depending on the name it is invoked with, as found in argv[0]*/

#include <stdio.h>
#include <ctype.h>


int main(void) /* lower: convert input to lower case*/
{
	int c;
		while ((c = getchar()) != EOF)
			putchar(tolower(c));
	return 0;
}
