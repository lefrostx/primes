#include "Primes.h"

bool Primes::isPrimeEach0(long number)
{
    for (long i{1L}; i <= number; ++i)
		if (number % i == 0)
			return false;
	return true;
}
