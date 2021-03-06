#ifndef ALGO_PRIMES_H
#define ALGO_PRIMES_H

#include <vector>

namespace Primes {
    bool isPrimeEach0(long number);
    bool isPrimeEach1(long number);
    bool isPrimeEach2(long number);
    bool isPrimeEach3(long number);
    bool isPrimeEachP(long number);
    bool isPrimeHalf1(long number);
    bool isPrimeHalf2(long number);
    bool isPrimeHalf3(long number);
    bool isPrimeHalfP(long number);
    bool isPrimeSqrt1(long number);
    bool isPrimeSqrt2(long number);
    bool isPrimeSqrt3(long number);
    bool isPrimeSqrtP(long number);
    std::vector<long> primesEratoTo(long top);
}

#endif
