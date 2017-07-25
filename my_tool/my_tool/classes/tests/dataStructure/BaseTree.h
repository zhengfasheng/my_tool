#pragma once
/*
* 有序二叉树
*/
#include<iostream>
using namespace std;
namespace Base{
	//有序二叉树类
	class Tree{
	public:
		//构造过程中初始化为空树
		Tree(void) :m_root(NULL), m_size(0){}
		//析构过程中释放剩余节点
		~Tree(void){
			clear();
		}
		//插入数据
		void insert(int data){
			insert(new Node(data), m_root);
			m_size++;
		}
		//删除找到的第一个匹配数据
		bool remove(int data){
			Node*& f = find(data, m_root);
			if (f){
				//将f的左子树插入右子树
				insert(f->m_left, f->m_right);
				//将f的右子树提升到f处
				Node* node = f;
				f = f->m_right;
				//删除f
				delete node;
				m_size--;
				return true;
			}
			return false;
		}
		//删除全部匹配数据
		void removeall(int data){
			while (remove(data));
		}
		//清空树
		void clear(void){
			clear(m_root);
			m_size = 0;
		}
		//将所有的old替换为val
		void update(int old, int val){
			while (remove(old))
				insert(val);
		}
		//是否存在data
		bool find(int data){
			return find(data, m_root) != NULL;
		}
		//中序遍历
		void travel(void){
			cout << "{";
			travel(m_root);
			cout << "}" << endl;
		}
		//获取树的大小
		size_t size(void){
			return m_size;
		}
		//获取树的高度
		size_t height(void){
			return height(m_root);
		}
	private:
		//节点类
		class Node{
		public:
			int m_data;//数据
			Node* m_left;//左树
			Node* m_right;//右树
			//构造函数初始化节点
			Node(int data = 0, Node* left = NULL, Node* right = NULL) :m_data(data), m_left(left), m_right(right){}
		};
		//向树中插入节点
		void insert(Node* node, Node*& tree){//node指要插入的节点,tree指要插入的目标树
			if (!tree)
				tree = node;
			else if (node){
				if (node->m_data < tree->m_data)
					insert(node, tree->m_left);
				else
					insert(node, tree->m_right);
			}
		}
		//查找值为data的节点
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
		//清空树
		void clear(Node*& tree){
			if (tree){
				clear(tree->m_left);
				clear(tree->m_right);
				delete tree;
				tree = NULL;
			}
		}
		//中序遍历
		void travel(Node*& tree){
			if (tree){
				travel(tree->m_left);
				cout << "<" << tree->m_data << ">";
				travel(tree->m_right);
			}
		}
		//求树的高度(深度)
		size_t height(Node*& tree){
			if (tree){
				size_t lh = height(tree->m_left);
				size_t rh = height(tree->m_right);
				return (lh > rh ? lh : rh) + 1;
			}
			return 0;
		}
		Node* m_root;//树根
		size_t m_size;//树大小
	};

}