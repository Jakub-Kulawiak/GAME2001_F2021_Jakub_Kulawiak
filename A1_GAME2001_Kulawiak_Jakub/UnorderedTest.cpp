#include <iostream>
#include "UnorderedArrayA1.h"
using namespace std;


int main()
{
	UnorderedArray<int> arrayUnordered(3);
	
	
	arrayUnordered.push(40);
	arrayUnordered.push(20);
	arrayUnordered.push(40);
	arrayUnordered.push(231);
	arrayUnordered.push(543);
	arrayUnordered.push(123);
	arrayUnordered.push(69);
	arrayUnordered.push(54);
	arrayUnordered[4] = 420;

	arrayUnordered.pop();

	for (int i = 0; i < arrayUnordered.getSize(); i++)
	{
		cout << arrayUnordered[i] << " ";
	}
	cout << endl;

	arrayUnordered.remove(5);
	arrayUnordered.search(231);

	for (int i = 0; i < arrayUnordered.getSize(); i++)
	{
		cout << arrayUnordered[i] << " ";
	}
	cout << endl;

	cout << arrayUnordered.getMaxSize() << endl;
	return 0;
}