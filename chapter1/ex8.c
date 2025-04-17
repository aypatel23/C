

/* Ex 1.8 program to count blanks, tabs, and newlines */

#include<stdio.h>
int main(void)
{
	int c, nb, nt, nl;

	nb = nt = nl = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')	// nb ?
			nb++;
		if (c == '\t')
			nt++;
		if (c == '\n')
			nl++;
	}

	printf("%s %d\n", "blanks =",  nb);
	printf("%s %d\n", "tabs =", nt);
	printf("%s %d\n", "newlines =", nl);
}
