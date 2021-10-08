#pragma once
#ifndef _ORDERED_ARRAY_
#define _ORDERED_ARRAY_
#include "TemplateArray.h"

template <class T>
class OrderedArray final : public BaseArray<T>
{
private:
	T* m_array;
	int m_interval = 1;

public:
	OrderedArray(int size, int growBy): m_array(NULL), BaseArray<T>(size, growBy) 
	{
		m_array = new T[this->getMaxSize()]; // Dynamically allocating an array to m_array
		memset(m_array, 0, sizeof(T) * this->getGrowSize() ); // explicitly set 0 to all elements in the array
	}

	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}

	bool expand()
	{
		if (this->getGrowSize() <= 0)
		{
			//Leave!
			return false;
		}
		//create new array
		T* temp = new T[this->getMaxSize() + this->getGrowSize()];
		assert(temp != nullptr);

		//copy the contents of the original array into the new array
		memcpy(temp, m_array, sizeof(T) * this->getMaxSize());

		//delete old array
		delete[] m_array;

		//clean up variable assignments
		m_array = temp;
		temp = nullptr; //cleans up anything dangling 

		this->setMaxSize(pow(this->getGrowSize(),pow(this->getGrowSize(),m_interval)));
		m_interval++;
		return true;
	}
	
	T& operator[](int index)
	{
		assert(m_array != nullptr && index < this->getNumElements());
	
		return m_array[index];
	}

	bool isDouble(T val)
	{
		if(search(val) == true)
		{
			return true;
		}
		
		return false;
	}
	
	void push(T val)
	{
		assert(m_array != nullptr);
		
		if (isDouble(val) == false)
		{
		
			if (this->getNumElements() >= this->getMaxSize())
			{
				expand();
			}
			int i, k; //i index to be inserted. k used for shifting purposes.

			for (i = 0; i < this->getNumElements(); i++)
			{
				if (m_array[i] > val)
					break;
			}
			//step 2 shift everything to the right of the index by one(work backwards)
			for (k = this->getNumElements(); k > i; k--)
			{
				m_array[k] = m_array[k - 1];
			}
			//step 3 insert val into array at index
			m_array[i] = val;

			this->setNumElements(this->getNumElements() - 1);
			//return i;
		}
	}

	//Deletion (2 ways)
	void pop()
	{
		if (this->getNumElements() > 0)
		{
			this->setNumElements(this->getNumElements() - 1); //reduce the total number of elements by 1 (ignores the last element till something is added)
		}
	}
	//remove an item given an index
	// almost brute force execution -- BIG O notation = O(N)
	void remove(int index)
	{
		assert(m_array != nullptr);

		if (index >= this->getNumElements())
		{	//tried to remove something out of bounds of the array
			return; // maybe should have some form of exception handling
		}
		for (int i = index; i < this->getNumElements(); i++)
		{
			//starts at the index we want to remove.
			//shifts everything after index back by one.
			if (i + 1 < this->getNumElements()) // confines the loop into the array
			{
				m_array[i] = m_array[i + 1];
			}
		}
		this->setNumElements(this->getNumElements() - 1);
	}
	//Searching
	//Binary search
	int search(T searchKey)
	{
		assert(m_array != nullptr);
		//helper variables
		int lowerBound = 0;
		int upperBound = this->getNumElements() - 1;
		int current = 0;

		while (1)	//this will be replaced with recursion 
		{
			current = (lowerBound + upperBound) >> 1; // preview of bit wise operation. divides by 2
			//Binary Steps
			//Step 1: check if the middle is the value we are looking for.
			if (m_array[current] == searchKey)
			{
				return current;
			}
			//Step 2: check that we've exhausted all options. Can't find the item.
			else if (lowerBound > upperBound)
			{
				return -1;
			}
			//Step 3: check which half of the array the value is in.
			else
			{
				if (m_array[current] < searchKey)
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
	void clear()
	{
		this->setNumElements(0); //Ignores/forgets all current items in the array
	}

};
#endif
