#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "integerClass.h"

//////////////////////////////////////////////////////////////
//Tests for initiation
//////////////////////////////////////////////////////////////
TEST_CASE("Create an IntegerInfo object")
{
	IntegerInfo info;
}

TEST_CASE("Create an IntegerInfo oject from an integer")
{
	IntegerInfo info(12);
}

//////////////////////////////////////////////////////////////
//Tests for isOdd
//////////////////////////////////////////////////////////////
TEST_CASE("Check isOdd returns true for an odd number")
{
	IntegerInfo info(1);
	REQUIRE(info.isOdd() == true);
}

TEST_CASE("Check isOdd returns false for an even number")
{
	IntegerInfo info(2);
	REQUIRE(info.isOdd() == false);
}

TEST_CASE("Check isOdd returns false for 0")
{
	IntegerInfo info(0);
	REQUIRE(info.isOdd() == false);
}

TEST_CASE("Check isOdd returns proper value for negative even")
{
	IntegerInfo info(-2);
	REQUIRE(info.isOdd() == false);
}

TEST_CASE("Check isOdd returns proper value for negative odd")
{
	IntegerInfo info(-1);
	REQUIRE(info.isOdd() == true);
}

TEST_CASE("Check isOdd returns proper value for maximum integer value")
{
	IntegerInfo info(2147483647);
	REQUIRE(info.isOdd() == true);
}

TEST_CASE("Check isOdd returns proper value for minimum integer value")
{
	IntegerInfo info(-2147483648);
	REQUIRE(info.isOdd() == false);
}

//////////////////////////////////////////////////////////////
//Tests for isEven
//////////////////////////////////////////////////////////////
TEST_CASE("Check isEven returns false for an odd number")
{
	IntegerInfo info(1);
	REQUIRE(info.isEven() == false);
}

TEST_CASE("Check isEven returns true for an even number")
{
	IntegerInfo info(2);
	REQUIRE(info.isEven() == true);
}

TEST_CASE("Check isEven returns true for 0")
{
	IntegerInfo info(0);
	REQUIRE(info.isEven() == true);
}

TEST_CASE("Check isEven returns proper value for negative even")
{
	IntegerInfo info(-2);
	REQUIRE(info.isEven() == true);
}

TEST_CASE("Check isEven returns proper value for negative odd")
{
	IntegerInfo info(-1);
	REQUIRE(info.isEven() == false);
}

TEST_CASE("Check isEven returns proper value for maximum integer value")
{
	IntegerInfo info(2147483647);
	REQUIRE(info.isEven() == false);
}

TEST_CASE("Check isEven returns proper value for minimum integer value")
{
	IntegerInfo info(-2147483648);
	REQUIRE(info.isEven() == true);
}

//////////////////////////////////////////////////////////////
//Tests for isPrime
//////////////////////////////////////////////////////////////
TEST_CASE("Check isPrime returns true for 1")
{
	IntegerInfo info(1);
	REQUIRE(info.isPrime() == true);
}

TEST_CASE("Check isPrime returns true for 0")
{
	IntegerInfo info(0);
	REQUIRE(info.isPrime() == true);
}

TEST_CASE("Check isPrime returns false for non-prime number")
{
	IntegerInfo info(4);
	REQUIRE(info.isPrime() == false);
}

TEST_CASE("Check isPrime returns true for a prime number")
{
	IntegerInfo info(2);
	REQUIRE(info.isPrime() == true);
}

TEST_CASE("Check isPrime returns true for a prime negative number")
{
	IntegerInfo info(-3);
	REQUIRE(info.isPrime() == true);
}

TEST_CASE("Check isPrime returns false for a non-prime negative number")
{
	IntegerInfo info(-10);
	REQUIRE(info.isPrime() == false);
}

TEST_CASE("Check isPrime returns true for a larger prime number")
{
	IntegerInfo info(199);
	REQUIRE(info.isPrime() == true);
}

TEST_CASE("Check isPrime returns false for a larger non-prime number")
{
	IntegerInfo info(200);
	REQUIRE(info.isPrime() == false);
}

//////////////////////////////////////////////////////////////
//Tests for isComposite
//////////////////////////////////////////////////////////////
TEST_CASE("Check isComposite returns false for 1")
{
	IntegerInfo info(1);
	REQUIRE(info.isComposite() == false);
}

