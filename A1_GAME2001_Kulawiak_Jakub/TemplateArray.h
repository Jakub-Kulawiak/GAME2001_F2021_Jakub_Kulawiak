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
T* m_array;
	int m_maxSize;
	int m_growSize;
	int m_numElements;
public:


	BaseArray()
	{
	
	}
	~BaseArray() = default;


};
#endif 
