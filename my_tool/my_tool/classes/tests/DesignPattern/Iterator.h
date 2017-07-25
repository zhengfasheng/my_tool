#pragma  once
/*
������ģʽ�� Iterator Pattern�� Ŀǰ�Ѿ���һ��û���ģʽ�� ������û�˻ᵥ��дһ����
������ �����ǲ�Ʒ���ʵĿ����� �䶨�����£�
���ṩһ�ַ�������һ�����������и���Ԫ�أ� ���ֲ��豩¶��
������ڲ�ϸ�ڡ�

�� Iterator���������
�����������������ʺͱ���Ԫ�صĽӿڣ� ���һ��������й̶���3�������� first()��
�õ�һ��Ԫ�أ� next()������һ��Ԫ�أ� isDone()�Ƿ��Ѿ����ʵ��ײ��� Java����hasNext()��
���� ��
�� ConcreteIterator���������
�����������ɫҪʵ�ֵ������ӿڣ� �������Ԫ�صı�����
�� Aggregate��������
������ɫ�����ṩ���������������ɫ�Ľӿڣ� ��Ȼ�ṩһ������createIterator()������
������ ��Java��һ����iterator()������
�� Concrete Aggregate��������
��������ʵ�������ӿڶ���ķ����� ���������ɵ������Ķ���

*/
#include <iostream>
#include <stdexcept>
//�Լ�ʵ��һ��List
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
			Node* m_prev;//ǰָ��
			Node* m_next;//��ָ��
			vaule_type m_data;//����
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

		pointer m_pHead;//ͷָ��
		pointer m_pTail;//βָ��

	public:

		List(void) :m_pHead(nullptr), m_pTail(nullptr){}
		~List()
		{
			clear();
		}
		//��������(���)
		List(const List& that)
			:m_pHead(nullptr), m_pTail(nullptr)
		{
			for (Node* p = that.m_pHead; p; p = p->m_next )
			{
				push_back(p);
			}
		}
		//������ֵ
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
			throw std::out_of_range("�±�Խ��");
		}

		//�õ���Ԫ��
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

		//�ײ�ѹ��
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

		//�ײ�����
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

		//�õ�βԪ��
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

		//��β��ѹ������
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

		//ɾ��β������
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

		//ɾ������ƥ��Ԫ��
		void remove(const vaule_type& data)
		{
			pointer p, pNext;
			for (p = m_pHead;p;p = pNext)
			{
				pNext = p->m_next;
				if (equal(p->m_data, data))
				{
					if (p->m_prev)//�������ǰ�ڵ�
					{
						p->m_prev->m_next = p->m_next;
					}
					else//���û��ǰ�ڵ�
					{
						m_pHead = p->m_next;
					}
					if ( p->m_next )//������к�ڵ�,�Ѻ����������
					{
						p->m_next->m_prev = p->m_prev;
					}
					else//���û�к�ڵ�
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

		//�Ƿ�Ϊ��
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

		//������
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

			//ǰ++
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

		//��ȡ��ʼ���������
		iterator begin(void)
		{
			return iterator(m_pHead, m_pTail, m_pHead);
		}

		//��ȡ��ֹ���������
		iterator end(void)
		{
			return iterator(m_pHead, m_pTail);
		}

		//�������
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

		//ɾ��
		iterator erase(iterator loc)
		{
			if (loc == end())
				throw invalid_argument("��ֹ����");
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