/* Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and measure
the difference in run-time.*/

// compare the input value of x in the array v

#include <stdio.h>

/*
 *   binsearch: find x in v[0] <= v[1] <= .. <= v[n-1]
 *   Make one test inside the loop, instead of two
 *   Two tests inside loop: 0.00s user 0.00s system 45% cpu 0.002 total
 *   One test inside each nested loop:0.00s user 0.00s system 56% cpu 0.002 total
 *
 */

static int binsearch(int x, int v[], int n); // function declaration of binseacrh function(signature)
					     // static function has internal linkage, meaning it can only be called from within the same file where it is defined
					     // int : the function will return int value
					     // (int x, int v[], int n) : function parameters list
					     // specifies 3 peices: 
					     // int x: int represets the value of x
					     //int v[]: which is an array
					     //int n : number of elements in the array : 0 .. upto n

int main(void)                               //main function, return type is int, no arguments so it's void
{
	//static int y; // y = 0
	int v[] = {1, 3, 6, 8, 13, 24, 42};  // declares an int array called v and it has specific set of value: v[0]=1, v[1]=3... v[6]=42
	int n = sizeof(v) / sizeof(v[0]);  // 28 / 4 = 7  calculates(size of array) number of elements in the array v which total size of array in bytes / single element of array v
	printf("Size of array with sizeof(v): %ld\n", sizeof(v));
	int x = 13; /* the number we're searching for */

	printf("Number %d is at position %d\n", x, binsearch(x, v, n));
}

// arg1 num we're searching for, arg2 array, etc
static int binsearch(int x, int v[], int n)
{
	static int low, high, mid;

	low = 0;                          //low starts at 0
	high = n - 1;                     //high starts at n-1, which is the last possible index
	mid = (low + high) / 2;           //formula to define mid

	while (low <= high) { // true or false (While loop continues as long as low is <= high)
		if (x < v[mid])  { // first check at position 3 (checking the x is it's less than the middle value)
			high = mid - 1; // If it is, now high becomes mid-1
		} else {
			low = mid + 1;  //Otherwise, if it's in higher range than mid, then low becomes mid+1
		}                      // The loop will continue till low becomes greater than high
		mid = (low + high) / 2;
	}

	if (x == v[mid])              // The loop will terminate when low > high and it i will check if middle is x, then print the value of x
		return mid;
	else
		return -1; // no match (Return -1 if it's doesn't match with the 13)
}
