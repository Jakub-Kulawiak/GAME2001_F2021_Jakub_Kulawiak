#pragma once
#ifndef _TEMPLATE_ARRAY_
#define _TEMPLATE_ARRAY_
#include <cassert>
#include <cmath>

template <class T>
class BaseArray
{
private:
	T* m_pArray;
	int m_numbElements;
	int m_growSize = 2;
	int interval = 1;

	bool expand()
	{
		if (m_growSize <= 0)
		{
			//Leave!
			return false;
		}
		//create new array
		T* temp = new T[m_maxSize + m_growSize];
		assert(temp != nullptr);

		//copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * m_maxSize);

		//delete old array
		delete[] m_array;

		//clean up variable assignments
		m_array = temp;
		temp = nullptr; //cleans up anything dangling 

		m_maxSize += m_growSize;
		m_growSize = pow(m_growSize, interval);
		interval++;
		return true;
	}

public:

	BaseArray(int size) :
	m_array(NULL), m_maxSize(0), m_numElements(0)
	{
		m_maxSize = size;
		m_array = new T[m_maxSize]; // Dynamically allocating an array to m_array
		memset(m_array, 0, sizeof(T) * m_maxSize); // explicitly set 0 to all elements in the array
	}

	~BaseArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	//To be inherrited
	//(As they're all the same function)
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; //reduce the total number of elements by 1 (ignores the last element till something is added)
		}
	}

	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{	//tried to remove something out of bounds of the array
			return; // maybe should have some form of exception handling
		}
		for (int i = index; i < m_numElements; i++)
		{
			//starts at the index we want to remove.
			//shifts everything after index back by one.
			if (i + 1 < m_numElements) // confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	
	void clear()
	{
		m_numElements = 0; //Ignores/forgets all current items in the array
	}

	//Getters and Setters
	int getMaxSize()
	{
		return m_maxSize;
	}

	int getGrowSize()
	{
		return m_growSize;
	}

	int getSize()
	{
		return m_numElements;
	}

	void setMaxSize(int size)
	{
		m_maxSize = size;
	}

	void setGrowSize(int growBy)
	{
		assert(growBy >= 0);
		m_growSize = growBy;
	}

	//overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);

		return m_array[index];
	}

	//pure virtual functions to be later declared
	virtual void push(T val) = 0;
	
};
#endif 