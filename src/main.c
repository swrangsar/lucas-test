#include <stdio.h>
#include <math.h>

#include "modmath.h"


int main(int argc, const char *argv[])
{
	printf("odd lucas primes\n");

	int i;
	for (i = 3; i < 1000000; i += 2) {
		if (is_lucas_prime(i)) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
