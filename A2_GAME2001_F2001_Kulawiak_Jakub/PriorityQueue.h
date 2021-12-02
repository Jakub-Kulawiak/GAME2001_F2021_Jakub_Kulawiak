#pragma once
#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_
#include "Node.h"

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
		while(m_pList->m_pRoot)
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
	}
	void push(T data, int priority)
	{
		Node<T>* node = new Node<T>;
		assert(node != nullptr);
		node->m_data = data;
		node->m_priority = priority;

		if(m_pList->m_pLast == nullptr) //if empty
		{
			m_pList->m_pRoot = node;
			m_pList->m_pLast = node;
		}
		else // will search through based on priority to place the node in the list
		{
			LinkedIterator<T> sort;
			//priority is ordered highest = lower value
			for(sort = m_pList->Begin(); sort != m_pList->End(); sort++)
			{
				if(node->m_priority == sort.m_pNode->m_priority)
				{
					Node<T>* tempNode;
					tempNode = sort.m_pNode->m_pNext;
					sort.m_pNode->m_pNext = node;
					node->m_pNext = tempNode;
					tempNode = nullptr;
					break;
				}
				else if (node->m_priority < sort.m_pNode->m_priority)
				{
					Node* prevNode;
					node->m_pNext = sort.m_pNode;
					sort--;
					if(sort.m_pNode != nullptr)
					{
						sort.m_pNode->m_pNext = node;
					}
					sort++;
					break;
				}

			}
		}
		m_pList->m_size = m_pList->m_size++;
	}

};


#endif
