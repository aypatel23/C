/* Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types. */

#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
	printf("Range of signed char is [%d, %d].\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of unsigned char is [%u, %u].\n", 0, UCHAR_MAX);
	printf("Range of char is [%d, %d].\n", CHAR_MIN, CHAR_MAX);

	printf("Range of signed short int is [%hd, %hd].\n", SHRT_MIN, SHRT_MAX);
	printf("Range of unsigned short int is [%hu, %hu].\n", 0, USHRT_MAX);

	printf("Range of signed int is [%d, %d].\n", INT_MIN, INT_MAX);
	printf("Range of unsigned int is [%u, %u].\n", 0, UINT_MAX);

	printf("Range of signed long int is [%ld, %ld].\n", LONG_MIN, LONG_MAX);
	printf("Range of unsigned long int is [%lu, %lu].\n", 0, ULONG_MAX);
}
