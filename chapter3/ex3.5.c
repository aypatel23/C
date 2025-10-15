/* shellsort: sort v[0]...v[n-1] into increasing order */

#include<stdio.h>

void shellsort(int v[], int n)
{
	int gap, i, j, temp;
	for (gap = n/2; gap > 0; gap = gap / 2) {
		for (i = gap; i < n; i++) {
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j -= gap) {
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
			}
		}
	}
}

void printArray(int arr[]) {
	int i;

	int size = sizeof(arr) / sizeof(arr[0]);

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	//int i;
	// Declare and initialize an array of integers to be sorted.
	int data[] = {12, 34, 54, 2, 3, 7, 9, 10, 88};

	// Calculate the size of the array.
	int n = sizeof(data) / sizeof(data[0]);

	// Print the original unsorted array.
	printf("Unsorted array: \n");
	printArray(data);
	//for (i = 0; i < n; i++) {
	//	printf("%d ", data[i]);
	//}

	// Call the shellsort function to sort the array.
	shellsort(data, n);

	// Print the sorted array.
	printf("\nSorted array: \n");
	printArray(data);
	//for (i = 0; i < n; i++) {
	//	printf("%d ", data[i]);
	//}

	return 0;
}
