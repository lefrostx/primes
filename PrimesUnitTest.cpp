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
    if (number == 2)
        return true;

    for (long i{2L}; i < number; ++i)
		if (number % i == 0)
			return false;
	return true;
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

BOOST_DATA_TEST_CASE(testIsPrimeHalf0, testRange, number)
{
	bool result{ isPrime(number) == Primes::isPrimeHalf0(number) };
	BOOST_TEST(result);
}
