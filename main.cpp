#include <iostream>
#include <iomanip>
#include <chrono>
#include "Primes.h"

using pFuncPrime = bool(long);

std::vector<long> generatePrimes(pFuncPrime isPrime, long top)
{
    std::vector<long> primes;
    primes.reserve(top + 1);

    for (long i{2}; i <= top; ++i)
        if (isPrime(i))
            primes.push_back(i);

    return primes;
}

long calcPrimeByTime(pFuncPrime isPrime, std::chrono::seconds duration)
{
    using namespace std::chrono;

    auto endPoint = steady_clock::now() + duration;
    
    long primeCount{};

    for (long number{2}; steady_clock::now() < endPoint; ++number)
        if (isPrime(number))
            ++primeCount;    

    return primeCount;
}

long calcPrimeByTop(pFuncPrime isPrime, long top)
{
    using namespace std::chrono;

    auto startPoint = steady_clock::now();
    generatePrimes(isPrime, top);
    auto endPoint = steady_clock::now();

    return duration_cast<microseconds>(endPoint - startPoint).count();
}

long calcEratoByTop(long top)
{
    using namespace std::chrono;

    auto startPoint = steady_clock::now();
    Primes::primesEratoTo(top);
    auto endPoint = steady_clock::now();

    return duration_cast<microseconds>(endPoint - startPoint).count();
}

int main()
{
    struct TestOutput {
        const char * funcName;
        bool (*pFunc)(long);
    } data[] =
    {
        {"isPrimeEach0", Primes::isPrimeEach0},
        {"isPrimeEach1", Primes::isPrimeEach1},
        {"isPrimeEach2", Primes::isPrimeEach2},
        {"isPrimeEach3", Primes::isPrimeEach3},
        {"isPrimeEachP", Primes::isPrimeEachP},
        {"isPrimeHalf1", Primes::isPrimeHalf1},
        {"isPrimeHalf2", Primes::isPrimeHalf2},
        {"isPrimeHalf3", Primes::isPrimeHalf3},
        {"isPrimeHalfP", Primes::isPrimeHalfP},
        {"isPrimeSqrt1", Primes::isPrimeSqrt1},
        {"isPrimeSqrt2", Primes::isPrimeSqrt2},
        {"isPrimeSqrt3", Primes::isPrimeSqrt3},
        {"isPrimeSqrtP", Primes::isPrimeSqrtP}
    };

    long testSeconds{1};
    std::cout << "This program tests prime number algorithms.\n"
              << "\nPart1. Testing functions by fixed time.\n"
              << "Input time (in seconds): ";
    std::cin >> testSeconds;
    std::cout << "\nTask: find prime numbers for " << testSeconds << " seconds.\n"
        << "Prime count results:\n" 
        << "__________________________________________________\n"
        << std::setw(25) << "|     Function name     |"
        << std::setw(25) << "     Count (primes)     |\n"
        << "|_______________________|________________________|\n";

    for (const auto & x : data) {
        auto count = calcPrimeByTime(x.pFunc, std::chrono::seconds{testSeconds});
        std::cout << '|' << std::setw(23) << x.funcName 
                  << '|' << std::setw(24) << count << "|\n";
    }

    std::cout << "|_______________________|________________________|\n";

    long topPrime{10000};
    std::cout << std::fixed;
    std::cout << "\nPart2. Testing functions by range [2, top]\n"
              << "\nInput top number: ";
    std::cin >> topPrime;

    std::cout << "\nTask: find prime numbers in range [2, " << topPrime << "]\n"
              << "Time results:\n" 
              << "__________________________________________________\n"
              << std::setw(25) << "|     Function name     |"
              << std::setw(25) << "   Time (microseconds)  |\n"
              << "|_______________________|________________________|\n";

    for (const auto & x : data) {
        auto time = calcPrimeByTop(x.pFunc, topPrime);
        std::cout << '|' << std::setw(23) << x.funcName 
                  << '|' << std::setw(24) << time << "|\n";
    }

    auto time = calcEratoByTop(topPrime);
    std::cout << '|' << std::setw(23) << "Eratosthenes" 
              << '|' << std::setw(24) << time << "|\n"
              << "|_______________________|________________________|\n";
}
