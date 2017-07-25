#pragma  once
/*
迭代器模式（ Iterator Pattern） 目前已经是一个没落的模式， 基本上没人会单独写一个迭
代器， 除非是产品性质的开发， 其定义如下：
它提供一种方法访问一个容器对象中各个元素， 而又不需暴露该
对象的内部细节。

● Iterator抽象迭代器
抽象迭代器负责定义访问和遍历元素的接口， 而且基本上是有固定的3个方法： first()获
得第一个元素， next()访问下一个元素， isDone()是否已经访问到底部（ Java叫做hasNext()方
法） 。
● ConcreteIterator具体迭代器
具体迭代器角色要实现迭代器接口， 完成容器元素的遍历。
● Aggregate抽象容器
容器角色负责提供创建具体迭代器角色的接口， 必然提供一个类似createIterator()这样的
方法， 在Java中一般是iterator()方法。
● Concrete Aggregate具体容器
具体容器实现容器接口定义的方法， 创建出容纳迭代器的对象。

*/
#include <iostream>
#include <stdexcept>
//自己实现一个List
namespace Iterator
{

	

	//Concrete Aggregate
	template<class T>
	class List
	{
	public:
		typedef T vaule_type;
		typedef T& reference;
	private:
		class Node
		{
		public:
			Node* m_prev;//前指针
			Node* m_next;//后指针
			vaule_type m_data;//数据
			Node(const vaule_type& data , Node* prev = nullptr , Node* next = nullptr )
				:m_data(data),
				m_prev(prev),
				m_next(next){}
			friend std::ostream& operator << (std::ostream& os, const Node& node)
			{
				return os << "<" << node.m_data << ">";
			}
		};

	
		typedef Node* pointer;

		pointer m_pHead;//头指针
		pointer m_pTail;//尾指针

	public:

		List(void) :m_pHead(nullptr), m_pTail(nullptr){}
		~List()
		{
			clear();
		}
		//拷贝构造(深拷贝)
		List(const List& that)
			:m_pHead(nullptr), m_pTail(nullptr)
		{
			for (Node* p = that.m_pHead; p; p = p->m_next )
			{
				push_back(p);
			}
		}
		//拷贝赋值
		List& operator=(const List& that)
		{
			if (&that != this)
			{
				List lst(that);
				std::swap(m_pHead,that.m_pHead);
				std::swap(m_pTail, that.m_pTail);
			}
			return *this;
		}

		reference operator[](size_t index)
		{
			for (pointer p = m_pHead; p;p=p->m_next)
			{
				if (index-- == 0)
					return p->m_data;
			}
			throw std::out_of_range("下标越界");
		}

		//得到首元素
		vaule_type& front()
		{
			if (empty())
				throw std::underflow_error("empty list");
			return m_pHead->m_data;
		}

		const T& front() const
		{
			return const_cast(List*)(this)->front();
		}

		//首部压入
		void push_front(const vaule_type& data)
		{
			m_pHead = new Node(data, nullptr, m_pHead);
			if ( m_pHead->m_next )
			{
				m_pHead->m_next->m_prev = m_pHead;
			}
			else
			{
				m_pTail = m_pHead;
			}
		}

		//首部弹出
		void pop_front()
		{
			if (empty())
				throw std::underflow_error("empty list");
			auto pNode = m_pHead->m_next;
			delete m_pHead;
			m_pHead = pNode;
			if ( m_pHead )
			{
				m_pHead->m_prev = nullptr;
			}
			else
			{
				m_pTail = nullptr;
			}
		}

		//得到尾元素
		vaule_type& back()
		{
			if (empty())
				throw std::underflow_error("empty list");
			return m_pTail->m_data;
		}

		const vaule_type& back() const
		{
			return const_cast<List*>(this)->back();
		}

		//向尾部压入数据
		void push_back(const vaule_type& data)
		{
			m_pTail = new Node(data, m_pTail);
			if (m_pTail->m_prev)
			{
				m_pTail->m_prev->m_next = m_pTail;
			}
			else
			{
				m_pHead = m_pTail;
			}
		}

		//删除尾部数据
		void pop_back()
		{
			if (empty())
				throw std::underflow_error("empty list");
			auto pNode = m_pTail;
			delete m_pTail;
			m_pTail = pNode;
			if (m_pTail)
			{
				m_pTail->m_next = nullptr;
			}
			else
			{
				m_pHead = nullptr;
			}
		}

