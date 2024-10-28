#include "gcd.h"

// Euclidean algorithm for finding the greatest common denominator (GCD) of two variables
int gcd(int x, int y){
	while (y != 0) {
		int z = y;
		y = x % y;
		x = z;
	}
	return x;
}
