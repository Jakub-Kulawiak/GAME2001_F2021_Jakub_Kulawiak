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
	thing[2] = 45;

	//for(int i = 0; i < thing.getNumElements(); i++)
	//{
	//	cout << thing[i] << " ";
	//}
	cout << endl;
	thing.search(231);

	return 0;
}