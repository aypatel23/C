#include<stdio.h>

/* this is character counting program */

int main(void)
/*
{
	long nc;
	nc =0;
	while(getchar() != EOF)
		nc++;
	printf("%ld\n", nc);
}
*/


/* Ex 1.8 program to count blanks, tabs, and newlines */

{
	int c, nb, nt, nl;
	nb = nt = nl = 0;
	while((c = getchar()) != EOF){
		if (c == ' ')	// nb ?
			nb++;
		if (c == '\t')
			nt++;
		if(c == '\n')
			nl++;
	}

	printf("%s %d\n", "blanks =",  nb);
	printf("%s %d\n", "tabs =", nt);
	printf("%s %d\n", "newlines =", nl);
}
