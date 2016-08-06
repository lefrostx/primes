#include "Primes.h"

bool Primes::isPrimeEach0(long number)
{
    if (number == 2)
        return true;

    for (long i{2L}; i < number; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeEach1(long number)
{
    if (number == 2L)
        return true;
    
    if (number % 2L == 0)
        return false;

    for (long i{3L}; i < number; i += 2)
		if (number % i == 0)
			return false;
	return true;
}
