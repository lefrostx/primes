#define BOOST_TEST_MODULE Primes algorithm test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include <vector>
#include "Primes.h"

namespace {

    namespace bdata = boost::unit_test::data;
    constexpr long endPrimeRange = 1000;
    auto testRange = bdata::xrange(2L, endPrimeRange);

    bool isPrime(long number)
    {
        if (number == 2)
            return true;

        long count{};

        for (long i{1}; i <= number; ++i)
            if (number % i == 0)
                ++count;

	    return count == 2;
    }

    std::vector<long> primesTo(long endRange)
    {
        std::vector<long> primes;
        for (long i{2}; i <= endRange; ++i)
            if (isPrime(i))
                primes.push_back(i);
        return primes;
    }
}

BOOST_DATA_TEST_CASE(testPrimeErato, testRange, number)
{
	bool result{ primesTo(number) == Primes::primesEratoTo(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeEach0, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeEach0(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeEach1, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeEach1(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeEach2, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeEach2(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeEach3, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeEach3(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeEachP, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeEachP(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeHalf1, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeHalf1(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeHalf2, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeHalf2(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeHalf3, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeHalf3(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeHalfP, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeHalfP(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeSqrt1, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeSqrt1(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeSqrt2, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeSqrt2(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeSqrt3, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeSqrt3(number) };
	BOOST_TEST(result);
}

BOOST_DATA_TEST_CASE(testIsPrimeSqrtP, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeSqrtP(number) };
	BOOST_TEST(result);
}
