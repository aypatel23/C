/* Define a macro swap(t,x,y) that interchanges two arguments of type t.(Block structure will help.)*/

#include<stdio.h>
#define swap(t, x, y) {t temp = x; x = y; y = temp; }

int main(void)
{
	int x = 5, y = 10;

	printf("Before: x=%d, y=%d\n", x, y);

	swap(int, x, y);
	printf("After: x=%d, y=%d\n", x, y);

	return 0;
}
