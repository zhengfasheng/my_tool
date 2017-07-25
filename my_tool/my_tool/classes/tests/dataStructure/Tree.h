#pragma once
#include "Itest.h"
#include <iostream>
using namespace std;

class Tree{

	//�ڵ���
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

	//����
	Node* m_pRoot;

	//���Ĵ�С
	size_t m_nSize;

public:
	//
	Tree();
	~Tree();

private:

	//�����в���ڵ�
	void insert(Node* pNode, Node*& root);

	//��������
	void traverse(Node*& root);

	//���
	void clear(Node*& root);

public:



	//�����в���Ԫ��
	void insert(int data);

	//��������
	void traverse();

	//���
	void clear();

};

class TestTree : public ITest
{
public:
	IMPLEMENT_GET_NAME(TestTree);
	virtual void run() override;
};

