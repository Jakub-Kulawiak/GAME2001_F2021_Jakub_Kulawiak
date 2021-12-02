#pragma once
#ifndef _NODE_H_
#define	_NODE_H_
#include <cassert>

template <class T> class LinkedList;
template <class T> class LinkedIterator;
template <class T> class PriorityQueue;


template <class T>
class Node
{
private:
	Node* m_pNext;
	Node* m_pPrev;
	int m_priority;
	T m_data;

public:
	friend class LinkedList<T>;
	friend class LinkedIterator<T>;
	friend class PriorityQueue<T>;

	int getPriority()
	{
		return m_priority;
	}
	void setPriority(int rank)
	{
		m_priority = rank;
	}
};

template <class T>
class LinkedIterator
{
private:
	Node<T>* m_pNode;
public:
	friend class PriorityQueue<T>;
	LinkedIterator()
	{
		m_pNode = nullptr;
	}

	~LinkedIterator() {} 
	//Assignment operator (=)
	void operator=(Node<T>* node)
	{
		m_pNode = node;
	}

	T& operator*()
	{
		assert(m_pNode != nullptr);
		return m_pNode->m_data;
	}

	void operator++() // prefix
	{
		assert(m_pNode != nullptr);
		m_pNode = m_pNode->m_pNext;
	}

	void operator++(int) // postfix
	{
		assert(m_pNode != nullptr);
		m_pNode = m_pNode->m_pNext;
	}
	bool operator!=(Node<T>* node)
	{
		return (m_pNode != node);
	}
	bool operator==(Node<T>* node)
	{
		return (m_pNode == node);
	}
};

template <class T>
class LinkedList
{
private:
	int m_size; // holds size of link list
	Node<T>* m_pRoot; // points to first node of the linked list
	Node<T>* m_pLast; // points to last node

public:
	friend class PriorityQueue<T>;
	LinkedList() : m_size(0), m_pRoot(nullptr), m_pLast(nullptr){}
	
	~LinkedList()
	{
		while(m_pRoot)
		{
			pop();
		}
	}

	Node<T>* Begin()
	{
		assert(m_pRoot != nullptr);
		return m_pRoot;
	}

	Node<T>* End()
	{
		return nullptr;
	}

	Node<T>* Last()
	{
		assert(m_pLast != nullptr);
		return m_pLast;
	}

	void push(T newData)
	{
		Node<T>* node = new Node<T>;

		assert(node != nullptr);
		node->m_data = newData;
		node->m_pNext = nullptr;

		if(m_pLast != nullptr)
		{
			m_pLast->m_pNext = node;
			m_pLast = node;
		}
		else //is empty
		{
			m_pRoot = node;
			m_pLast = node;
		}
		m_size++;
	}

	void pop()
	{
		assert(m_pRoot != nullptr);
		//if there is only one node
		if (m_pRoot->m_pNext == nullptr)
		{
			delete m_pRoot;
			m_pRoot = nullptr;
			m_pLast = nullptr;
		}
		else //linked list has 2 or more elements
		{
			Node<T>* prevNode = m_pRoot; 

			while (prevNode->m_pNext != nullptr && prevNode->m_pNext != m_pLast)
			{
				prevNode = prevNode->m_pNext;
			}

			delete m_pLast;
			prevNode->m_pNext = nullptr;
			m_pLast = prevNode;
			prevNode = nullptr;
		}
		m_size = (m_size == 0 ? m_size : m_size - 1); // prevents negative numbers/sizes
	}

	int getSize()
	{
		return m_size;
	}

};

template <class T>
class PriorityQueue
{
private:
	LinkedList<T>* m_pList;


public:

	PriorityQueue()
	{
		m_pList = new LinkedList<T>;
	}
	~PriorityQueue()
	{
		while (m_pList->m_pRoot)
		{
			pop();
		}
	}

	LinkedList<T>* getLinkedList()
	{
		return m_pList;
	}

	void pop()
	{
		assert(m_pList->m_pRoot != nullptr);
		Node<T>* tempNode;
		tempNode = m_pList->m_pRoot->m_pNext;
		delete m_pList->m_pRoot;
		m_pList->m_pRoot = tempNode;
		tempNode = nullptr;
		m_pList->m_size--;
	}
	void push(T data, int priority)
	{
		Node<T>* node = new Node<T>;
		assert(node != nullptr);
		node->m_data = data;
		node->m_priority = priority;

		if (m_pList->m_pRoot == nullptr) //if empty
		{
			m_pList->m_pRoot = node;
			m_pList->m_pLast = node;
		}
		else if(m_pList->m_pRoot != nullptr) // will search through based on priority to place the node in the list
		{
			LinkedIterator<T> sort;
			//priority is ordered highest = lower value
			for (sort = m_pList->Begin(); sort != m_pList->End(); sort++)
			{
				if (node->m_priority == sort.m_pNode->m_priority)
				{
					Node<T>* tempNode;
					tempNode = sort.m_pNode->m_pNext;
					sort.m_pNode->m_pNext = node;
					node->m_pNext = tempNode;
					tempNode = nullptr;
					if(node->m_pNext == nullptr)
					{
						m_pList->m_pLast = node;
					}
					break;
				}
				else if (node->m_priority < sort.m_pNode->m_priority)
				{
					Node<T>* tempNode = sort.m_pNode->m_pPrev;
					node->m_pNext = sort.m_pNode;
					sort.m_pNode->m_pPrev = node;
					node->m_pPrev = tempNode;
					tempNode = nullptr;
					if(node->m_pPrev == nullptr)
					{
						m_pList->m_pRoot = node;
					}
					break;
				}
				else if(sort.m_pNode == m_pList->End())
				{
					m_pList->m_pLast->m_pNext = node;
					node->m_pPrev = m_pList->m_pLast;
					m_pList->m_pLast = node;
				}
			}
		}
		m_pList->m_size = m_pList->m_size++;
	}
};
#endif
