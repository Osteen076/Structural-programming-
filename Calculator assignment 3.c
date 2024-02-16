#include <stdio.h>

float addition(float num1, float num2) {
	return num1 + num2;
}

float subtraction(float num1, float num2) {
	return num1 - num2;
}

float multiplication(float num1, float num2) {
	return num1 * num2;
}	
float division(float num1, float num2) {
	if (num2 != 0) {
		return num1/num2;
	} else {
		printf("Cannot divide by zero!!\n");
		return 0;
	}
}

int main() {
	float num1, num2;
	
	printf("Enter the first number: ");
	scanf("%f", &num1);
	printf("Enter the second number: ");
	scanf("%f", &num2);
	
	float sum = addition(num1, num2);
	float difference = subtraction(num1, num2);
	float quotient = division(num1, num2);
	float product = multiplication(num1, num2);
	
	printf("The sum of %.2f and %.2f is: %.2f\n", num1, num2, sum);
	printf("The difference of %.2f and %.2f is: %.2f\n", num1, num2, difference);
	printf("The sum and difference are: %.2f and %.2f\n", sum, difference);
	printf("The product of %.2f and %.2f is: %.2f\n", num1, num2, product);
	printf("The quotient of %.2f and %.2f is %.2f\n", num1, num2, quotient);
	
	return 0;
}
