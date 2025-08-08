/* Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

#include<stdio.h>
#define limit 25
#define MAXLINE 50

int getaline(char s[], int lim);
void fold(char line[], int fold);


int main(void)
{
	char line[MAXLINE];
	int len;

	while((len = getaline(line, MAXLINE)) > 0){
		fold(line, limit);
	}
	return 0;
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

        return i;       // this will returning the value of i to main()
}

void fold(char line[], int fold)
{
	int i = 0;
	int len = strlen(line);

	while(len > limit) {
		int k = fold;


		while(k > 0 && (line[i = k - 1] == ' ' || line[i + k - 1] == '\t')) {
			k--;
		}


