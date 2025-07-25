/* Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2. */
// Main
// squeeze
//getaline

#include<stdio.h>
#include<string.h>

# define LEN 100
void squeeze(char s1[], char s2[]);
int getaline(char s[], int min);

int main(void)
{
	char s1[LEN];
	char s2[LEN];

	while((getaline(s1, LEN) && getaline(s2, LEN)) != 0) {
		squeeze(s1, s2);
		printf("Result string s1 is %s\n", s1);
		return 0;
	}
}

void squeeze(char s1[], char s2[])
{
	int i, j;
	int k = 0;

	for (i = 0; i < strlen(s1); i++) {
		for(j = 0; j < strlen(s2); j++){
			if(s1[i] == s2[j])
				break;
		}
		if(j == strlen(s2)) {
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';
}

/*	for (i = j = 0; s[i] != '\0', i++)
	if (s1[i] != s2[j])
	s[j] = s[i];
	j++;
	*/


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

