#pragma once
#ifndef _TEMPLATE_ARRAY_
#define _TEMPLATE_ARRAY_
#include <cassert>
#include <cmath>
#include <iostream>

template <class T>
class BaseArray
{
private:

	

	int m_maxSize;
	int m_growSize;
	int m_numElements;


public:

	BaseArray(int size, int growBy) :
		 m_maxSize(0), m_growSize(0), m_numElements(0)
	{
		if (size) // check if size is valid/legal
		{
			m_maxSize = size;
			m_growSize = ((growBy > 0) ? growBy : 0); // if true sets first option, else sets it as second option
		}
	}
	~BaseArray() = default;

	int getNumElements()
	{
		return m_numElements;
	}

	void setNumElements(int size)
	{
		m_numElements = size;
	}

	int getGrowSize()
	{
		return m_growSize;
	}

	void setGrowSize(int growBy)
	{
		m_growSize = growBy;
	}

	int getMaxSize()
	{
		return m_maxSize;
	}

	void setMaxSize(int maxSize)
	{
		m_maxSize = maxSize;
	}
	
};
#endif 
