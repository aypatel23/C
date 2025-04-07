#include <stdio.h>
/* copy input to output; 2nd version*/
int main(void)
{



	int c;
	int ret;


	while ((c = getchar()) != EOF)  // while has to 0 or 1

	//while ((c = getchar()) )

	c = ret = getchar();
        putchar(c);

	/* ret = c != EOF;  // != has to be 0 or 1
	printf("Value of return is %d\n", ret); */ 

	if (ret == 0){
		printf ("Return is false \n");
	}
	else if (ret == 1){
		printf ("Return is true \n");
	}
	else {
		printf ("Return is invalid \n");
	}
}

/*	for extra credit put the if/else check back in a while loop
*/


