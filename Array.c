#include <stdio.h>
#define SIZE 9

void insertElement(int arr[], int index, int element) {
	for (int i = SIZE - 1; i>index; i--) {
		arr[i] = arr[i-1];
	}
	arr[index] = element;
}

void deleteElement(int arr[], int index) {
	for (int i = index; i<SIZE -1;i++) {
		arr[i] = arr[i + 1];
	}
}

int main(){

	int originalArray[SIZE] = {1,2,3,5,6,7,8,9,10};
	int omittedElement = 4;
	int newArray[SIZE];
	
	printf("Original Array: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d", originalArray[i]);
	}
	printf("\n");
	
	printf("Omitting element %d...\n", omittedElement);
	
	int insertionIndex = 3;
	insertElement(originalArray, insertionIndex, omittedElement);

	printf("Array with omitted element inserted: ");
	for (int i = 0; i<SIZE; i++) {
		printf("%d", originalArray[i]);
	}
	printf("\n");

	printf("Deleting Element %d...\n", omittedElement);
	deleteElement(originalArray, insertionIndex);

	printf("Array with element deleted: ");
	for (int i = 0; i < SIZE - 1; i++) {
		printf("%d", originalArray[i]);
	}
	printf("\n");

return 0;
}
