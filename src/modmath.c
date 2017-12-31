#include "modmath.h"

#include <stdio.h>


int64_t mulmod(int64_t a, int64_t b, int64_t mod)
{
	int64_t c = a >= b ? a : b;
	int64_t d = a < b ? a : b;
	int64_t r = 0;
	
	while (d > 0) {
		if ((d % 2)) {
			r = (r + c) % mod;
		};

		d /= 2;
		c = (c + c) % mod;
	}
	
	return r;
}

int64_t expmod(int64_t a, int64_t b, int64_t mod)
{
	int64_t r = 1;
	
	while (b > 0) {
		if ((b % 2)) {
			r = mulmod(r, a, mod);
		};

		b /= 2;
		a = mulmod(a, a, mod);
	}
	
	return r;
}

int64_t gcd(int64_t a, int64_t b)
{
	int64_t rem;

	while ((rem = a % b)) {
		a = b;
		b = rem;
	}

	return b;
}

int is_pseudoprime(int64_t p, int64_t base)
{
	return (1 == expmod(base, p - 1, p));
}

int is_root_of_prime(int64_t a, int64_t mod)
{
	int is_root = 0;
	const int64_t dividend = mod - 1;

	if (!(dividend % 2)) {
		if (1 != expmod(a, (dividend/2), mod)) {
			int64_t i;

			is_root = 1;
			for (i = 3; i < dividend; i += 2) {
				if (is_pseudoprime(i, 2)) {
					if (!(dividend % i)) {
						if (1 == expmod(a, (dividend/i), mod)) {
							is_root = 0;
							break;
						}
					}
				}
			}
		}
	} else {
		fprintf(stderr, "root of prime check: bad p %lld\n", mod);
	}

	return is_root;
}

int is_lucas_prime(int64_t num)
{
	int is_prime = 0;
	int64_t i;

	for (i = 2; i < num; ++i) {
		if (is_pseudoprime(num, i)) {
			if (is_root_of_prime(i, num)) {
				is_prime = 1;
				break;
			}
		} else {
			break;
		}
	}

	return is_prime;
}
