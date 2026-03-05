#include <stdio.h>

// Eddie Kovsky ekovsky@redhat.com 2025 GPL-2.0+

int main(void)
{
	// Variables hold values.
	// We've seen many basic types that hold a scalar object.
	int i = 42;
	char c = 'a';

	printf("The variable i contains the integer %d\n", i);
	printf("The variable c contains the character %c\n", c);

	// We can use the '&' operator to get the address of any object.
	printf("The address of variable i is %p. \n", &i);

	// A pointer is a variable type that holds the address of an object.
	int *p;
	p = &i; // variable p stores an address of sizeof(int)
	//p = i;  // error, assigning a concret type to p, which only stores an address

	// The pointer variable type allows us to use an address just like any regular variable.
	printf("Variable p is assigned to the address of variable i: %p.\n", p);

	// Pointers have the same type as the object they are assigned to
	// because an address must be large enough to hold the type.
	printf("The size of variable p is %ld bytes.\n", sizeof(p));

	// Assigning an object of size char to a pointer of size int is a compile time error.
	//p = &c;

	// The '*' operator is overloaded; it has a different meaning depending on the context.
	// In addition to declaring a variable of type pointer, '*' is also
	// used to dereference, or get the value at an address.
	printf("The object variable p points to is %d.\n", *p);

	// Surprise! Arrays are actually pointers.
	// See Section 5.3: "By definition, the value of a variable or
	// expression of type array is the address of element zero of the array."
	// This is often referred to as 'pointer arithmetic.'
	int a[3] = {34, 238, 7};
	int *pa;
	pa = &a[0]; // Equivalent to pa = a;
	//pa = a;

	for (int j = 0; j < 3; j++) {
		printf("The object at index %d is %d.\n", j, *(pa+j));  // pa + sizeof(int)
	}
}
