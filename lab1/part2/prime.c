#include "prime.h"

// calculation for determining if a number is prime

int is_prime(int num) {
	if (num <= 1) return 0; //0 and 1 are not prime number
	if (num == 2) return 1; //2 is a prime number
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0; //not prime if divisible by any number besides 1 and itself
		}
	}
	return 1; //otherwise number is prime
}
