/* Write a function htoi(s), which converts a string of hexadecimal digits
(including an optional 0x or 0X) into its equivalent integer value. The allowable digits are 0
through 9, a through f, and A through F */

/* 
 * 1. main function - what does it call?
 * 2. get input from getaline- great, recycle that for free; make sure it works
 * 3. call htoi
 *	what is its signature?
 *	what is its implementation?
 */

/*
int main(void)
{
	while get input {
		get line from user
		pass it htoi
		htoi is going to convert string to hex digit
}

int getaline
{
	copy this or use the standard libary
}

int htoi(s)
{
 // what can I copy from the book?
 // for loop that walks the array of char
 // handle 0 - 9
 // handle a - f
 // handle A - F
}
*/


#include<ctype.h>
#include<stdio.h>
int htoi(char s[]);
int getaline(char s[], int lim);


int main(void)
{
	int lim = 100;
	char line[lim]; // current line
	int n;
	int len;

	while ((len = getaline(line, lim)) > 0) {
		n = htoi(line);

		if (n > 0) {
			printf("The converted integer value is: %d\n", n);
		} else {
			printf("Invalid input\n");
			return n;
		}
	}

	return 0;
}

// convert the hex string to hex number
// convert upper case hex to int
// convert lower case hex to int
// print the final integer value

// in () we use line & macro MAXLINE to define array in the getaline funtion
// TODO implement htoi call

// take a string of hexadecimal digits and convert to its integer
int htoi(char s[])
{
	int c;
	int n, i=0;
	n = 0;

	while ((c = tolower(s[i])) != '\n') {
		n *= 16;

		if (i == 0 && c == '0') {
			++i;
			if(s[i] == 'x' || s[i] == 'X') {
				++i;
				continue;
			}
		} else if(c >= '0' && c <= '9') {
			n = 10 * n + (c - '0');
		} else if(c >= 'a' && c <= 'f') {
			n = n + 10 + (c - 'a');
		} else if(c >= 'A' && c <= 'F') {
			n = n + 10 + (c - 'A');
		} else if(c > 'f') {
			return -1;
		}

		i++;
	}
	return n;
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
