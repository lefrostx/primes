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
	for (long i{1L}; i <= number; ++i)
		if (number % i == 0)
			return false;
	return true;
}

BOOST_DATA_TEST_CASE(testIsPrimeEach0, testRange)
{
	bool result{ isPrime(sample) == Primes::isPrimeEach0(sample) };
	BOOST_TEST(result);
}
