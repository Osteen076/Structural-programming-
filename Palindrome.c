#include <stdio.h>

int isPalindrome(int n) {
	int reversedNum = 0, originalNum = n;
	
	
	while (n>0) {
		reversedNum = reversedNum * 10 + n % 10;
		n /= 10;
		
	}
	
	if (reversedNum == originalNum) {
		return 1;
	} else {
		return 0;
	}
}

int main() { 
	int num;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	if (isPalindrome(num)) {
		printf("%d is a palindrome.\n", num);
	} else {
		printf("%d is not a palindrome.\n", num);
	}
	
	return 0;
}
