/* Write the function strindex(s,t) which returns the position of the rightmost occurrence of t in s, or -1 if there is none. */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getaline(char s[], int lim);
int strindex(char source[], char searchfor[]);
/* find all lines matching pattern */

int main(void)
{
	char line[MAXLINE];
	int found = 0; // they mean count
	char pattern[] = "ould"; /* pattern to search for */
	int ret;

	while (getaline(line, MAXLINE) > 0){
		ret = strindex(line, pattern);

		if (ret > 0) {
			printf("Found match at index %d\n", strindex(line, pattern));
			printf("%s", line); // TODO index will off by one
			found++;
		} else {
			printf("no match found\n");
		}
		return found;
	}
}


/* getline: get line into s, return length */
int getaline(char s[], int lim)
{
	int c, i;
	i = 0;
	while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/*
int getaline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;// this will returning the value of i to main()
}
*/

/* strindex: return index of t in s, -1 if none */
// s is input line, t is the pattern to look for
int strindex(char s[], char t[])
{
	int i, j, k;
	int pos  = -1;

	for (i = 0; s[i] != '\0'; i++) {
		// printf("index i is %d\n", i);
		// printf("char %c in string s at index j is %d\n", s[i], i); // w i l l
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) {  // nothing in inner loop runs without a math
			printf("index j is %d\n", j);
			printf("index k is %d\n", k);
			printf("char %c in string s at index j is %d\n", s[j], j);
			printf("char %c in string t at index k is %d\n", t[k], k);
		}
			//;
		if (k > 0 && t[k] == '\0') {
			pos = i;
		}// TODO
			//return i;
	}
	// return -1;
	return pos;
}

