#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <assert.h>
#include <list>
#include <sstream>

using namespace std;

#define INSTANCE( className )\
static className* getInstance( )\
{\
	static className* instance = nullptr;\
	if ( !instance )\
		{\
		instance = new className;\
	}\
	return instance;\
}

template<class T>
string toString(const T& data)
{
	stringstream os;
	os << data;
	return os.str();
}

#pragma region ��������֧��iterator�Ķ���

template< class T >
void printObject(T obj, string separator = "\t")
{
	typedef T type;
	for (type::iterator it = obj.begin(); it != obj.end(); it++)
	{
		cout << *it << separator;
	}
	cout << endl;
}

#pragma endregion
