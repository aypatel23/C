/* Write a Program to remove the trailing blanks and tabs from each input line and to delete entirely blank lines */

#include<stdio.h>

#define MAXLINE 1000

int getaline(char line[], int lim);

int main(void)
{
	int len;
	char line[MAXLINE];

	while ((len = getaline(line, MAXLINE)) > 0)
		printf("%s", line);
}

// declare getaline

int getaline(char line[], int lim)
{
	int i, c;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;

	if (c == '\n') {
		if (line[i-1] == '\t' || line[i-1] == ' ') {
			// inputs "cat"
			// line = ['c', 'a', 't', '\t', '\n']
			line[i-1] = 'X'; /* Make it clear on screen what changed */
		}

		line[i] = c;
		++i;
	}

	line[i] = '\0';

	// blank lines
	if (line[1] == '\0')
		i = 0;
	return i;
}
