#include "Primes.h"
#include <cmath>
#include <vector>

bool Primes::isPrimeEach0(long number)
{
    if (number == 2)
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

    for (long i{2}; i < number; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeEach2(long number)
{
    if (number == 2)
        return true;
    
    if (number % 2 == 0)
        return false;

    for (long i{3}; i < number; i += 2)
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

bool Primes::isPrimeEachP(long number)
{
    static std::vector<long> primes;

    if (number == 2) {
        primes.clear();
        primes.push_back(number);
        return true;
    }

    for (auto x : primes)
		if (number % x == 0)
			return false;
    
    primes.push_back(number);

	return true;
}

bool Primes::isPrimeHalf1(long number)
{
    if (number == 2)
        return true;

    long half = number / 2;

    for (long i{2}; i <= half; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeHalf2(long number)
{
    if (number == 2)
        return true;
    
    if (number % 2 == 0)
        return false;

    long half = number / 2;

    for (long i{3}; i <= half; i += 2)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeHalf3(long number)
{
    if (number == 2 || number == 3)
        return true;
    
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    long half = number / 2;
    long k{4};

    for (long i{5}; i <= half; i += k) {
		if (number % i == 0)
			return false;
        k = (k == 2) ? 4 : 2;
    }
	return true;
}

bool Primes::isPrimeHalfP(long number)
{
    static std::vector<long> primes;

    if (number == 2) {
        primes.clear();
        primes.push_back(number);
        return true;
    }

    long half = number / 2;

    for (auto x : primes) {
        if (x > half)
            break;
		if (number % x == 0)
			return false;
    }
    
    primes.push_back(number);

	return true;
}

bool Primes::isPrimeSqrt1(long number)
{
    if (number == 2)
        return true;

    long top = std::sqrt(number);

    for (long i{2}; i <= top; ++i)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeSqrt2(long number)
{
    if (number == 2)
        return true;
    
    if (number % 2 == 0)
        return false;

    long top = std::sqrt(number);

    for (long i{3}; i <= top; i += 2)
		if (number % i == 0)
			return false;
	return true;
}

bool Primes::isPrimeSqrt3(long number)
{
    if (number == 2 || number == 3)
        return true;
    
    if (number % 2 == 0 || number % 3 == 0)
        return false;

    long top = std::sqrt(number);
    long k{4};

    for (long i{5}; i <= top; i += k) {
		if (number % i == 0)
			return false;
        k = (k == 2) ? 4 : 2;
    }
	return true;
}

bool Primes::isPrimeSqrtP(long number)
{
    static std::vector<long> primes;

    if (number == 2) {
        primes.clear();
        primes.push_back(number);
        return true;
    }

    long top = std::sqrt(number);

    for (auto x : primes) {
        if (x > top)
            break;
		if (number % x == 0)
			return false;
    }
    
    primes.push_back(number);

	return true;
}

std::vector<long> Primes::primesEratoTo(long topRange)
{
    std::vector<long> primes;
    long n{topRange + 1};    
    std::vector<bool> a(n, true);
    a[0] = a[1] = false;
    
    for (int p{2}; p <= n; ++p) {
        if (a[p]) {
            for (int k{2}; k * p <= n; ++k) {
                a[k * p] = false;
            }
        }
    }

    for (int i{2}; i < a.size(); ++i) {
        if (a[i])
            primes.push_back(i);
    }

    return primes;
}
