#pragma once
#ifndef _UNORDERED_ARRAY_
#define _UNORDERED_ARRAY_
#include "TemplateArray.h"

template <class T>
class UnorderedArray final : public BaseArray<T>
{
private:
	//Variables
	T* m_array; // points to the beginning of the array

	int m_maxSize; // Max size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Numbers of items currently in my array
	int m_interval = 1;

	// Private functions

	//Expansion
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

		m_maxSize += pow(m_growSize, m_interval);
		m_interval++;
		return true;
	}
public:

	//Constructor & Destructor
	UnorderedArray(int size, int growBy = 1) :
		m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // check if size is valid/legal
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_array
			memset(m_array, 0, sizeof(T) * m_maxSize); // explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0); // if true sets first option, else sets it as second option
		}
	}

	~UnorderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	
	//Insertion
	void push(T val)
	{
		assert(m_array != nullptr); //debugging purposes
		//check to see if array has space for new value, if not expands to make room
		if (m_numElements >= m_maxSize)
		{
			expand();
		}

		//array has enough space for new value, will be added to array
		m_array[m_numElements] = val;
		m_numElements++;
	}
	//Deletion 
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; //reduce the total number of elements by 1 (ignores the last element till something is added)
		}
	}
	//remove an item given an index
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= m_numElements)
		{	//tried to remove something out of bounds of the array
			return;
		}
		for (int i = index; i < m_numElements; i++)
		{
			//starts at the index we want to remove.
			if (i + 1 < m_numElements) 
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	//linear search
	int search(T val)
	{
		assert(m_array != nullptr);

		for (int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}

		return -1; 
	}


	//Overloaded [] operator
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < m_numElements);

		return m_array[index];
	}
	//Clear
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
	
};
#endif 
