#pragma once
#include <cassert>


template<class T>
class OrderedArray
{
private:
	//Variables
	T* m_array; // points to the beginning of the array

	int m_maxSize; // Max size of the array
	int m_growSize; // Amount the array can grow through expansion
	int m_numElements; // Numbers of items currently in my array 

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

		m_maxSize += m_growSize;
		return true;
	}
public:

	//Constructor
	OrderedArray(int size, int growBy = 1) :
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

	//Destructor
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	//Insertion
	//fast insertion for unordered array Big O is O(N)
	void push(T val)
	{
		assert(m_array != nullptr);

		if(m_numElements >= m_maxSize)
		{
			expand();
		}
		int i, k; //i index to be inserted. k used for shifting purposes.

		for (i=0;i< m_numElements; i++)
		{
			if (m_array[i] > val)
				break;
		}
		//step 2 shift everything to the right of the index by one(work backwards)
		for (k = m_numElements; k > i; k--)
		{
			m_array[k] = m_array[k - 1];
		}
		//step 3 insert val into array at index
		m_array[i] = val;

		m_numElements++;
		//return i;
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
			if (i + 1 < m_numElements) // confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		m_numElements--;
	}
	//Searching
	//Binary search
	int search(T searchKey)
	{
		assert(m_array != nullptr);
		//helper variables
		int lowerBound = 0;
		int upperBound = m_numElements - 1;
		int current = 0;

		while(1)	//this will be replaced with recursion 
		{
			current = (lowerBound + upperBound) >> 1; // preview of bit wise operation. divides by 2
			//Binary Steps
			//Step 1: check if the middle is the value we are looking for.
			if(m_array[current] == searchKey)
			{
				return current;
			}
			//Step 2: check that we've exhausted all options. Can't find the item.
			else if(lowerBound > upperBound)
			{
				return -1;
			}
			//Step 3: check which half of the array the value is in.
			else
			{
				if(m_array[current] < searchKey)
				{
					lowerBound = current + 1; // value may be in upper half
				}
				else
				{
					upperBound = current - 1; // value may be in lower half
				}
			}
		}
		return -1; // catch all return from danger
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
	int getMaxSize() const
	{
		return m_maxSize;
	}

	int getGrowSize() const
	{
		return m_growSize;
	}

	int getSize() const
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