/*
 * Write a function escape(s,t) that converts characters like newline and tab into
visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write a
function for the other direction as well, converting escape sequences into the real characters.
*/

// main
// escape(s,t)
// getaline to get input

#include<stdio.h>
#define MAXLINE 200
int escape(char s[], char t[]);

int escape(char s[], char t[])
{
	int i, j;
	i = j = 0;

	while (t[i] != '\0'){
		switch (t[i]) {
			case '\n':
				s[j] = '\\';
				++j;
				s[j] = 'n';
				break;
			case '\t':
				s[j] = '\\';
				++j;
				s[j] = 't';
				break;
			default:
				s[j] = t[i];
				break;
		}
		++i;
		++j;
	}
	s[j] = '\0';
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

int main(void)
{
    char s[MAXLINE], t[MAXLINE];

    getaline(t, MAXLINE);

    escape(s, t);

    printf("%s", s);

    return 0;
}


