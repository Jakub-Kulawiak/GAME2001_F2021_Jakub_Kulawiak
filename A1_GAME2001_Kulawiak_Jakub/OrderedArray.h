#pragma once
#ifndef _ORDERED_ARRAY_
#define _ORDERED_ARRAY_
#include "TemplateArray.h"
#include <iostream>

template <class T>
class OrderedArray : public BaseArray
{
private:


public:

	OrderedArray(int size)
	{
		if (size) // check if size is valid/legal
		{
			BaseArray(size);
		}
	}
	~OrderedArray()
	{
		if (m_array != nullptr)
		{
			delete[] m_array;
			m_array = nullptr;
		}
	}
	
	void push(T val) override
	{
		//will perform a check if the item exists before adding it
		if (isDouble(val) == false)
		{
			void push(T val)
			{
				assert(m_array != nullptr);

				if (m_numElements >= m_maxSize)
				{
					expand();
				}
				int i, k; //i index to be inserted. k used for shifting purposes.

				for (i = 0; i < m_numElements; i++)
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
		}
		//basic statement if the item is in the array already
		std::cout << "The item already exists in the Array!"
	}

	//will search array for entered value 
	bool search(T search)
	{
		assert(m_array != nullptr);
		//helper variables
		int lowerBound = 0;
		int upperBound = m_numbElements - 1;
		int current = 0;

		while (1)	//this will be replaced with recursion 
		{
			current = (lowerBound + upperBound) >> 1; // preview of bit wise operation. divides by 2
			//Binary Steps
			//Step 1: check if the middle is the value we are looking for.
			if (m_array[current] == search)
			{
				return true;
			}
			//Step 2: check that we've exhausted all options. Can't find the item.
			else if (lowerBound > upperBound)
			{
				return false;
			}
			//Step 3: check which half of the array the value is in.
			else
			{
				if (m_array[current] < search)
				{
					lowerBound = current + 1; // value may be in upper half
				}
				else
				{
					upperBound = current - 1; // value may be in lower half
				}
			}
		}
		return false; // catch all return from danger
	}

	//will check if value is in the array
	bool isDouble(T Item)
	{
		if (search(Item) == true)
		{
			return true;
		}

		return false;
	}
};
#endif 