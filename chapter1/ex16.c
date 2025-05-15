/* Revise the main routine of the longest-line program so it will correctly print the length of arbitrary long input lines, and as much as possible of the text.*/

#include<stdio.h>
#define MAXLINE 1000

int getaline(char line[], int maxline); //getline is already predefined in c so we used getaline function name
void copy(char to[], char from[]);   //function declaration to connect the function to main

/* print the longest input line */
int main(void)
{
	int len; //current line length
	int max; // max length seen so far
	char line[MAXLINE]; // current line
	char longest[MAXLINE]; // longest line saved so far

	max = 0;
	while ((len = getaline(line, MAXLINE)) > 0) // in () we use line & macro MAXLINE to define array in the getaline funtion
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest); // %s is a string & longest is the integer
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
	return i;// this will returning the value of i to main()
}

// part 2 which defines funciton
void copy(char to[], char from[])
{
	int i = 0;
	//i = 0;

	//char from[] = {'f', 'i', 'v', 'e', '\0'}  // line
	//char to[MAXLINE]; // longest

	while ((to[i] = from[i]) != '\0') {
		//printf("%d\n", to[i]);
		++i;
	}
}
