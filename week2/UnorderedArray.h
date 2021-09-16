#pragma once
#include <cassert>


template<class T>
class UnorderedArray
{
private:
	//Variables
	T* m_array; // points to the beginning of the array
	
	int m_maxSize; // Max size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Numbers of items currently in my array 

	// Private functions

	//Expansion
	bool Expand()
	{
		if(m_growSize <= 0)
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
		return true;
	}
public:

	//Constructor
	UnorderedArray(int size, int growBy = 1) :
	m_array(NULL), m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if(size) // check if size is valid/legal
		{
			m_maxSize = size;
			m_array = new T[m_maxSize]; // Dynamically allocating an array to m_array
			memset(m_array, 0, sizeof(T)* m_maxSize); // explicitly set 0 to all elements in the array

			m_growSize = ((growBy > 0) ? growBy : 0); // if true sets first option, else sets it as second option
		}
	}
	
	//Destructor
	~UnorderedArray()
	{
		if(m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	
	//Insertion
	//fast insertion for unordered array Big O is O(1)
	void push(T val)
	{
		assert(m_array != nullptr); //debugging purposes
		//check to see if array has space for new value, if not expands to make room
		if (m_numElements >= m_maxSize)
		{
			//expand(); 
		}

		//array has enough space for new value, will be added to array
		m_array[m_numElements] = val;
		m_numElements++;	
	}

	//Deletion (2 ways)
	void pop()
	{
		if (m_numElements > 0)
		{
			m_numElements--; //reduce the total number of elements by 1 (ignores the last element till something is added)
		}
	}
	//remove an item given an index
	// almost brute force execution -- BIG O notation = O(N)
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
			if(i+1 < m_numElements) // confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}	
		}
		m_numElements--;
	}
	//Searching
	//linear search
	int search(T val)
	{
		assert(m_array != nullptr);
		//brute force search
		for(int i = 0; i < m_numElements; i++)
		{
			if (m_array[i] == val)
				return i;
		}

		return -1; // if failed search/failed to find value
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