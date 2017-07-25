#pragma once
#include "Itest.h"
#include <iostream>
using namespace std;

class Tree{

	//节点类
	class Node{
	public:
		int data;
		Node* left;
		Node* rigth;
		Node(int nData = 0 , Node* pLeft = nullptr , Node* pRight = nullptr )
			:data(nData),left(pLeft),rigth(pRight){}
		~Node()
		{
			cout << "~" << data << " ";
		}
	};

	//树根
	Node* m_pRoot;

	//树的大小
	size_t m_nSize;

public:
	//
	Tree();
	~Tree();

private:

	//向树中插入节点
	void insert(Node* pNode, Node*& root);

	//遍历中序
	void traverse(Node*& root);

	//清空
	void clear(Node*& root);

public:



	//向树中插入元素
	void insert(int data);

	//遍历中序
	void traverse();

	//清除
	void clear();

};

class TestTree : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestTree);
	virtual void run() override;
};

