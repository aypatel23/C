/*Write a function reverse(s) that reverses the character strings. Use it to write a program that reverses its input a line at a time.*/

#include<stdio.h>
#include <string.h>
#define MAXLINE 1000

void reverse(char line[]);
int getaline(char line[], int maxline); //getline is already predefined in c so we used getaline function name

/* print the longest input line */
int main(void)
{
	int len; //current line length
	char line[MAXLINE]; // current line

	while ((len = getaline(line, MAXLINE)) > 0) { // in () we use line & macro MAXLINE to define array in the getaline funtion
		reverse(line);
		printf("%s", line); // %s is a string & longest is the integer
	}
}

// defination of getaline function by using different variable
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

	return i;	// this will returning the value of i to main()
}

void reverse(char line[])
{
	int c, i, j;

	for (i = 0, j = strlen(line)-1; i < j; i++, j--) {
		c = line[i];		// c is temporary storage
		line[i] = line[j];
		line[j] = c;
	}
}
