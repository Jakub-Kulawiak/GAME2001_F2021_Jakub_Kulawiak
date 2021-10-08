#pragma once
#ifndef _UNORDERED_ARRAY_
#define _UNORDERED_ARRAY_
#include "TemplateArray.h"

template <class T>
class UnorderedArray final : public BaseArray<T>
{
private:
	

public:
	UnorderedArray(int size, int growBy);

	
//	T& operator[](int index)
//	{
//		assert(m_pArray != nullptr && index < m_numbElements);
//
//		return m_pArray[index];
//	}
	
};
#endif 
