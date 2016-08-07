#include "Primes.h"

bool Primes::isPrimeEach0(long number)
{
    if (number == 1)
        return true;

    int count{};

    for (long i{1}; i <= number; ++i) {
        if (number % i == 0)
            ++count;
    }

	return count == 2;
}

bool Primes::isPrimeEach1(long number)
{
    if (number == 2)
        return true;

    for (long i{2L}; i < number; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeEach2(long number)
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

bool Primes::isPrimeEach3(long number)
{
    if (number == 2 || number == 3)
        return true;
    
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    long k{4};

    for (long i{5}; i < number; i += k) {
		if (number % i == 0)
			return false;
        k = (k == 2) ? 4 : 2;
    }
	return true;
}

bool Primes::isPrimeHalf1(long number)
{
    if (number == 2)
        return true;

    long half = number / 2;

    for (long i{2L}; i <= half; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeHalf2(long number)
{
    if (number == 2L)
        return true;
    
    if (number % 2L == 0)
        return false;

    long half = number / 2;

    for (long i{3L}; i <= half; i += 2)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeSqrt1(long number)
{
    if (number == 2)
        return true;

    long sqrt = number / 2;

    for (long i{2L}; i <= sqrt; ++i)
		if (number % i == 0)
			return false;
	return true;
}
