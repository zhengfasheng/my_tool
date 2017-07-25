#include "TestTemplate.h"

void TestTemplate::run()
{
	cout << FibT(3) << endl;
	cout << FactT(4) << endl;
	cout << SumT(3) << endl;

	int i = 10;

	void* pi = (void*)i;

	int j = (int)pi;

	cout << j << endl;

}