		//删除所有匹配元素
		void remove(const vaule_type& data)
		{
			pointer p, pNext;
			for (p = m_pHead;p;p = pNext)
			{
				pNext = p->m_next;
				if (equal(p->m_data, data))
				{
					if (p->m_prev)//如果还有前节点
					{
						p->m_prev->m_next = p->m_next;
					}
					else//如果没有前节点
					{
						m_pHead = p->m_next;
					}
					if ( p->m_next )//如果还有后节点,把后面的连上来
					{
						p->m_next->m_prev = p->m_prev;
					}
					else//如果没有后节点
					{
						m_pTail = p->m_prev;
					}
					delete p;
				}
			}
		}

		void clear()
		{
			pointer pNode;
			while (m_pHead)
			{
				pNode = m_pHead->m_next;
				delete m_pHead;
				m_pHead = pNode;
			}
		}

		bool equal(const vaule_type& left, const vaule_type& right) const
		{
			return left == right;
		}

		//是否为空
		bool empty()
		{
			return m_pHead == nullptr && m_pTail == nullptr;
		}

		size_t size() const
		{
			size_t counter = 0;
			for (pointer p = m_pHead; p; p = p->m_next)
			{
				counter++;
			}
			return counter;
		}

		//输入流
		friend std::ostream& operator<< (std::ostream& os, const List& list)
		{
			for (pointer p = list.m_pHead; p;p = p->m_next)
			{
				os << *p;
			}
			return os;
		}

		//Iterator
		class iterator
		{
		public:
			iterator(pointer pHead = nullptr, pointer pTail = nullptr, pointer pNode = nullptr)
				:m_pHead(pHead), m_pTail(pTail), m_pNode(pNode){}
			
			bool operator==(const iterator& it) const
			{
				return it.m_pNode == m_pNode;
			}
			bool operator!=(const iterator& it) const
			{
				return !(*this == it);
			}
			vaule_type& operator[](size_t index ) const
			{
				for (pointer p = m_pHead; p; p = p->m_next )
				{
					if (--index == 0)
						return p;
				}
				return nullptr;
			}

			iterator& operator++(void)
			{
				if (m_pNode)
				{
					m_pNode = m_pNode->m_next;
				}
				else
				{
					m_pNode = m_pHead;
				}
				return *this;
			}

			//前++
			const iterator operator++(int)
			{
				iterator old = *this;
				++(*this);
				return old;
			}

			iterator& operator--(void)
			{
				if (m_pNode)
					m_pNode = m_pNode->m_prev;
				else
					m_pNode = m_pTail;
				return *this;
			}

			const iterator operator--(int)
			{
				iterator old = *this;
				--(*this);
				return old;
			}

			vaule_type& operator*(void) const
			{
				return m_pNode->m_data;
			}

			pointer operator->(void) const
			{
				return &*(*this);
			}

		private:
			pointer m_pHead;
			pointer m_pTail;
			pointer m_pNode;
			friend class List;
		};

		//获取起始正向迭代器
		iterator begin(void)
		{
			return iterator(m_pHead, m_pTail, m_pHead);
		}

		//获取终止正向迭代器
		iterator end(void)
		{
			return iterator(m_pHead, m_pTail);
		}

		//正向插入
		iterator insert(iterator loc, const vaule_type& data)
		{
			if ( loc == end() )
			{
				push_back(data);
				return iterator(m_pHead, m_pTail, m_pTail);
			}
			else
			{
				pointer p = new Node(data, loc.m_pNode->m_prev, loc.m_pNode);
				if (p->m_prev)//
					p->m_prev->m_next = p;
				else
					m_pHead = p;
				p->m_next->m_prev = p;
				return iterator(m_pHead, m_pTail, p);
			}
		}

		//删除
		iterator erase(iterator loc)
		{
			if (loc == end())
				throw invalid_argument("终止迭代");
			if (loc.m_pNode->m_prev)
				loc.m_pNode->m_prev->m_next = loc.m_pNode->m_next;
			else
				m_pHead = loc.m_pNode->m_next;
			if (loc.m_pNode->m_next)
				loc.m_pNode->m_next->m_prev = loc.m_pNode->m_prev;
			else
				m_pTail = loc.m_pNode->m_prev;
			pointer pNext = loc.m_pNode->m_next;
			delete loc.m_pNode;
			return iterator(m_pHead, m_pTail, pNext);
		}
	};

	template<>
	bool List<const char*>::equal(const char* const& left, const char* const& right) const
	{
		return strcmp(left, right) == 0;
	}

}