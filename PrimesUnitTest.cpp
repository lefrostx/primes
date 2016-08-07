#define BOOST_TEST_MODULE Primes algorithm test
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

#include "Primes.h"

namespace bdata = boost::unit_test::data;
constexpr long endPrimeRange = 1000L;
auto testRange = bdata::xrange(1L, endPrimeRange, 1L);

bool isPrime(long number)
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
