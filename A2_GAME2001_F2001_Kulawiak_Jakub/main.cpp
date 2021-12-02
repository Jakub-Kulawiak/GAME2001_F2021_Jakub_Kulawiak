#include <iostream>
#include "Node.h"



int main()
{
	PriorityQueue<int> testQueue;
	testQueue.push(12, 2);
	testQueue.push(45, 1);
	testQueue.pop();
	testQueue.push(543, 4);
	testQueue.push(43, 3);
	testQueue.push(25, 1);
	testQueue.push(26, 1);
	testQueue.pop();
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