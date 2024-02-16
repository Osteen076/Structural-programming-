#include <stdio.h>
#include <math.h>

int isArmstrong(int n) {
	int originalNum = n;
	int numDigits = 0;
	int sum = 0;
	
	while (originalNum != 0) {
		originalNum /= 10;
		numDigits++;
	}
	
	originalNum = n;
	
	while (originalNum != 0) {
		int digit = originalNum % 10;
		sum += pow(digit, numDigits);
		originalNum /= 10;
	}
	
	if (sum == n) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	if (isArmstrong(num)) {
		printf("%d is an Armstrong number.\n", num);
	} else {
		printf("%d is NOT Armstrong.\n", num);
	}
	
	return 0;
}	

