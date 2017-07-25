#pragma once
#include <assert.h>
#include <string>
#include <iostream>
using namespace std;

template <typename T>
class Singleton
{
protected:
	static T* instance;

public:
	Singleton(void)
	{
		instance = static_cast<T*>(this);
		assert(instance);
	}


	virtual ~Singleton(void)
	{
		if ( instance )
		{
			delete instance;
		}
	}

	static T* getInstance(){ assert(instance); return instance; }
};

#define SINGLETON_INIT( TYPE )							\
template <>	 TYPE * Singleton< TYPE >::instance = new TYPE;	




//����д��һ��ȱ�㣬���ǿؼ������û���new �ķ�ʽ�������� 

class TestSingleton : public Singleton<TestSingleton>
{
public:
	TestSingleton( int x =  0 , int y = 0 ) :x(x), y(y)
	{
	}
	~TestSingleton()
	{
	}

public:
	void print()
	{
		cout << "(" << x << "," << y <<")" << endl;
	}

private:

	int x;
	int y; 
};

SINGLETON_INIT(TestSingleton);


//����ֱ���Ժ�ķ�ʽʵ�ֱȽϺ�
#define CREATE_SINGLETON( TYPE )\
static TYPE* getInstance() \
{\
	static TYPE* p = nullptr;\
	if (p == nullptr)\
	{\
		p = new TYPE;\
	}\
	return p;\
}