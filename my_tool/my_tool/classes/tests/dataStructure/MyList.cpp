#include "MyList.h"
#include <iostream>
#include <random>
using namespace std;


MyList::MyList() :m_pHead(nullptr), m_pTail(nullptr)
{

}


MyList::~MyList()
{
	for (Node* p; m_pHead != nullptr;)
	{
		p = m_pHead->next;
		//cout << "delete" << m_pHead->data << "\t";
		delete m_pHead;
		m_pHead = p;
	}
	//cout << endl;
}

void MyList::insertBySort(int nData)
{
	if (m_pHead == nullptr)
	{
		m_pTail = new Node(nData, nullptr);
		m_pHead = m_pTail;
	}
	else
	{

		if ( nData >= m_pHead->data )
		{
			m_pHead = new Node(nData, m_pHead);
		}
		else
		{
			
			Node* pPrev = nullptr;//要插入的位置前
			Node* pNext = m_pHead;//要插入的位置后
			//找到要插入的位置
			while (nData < pNext->data && pNext->next != nullptr)
			{
				pPrev = pNext;
				pNext = pNext->next;
			}

			if ( pPrev->data == pNext->data )
			{
				//插入到最后
				pNext->next = new Node(nData);
			}
			else
			{
				pPrev->next = new Node(nData, pNext);

				//Node* pNew = new Node(nData);
				//pPrev->next = pNew;
				//pNew->next = pNext;

			}

		}
	}
}

void MyList::insert(int nData)
{
	if (m_pHead == nullptr)
	{
		m_pTail = new Node(nData, nullptr);
		m_pHead = m_pTail;
	}
	else
	{
		Node* node = new Node(nData);
		m_pTail->next = node;
		m_pTail = node;
	}
}

void MyList::print()
{
	for (Node* p = m_pHead; p != nullptr; p = p->next )
	{
		cout << p->data;
		if ( p->next )
		{
			cout << "->";
		}
	}
	cout << endl;
}

void MyList::reverse()
{
	if (m_pHead == nullptr || m_pHead->next == nullptr)
		return;
	Node* pHead = m_pHead;
	Node* pNext = pHead->next;
	Node* pNextNext = pNext->next;
	pHead->next = nullptr;
	for (; pNextNext ;)
	{
		pNext->next = pHead;
		pHead = pNext;
		pNext = pNextNext;
		pNextNext = pNextNext->next;
	}
	pNext->next = pHead;
	m_pHead = pNext;
}

Node* MyList::findMidElement()
{
	if (m_pHead == nullptr)
		return nullptr;

	Node* pSlow = m_pHead;
	Node* pFast = m_pHead;

	for (; pFast && pFast->next ; pSlow = pSlow->next,pFast = pFast->next->next)
	{

	}
	return pSlow;

}

void MyList::sort()
{
	Node* p, *q, *pSmall;
	int temp;

	//从头开始遍历，
	for (p = m_pHead; p->next != nullptr; p = p->next )
	{
		pSmall = p;
		//找到所有元素中最小的节点
		for (q = p->next; q; q = q->next )
		{
			if (q->data < pSmall->data)
			{
				pSmall = q;
			}
		}
		//如果最小元素不是当前节点，交换内部的数据
		if ( pSmall != p )
		{
			temp = p->data;
			p->data = pSmall->data;
			pSmall->data = temp;
		}
		print();
	}
}



void TestMyList::run()
{
	MyList* p = new MyList;
	// create default engine as source of randomness
	std::default_random_engine dre;

	// use engine to generate integral numbers between 10 and 20 (both included)
	std::uniform_int_distribution<int> di(10, 20);

	vector<int> vec{ 2, 55, 33, 66, 3, 2, 4, 1 };
	//vector<int> vec{ 2,55,33};

	for (auto o : vec)
	{
		p->insert(o);
	}
	p->print();

	//p->reverse();
	//p->print();
	p->sort();
	p->print();

	Node* pMid = p->findMidElement();
	cout << pMid->data << endl;

	delete p;
	p = nullptr;
}
