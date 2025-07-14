/* Write a program to print all input lines that are longer than 80 characters.*/
#include<stdio.h>
#define LONGEST 10 // line which is longer than 80, changing it to 10 instead of 80 to simplyfy
#define MAXLINE 1000

int getaline(char line[], int maxline);

int main(void)
{
	int len; // current line length
	char line[MAXLINE]; // current line


	while ((len = getaline(line, MAXLINE)) > 0) {
		if (len > LONGEST)
			printf("%s", line);
	}
}

int getaline(char s[], int lim)//s is an array, and the second, lim, is an integer.
{
	int c, i;

	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i) { // If a word is "five" it will use 5 bytes as '\0' will use one byte so we are doing lim-1 to keep 1 byte for end character
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;// this will returning the value of i to main()
}


