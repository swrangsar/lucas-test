#ifndef MODMATH_H_
#define MODMATH_H_

#include <stdint.h>


int64_t expmod(int64_t a, int64_t b, int64_t mod);
int64_t mulmod(int64_t a, int64_t b, int64_t mod);
int64_t gcd(int64_t a, int64_t b);
int is_pseudoprime(int64_t p, int64_t base);
int is_root_of_prime(int64_t a, int64_t mod);
int is_lucas_prime(int64_t num);

#endif  // MODMATH_H_
