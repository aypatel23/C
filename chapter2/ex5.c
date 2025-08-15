/* Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.) */

// main
// any(s1,s2)
// getaline to take input


#include<stdio.h>
#include<string.h>

# define LEN 100
int any(char s1[], char s2[]);
int getaline(char s[], int lim);

int main(void)
{
	char s1[LEN];
	char s2[LEN];
	int pos;  // position where we matched

	while(getaline(s1, LEN) && getaline(s2, LEN) != 0) {
		pos = any(s1, s2);
		printf("The first return in s1 is %c\n", pos);

		return 0;
	}
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s2[j] == s1[i] && s1[i] != '\n') {
				return s1[i];
			}
		}
	}

	return -1;
}
int getaline(char s[], int lim)
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

