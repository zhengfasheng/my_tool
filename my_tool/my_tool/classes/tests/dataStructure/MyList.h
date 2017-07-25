#pragma once
#include "Itest.h"
struct Node
{
	int data;
	Node* next;
	Node(int nData, Node* pNext = nullptr) : data(nData),next(pNext){}
};

class MyList
{
public:
	Node* m_pHead;
	Node* m_pTail;
public:
	MyList( );
	~MyList();

	void insertBySort(int nData);

	void insert(int nData);

	void print();

	void reverse();

	Node* findMidElement();

	void sort();

};

class TestMyList : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestMyList);
	virtual void run() override;
};

