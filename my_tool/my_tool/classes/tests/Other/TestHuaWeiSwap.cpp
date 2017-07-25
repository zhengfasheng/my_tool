#include "TestHuaWeiSwap.h"

void TestHuaWeiSwap::run()
{
	int a[] = { 3, 4, 1, 2 };
	int len = sizeof(a) / sizeof(int);
	int temp;
	for (int i = 0; i < len;)
	{
		temp = a[a[i] - 1];
		a[a[i] - 1] = a[i];
		a[i] = temp;
		if (a[i] == i + 1)
		{
			i++;
		}
		cout << "µÚ" << i + 1 << "´Î";
		for (auto& o : a)
		{
			cout << o << ",";
		}
		cout << endl;
	}
	for (auto& o : a)
	{
		cout << o << ",";
	}
}

