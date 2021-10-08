#include <iostream>
#include "UnorderedArrayA1.h"
#include "OrderedArrayA1.h"
using namespace std;

int main()
{
	OrderedArray<int> thing(4, 2);
	
	thing.push(40);
	thing.push(20);
	thing.push(40);
	thing.push(231);
	thing.push(543);
	thing.push(123);
	thing.push(34);
	thing.push(54);
	thing[4] = 69;

	thing.pop();

	
	
	for(int i = 0; i < thing.getSize(); i++)
	{
		cout << thing[i] << " ";
	}
	cout << endl;
	
	thing.remove(5);
	thing.search(231);

	for (int i = 0; i < thing.getSize(); i++)
	{
		cout << thing[i] << " ";
	}
	cout << endl;

	cout << thing.getMaxSize() << endl;

	return 0;
}