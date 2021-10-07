#pragma once
#ifndef _UNORDERED_ARRAY_
#define _UNORDERED_ARRAY_
#include "TemplateArray.h"

template <class T>
class UnorderedArray : public BaseArray
{
private:

public:
	UnorderedArray(int size, int)
	{
		if (size) // check if size is valid/legal
		{
			BaseArray(size);
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

	void push(T val) override
	{
		assert(m_array != nullptr); //debugging purposes
	//check to see if array has space for new value, if not expands to make room
		if (m_numElements >= m_maxSize)
		{
			expand();
		}

		//array has enough space for new value, will be added to array
		m_array[m_numElements] = val;
		m_numElements + m_growSize;
	}

	bool search(T search)
	{

	}

};
#endif 
