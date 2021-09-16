#include <iostream>
#include "UnorderedArray.h"

using namespace std;

int main()
{
	UnorderedArray<int> array(3);

	array.push(23);
	array.push(534);
	array.push(42);
	array.push(254);
	array.push(32);

	array[2] = 123;

	array.pop();
	cout << "Unordered array contents: ";
	for(int i = 0; i < array.getSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	cout << "Search for 254 was found at index: ";
	cout << array.search(254);
	cout << endl << endl;

	return 0;
}