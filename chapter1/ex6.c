#include <stdio.h>
/* copy input to output; 2nd version*/
int main(void)
{
	int c;
        int ret;

	c = getchar();
	putchar(c);

	while ((c = ret = getchar()) != EOF);

if (ret == 0){
	printf("Return is false \n");
}
else if (ret == 1){
	printf("Return is true \n");
}
else {
	printf("Return is invalid \n");
}

}
