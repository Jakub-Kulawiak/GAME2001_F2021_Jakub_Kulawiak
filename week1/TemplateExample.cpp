//"Generic" classes or function
// Compare 2 things. Return smallest. Return largest.

#include "iostream"
using namespace std;

//Template function
//Check 2 "Things". Return the smallest
template <class T>
T min_func(T lVal, T rVal)
{
	if (lVal > rVal)
		return rVal;
 // will default if prior is false 
	return lVal;
}

//Template function
//Check 2 "Things". Return the largest
template <class T>
T max_func(T lVal, T rVal)
{
	if (lVal < rVal)
		return rVal;
	// will default if prior is false 
	return lVal;
}

//Implement a template class
template <class T>
class TemplateClass
{
private:
	T m_val;

public:
	//constructor
	TemplateClass(T val)
	{
		setVal(val);
	}
	//getter
	T getVal()
	{
		return m_val;
	}
	//setter
	void setVal(T val)
	{
		m_val = val;
	}
	//overloaded operators
	bool operator<(TemplateClass& rVal) // a < b ==> a.operator<(b); 
	{
		return m_val < rVal.getVal();
	}

	bool operator>(TemplateClass& rVal) // a > b ==> a.operator>(b);
	{
		return m_val > rVal.getVal();
	}
	
};

//Main function
int main()
{
	cout << "template Example" << endl << endl;
	cout << "Min = " << min_func(53.45, 12.24) << endl;
	cout << "Max = " << max_func('f', 'l') << endl;
	cout << "------------------------------------" << endl;

	cout << "Max (objects) = " << max_func(TemplateClass<int>(7), TemplateClass<int>(5)).getVal();
	
	return 0;
}