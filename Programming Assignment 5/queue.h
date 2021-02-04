#pragma once
#include "queueNode.h"
class Queue
{
public: 
	Queue();
	~Queue();
	bool isEmpty();
	bool enqueue(const Data &newData);
	Data dequeue(); 
	void printQueue();
private:
	QueueNode *pHead;
	QueueNode *pTail;
};