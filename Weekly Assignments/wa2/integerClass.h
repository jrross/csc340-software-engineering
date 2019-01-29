#include <list>

using namespace std;

class IntegerInfo
{
	int integer;

	public:
	IntegerInfo();
	IntegerInfo(int num);
	~IntegerInfo();

	bool isOdd();
	bool isEven();
	bool isPrime();
	bool isComposite();
	int ones();
	list<int> getPrimes();
};
