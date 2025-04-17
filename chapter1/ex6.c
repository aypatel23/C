#include <stdio.h>
/* Exercise 1.6 - Verify that the expression getchar() != EOF is 0 or 1 */
int main(void)
{
	int c;

	while ((c = getchar()) != EOF) {// We may check the output by using prinf with if else switch such as if (ret == 0) printf ("Return is false\n")
		printf("%d", c != EOF);
		putchar(c);
	}
}

