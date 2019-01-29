#include "integerClass.h"
#include <cmath>

IntegerInfo::IntegerInfo()
{

}

IntegerInfo::IntegerInfo(int num)
{
	integer = num;
}

IntegerInfo::~IntegerInfo()
{

}

bool IntegerInfo::isOdd()
{
	if(integer % 2 == 1 || integer % 2 == -1)
		return true;
	else
		return false;
}

bool IntegerInfo::isEven()
{
	return !isOdd();
}

bool IntegerInfo::isPrime()
{
	for(int i = 2; i <= abs(integer) / 2; i++)
	{
		if(integer % i == 0)
			return false;
	}
	return true;
}

bool IntegerInfo::isComposite()
{
	return !isPrime();
}

int IntegerInfo::ones()
{
	int count = 0;
	//if negative number, add an additional 1 for the sign bit
	if(integer < 0)
		count = 1;
	int temp = abs(integer);
	while(temp > 0)
	{
		if(temp%2 != 0)
			count = count + 1;
		temp = temp/2;
	}
	return count;
}

list<int> IntegerInfo::getPrimes()
{
	list<int> primes;
	bool neg = false;
	//indicate if the integer is negative
	if(integer < 0)
		neg = true;
	for(int i = 1; i < abs(integer); i++)
	{
		//if a factor
		if(integer % i == 0)
		{
			IntegerInfo num(i);
			if(num.isPrime())
			{
				//return negative of the prime number if integer is negative
				if(neg)
					primes.push_back(-i);
				else
					primes.push_back(i);
			}
		}
	}
	return primes;
}
