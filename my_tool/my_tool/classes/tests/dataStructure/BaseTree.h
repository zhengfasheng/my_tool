#pragma once
/*
* ���������
*/
#include<iostream>
using namespace std;
namespace Base{
	//�����������
	class Tree{
	public:
		//��������г�ʼ��Ϊ����
		Tree(void) :m_root(NULL), m_size(0){}
		//�����������ͷ�ʣ��ڵ�
		~Tree(void){
			clear();
		}
		//��������
		void insert(int data){
			insert(new Node(data), m_root);
			m_size++;
		}
		//ɾ���ҵ��ĵ�һ��ƥ������
		bool remove(int data){
			Node*& f = find(data, m_root);
			if (f){
				//��f������������������
				insert(f->m_left, f->m_right);
				//��f��������������f��
				Node* node = f;
				f = f->m_right;
				//ɾ��f
				delete node;
				m_size--;
				return true;
			}
			return false;
		}
		//ɾ��ȫ��ƥ������
		void removeall(int data){
			while (remove(data));
		}
		//�����
		void clear(void){
			clear(m_root);
			m_size = 0;
		}
		//�����е�old�滻Ϊval
		void update(int old, int val){
			while (remove(old))
				insert(val);
		}
		//�Ƿ����data
		bool find(int data){
			return find(data, m_root) != NULL;
		}
		//�������
		void travel(void){
			cout << "{";
			travel(m_root);
			cout << "}" << endl;
		}
		//��ȡ���Ĵ�С
		size_t size(void){
			return m_size;
		}
		//��ȡ���ĸ߶�
		size_t height(void){
			return height(m_root);
		}
	private:
		//�ڵ���
		class Node{
		public:
			int m_data;//����
			Node* m_left;//����
			Node* m_right;//����
			//���캯����ʼ���ڵ�
			Node(int data = 0, Node* left = NULL, Node* right = NULL) :m_data(data), m_left(left), m_right(right){}
		};
		//�����в���ڵ�
		void insert(Node* node, Node*& tree){//nodeָҪ����Ľڵ�,treeָҪ�����Ŀ����
			if (!tree)
				tree = node;
			else if (node){
				if (node->m_data < tree->m_data)
					insert(node, tree->m_left);
				else
					insert(node, tree->m_right);
			}
		}
		//����ֵΪdata�Ľڵ�
		Node*& find(int data, Node*& tree){
			if (!tree)
				return tree;
			else if (data == tree->m_data)
				return tree;
			else if (data < tree->m_data)
				return find(data, tree->m_left);
			else
				return find(data, tree->m_right);
		}
		//�����
		void clear(Node*& tree){
			if (tree){
				clear(tree->m_left);
				clear(tree->m_right);
				delete tree;
				tree = NULL;
			}
		}
		//�������
		void travel(Node*& tree){
			if (tree){
				travel(tree->m_left);
				cout << "<" << tree->m_data << ">";
				travel(tree->m_right);
			}
		}
		//�����ĸ߶�(���)
		size_t height(Node*& tree){
			if (tree){
				size_t lh = height(tree->m_left);
				size_t rh = height(tree->m_right);
				return (lh > rh ? lh : rh) + 1;
			}
			return 0;
		}
		Node* m_root;//����
		size_t m_size;//����С
	};

}