TEST_CASE("Check isComposite returns false for 0")
{
	IntegerInfo info(0);
	REQUIRE(info.isComposite() == false);
}

TEST_CASE("Check isComposite returns true for non-prime number")
{
	IntegerInfo info(4);
	REQUIRE(info.isComposite() == true);
}

TEST_CASE("Check isComposite returns false for a prime number")
{
	IntegerInfo info(2);
	REQUIRE(info.isComposite() == false);
}

TEST_CASE("Check isComposite returns false for a prime negative number")
{
	IntegerInfo info(-3);
	REQUIRE(info.isComposite() == false);
}

TEST_CASE("Check isComposite returns true for a non-prime negative number")
{
	IntegerInfo info(-10);
	REQUIRE(info.isComposite() == true);
}

TEST_CASE("Check isComposite returns false for a larger prime number")
{
	IntegerInfo info(199);
	REQUIRE(info.isComposite() == false);
}

TEST_CASE("Check isComposite returns true for a larger non-prime number")
{
	IntegerInfo info(200);
	REQUIRE(info.isComposite() == true);
}

//////////////////////////////////////////////////////////////
//Tests for ones
//////////////////////////////////////////////////////////////
TEST_CASE("Check ones returns 1 for 1")
{
	IntegerInfo info(1);
	REQUIRE(info.ones() == 1);
}

TEST_CASE("Check ones returns 0 for 0")
{
	IntegerInfo info(0);
	REQUIRE(info.ones() == 0);
}

TEST_CASE("Check ones returns 3 for 52")
{
	IntegerInfo info(52);
	REQUIRE(info.ones() == 3);
}

TEST_CASE("Check ones returns proper value for a negative number")
{
	IntegerInfo info(-3);
	REQUIRE(info.ones() == 3);
}

TEST_CASE("test ones returns 4 for -52")
{
	IntegerInfo info(-52);
	REQUIRE(info.ones() == 4);
}

TEST_CASE("test a number 3 0s in a row")
{
	IntegerInfo info(142);
	REQUIRE(info.ones() == 4);
}

//////////////////////////////////////////////////////////////
//Tests for getPrimes
//////////////////////////////////////////////////////////////
TEST_CASE("No errors calling getPrimes")
{
	IntegerInfo info(12);
	list<int> test = info.getPrimes();
}

TEST_CASE("Check getPrimes to make sure 1 and 0 do not return anything")
{
	IntegerInfo num0(0);
	IntegerInfo num1(1);
	list<int> test = num0.getPrimes();
	REQUIRE(test.size() == 0);
	test = num1.getPrimes();
	REQUIRE(test.size() == 0);

}

TEST_CASE("Check getPrimes to make sure 3 returns only 1")
{
	IntegerInfo info(3);
	list<int> test = info.getPrimes();
	REQUIRE(test.size() == 1);
	REQUIRE(test.front() == 1);
}

TEST_CASE("Check getPrimes to make sure 10 returns 1,2, and 5")
{
	IntegerInfo info(10);
	list<int> test = info.getPrimes();
	REQUIRE(test.size() == 3);
	REQUIRE(test.front() == 1);
	test.pop_front();
	REQUIRE(test.front() == 2);
	test.pop_front();
	REQUIRE(test.front() == 5);
}

TEST_CASE("Check getPrimes to make sure -1 returns nothing")
{
	IntegerInfo info(-1);
	list<int> test = info.getPrimes();
	REQUIRE(test.size() == 0);
}

TEST_CASE("Check getPrimes to make sure -3 returns only -1")
{
	IntegerInfo info(-3);
	list<int> test = info.getPrimes();
	REQUIRE(test.size() == 1);
	REQUIRE(test.front() == -1);
}

TEST_CASE("Check getPrimes to make sure -10 returns -1,-2, and -5")
{
	IntegerInfo info(-10);
	list<int> test = info.getPrimes();
	REQUIRE(test.size() == 3);
	REQUIRE(test.front() == -1);
	test.pop_front();
	REQUIRE(test.front() == -2);
	test.pop_front();
	REQUIRE(test.front() == -5);
}
