#include <stdio.h>
#include <stdbool.h>
#include "gcd.h"
#include "prime.h"

int main() {
	int x, y;
	//ask user to input two variables
	printf("Enter two positive variables: ");
	scanf("%d", &x);
	scanf("%d", &y);
	printf("You typed in %d and %d\n", x, y);

	//Calculate average
	float avg = (x + y) / 2.0;
	printf("The average is: %f\n", avg);

	//Check if numbers are prime
	if (is_prime(x) == true){
		printf("%d is a prime number.\n", x);
	} else{
		printf("%d is not a prime number.\n", x);
	}

	if (is_prime(y) == true){
		printf("%d is a prime number.\n", y);
	} else {
		printf("%d is not a prime number.\n", y);
	}

	//Check if numbers are relatively prime
	if (gcd(x,y) == 1) {
		printf("%d and %d are relatively prime", x, y);
	} else {
		printf("%d and %d are not relatively prime", x, y);
	}

	return 0;
}
