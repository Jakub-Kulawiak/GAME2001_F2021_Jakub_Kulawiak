#include <iostream>
#include "Node.h"



int main()
{
	PriorityQueue<int> testQueue;
	
	testQueue.push(12, 2);
	testQueue.push(45, 1);
	testQueue.pop();
	testQueue.push(48, 1);
	testQueue.push(48, 3);
	testQueue.push(69, 4);
	//if all is right it should be:
	//26 12 43 543

	LinkedIterator<int> testIt;
	for(testIt = testQueue.getLinkedList()->Begin(); testIt != testQueue.getLinkedList()->End(); testIt++)
	{
		std::cout << " " << *testIt;
	}
	std::cout << std::endl;
	return 0;
}