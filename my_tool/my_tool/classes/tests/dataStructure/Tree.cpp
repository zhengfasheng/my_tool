#include "Tree.h"


Tree::Tree() :m_pRoot(nullptr), m_nSize(0)
{
}


Tree::~Tree()
{
	clear();
}

void Tree::insert(Node* pNode, Node*& root)
{
	//���Ҫ����ڵ�Ϊnull��������
	if (pNode == nullptr)
		return;
	//�����һ����������Ҫ����Ľڵ���Ϊ���ڵ�
	if ( root == nullptr )
	{
		root = pNode;
	}
	else
	{
		//���Ҫ���������С�ڸ��ڵ�����
		//��Ҫ��������ݲ��뵽������
		//������뵽������
		if (pNode->data < root->data)
		{
			insert(pNode, root->left);
		}
		else
		{
			insert(pNode, root->rigth);
		}
	}
}

void Tree::insert(int data)
{
	insert(new Node(data), m_pRoot);
}

void Tree::traverse(Node*& root)
{
	if (root == nullptr)
		return;
	traverse(root->left);
	cout << "<" << root->data << ">";
	traverse(root->rigth);
}

void Tree::traverse()
{
	traverse(m_pRoot);
}



void Tree::clear(Node*& root)
{
	if (root == nullptr)
		return;
	clear(root->left);
	clear(root->rigth);
	delete root;
	root = nullptr;
}

void Tree::clear()
{
	clear(m_pRoot);
}

void TestTree::run()
{
	Tree* pRoot = new Tree;
	pRoot->insert(10);
	pRoot->insert(20);
	pRoot->insert(300);
	pRoot->insert(1);
	pRoot->traverse();

	delete pRoot;
	pRoot = nullptr;
}
