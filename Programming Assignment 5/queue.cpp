#include "queue.h"
Queue::Queue() {
	this->pHead = this->pTail = nullptr;
}
Queue::~Queue() {

}
bool Queue::isEmpty() {
	if (this->pHead == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
bool Queue::enqueue(const Data &newData) {
	QueueNode *pMem = new QueueNode(newData);
	bool success = false;
	if (pMem != nullptr) {
		
		success = true;
		if (this->pHead == nullptr) {
			
			this->pHead = this->pTail = pMem;
		}
		else {
			
			this->pTail->setNextPtr(pMem);
			this->pTail = pMem; 
		}
	}
	return success;
}
Data Queue::dequeue() {
	Data *returnValue;
	QueueNode *pTemp = nullptr;
	if (this->pHead == this->pTail) {
		returnValue = pHead->getData();
		delete this->pHead;
		this->pHead = this->pTail = nullptr;
	}
	else {
		pTemp = this->pHead;
		returnValue = this->pHead->getData();
		this->pHead = this->pHead->getNextPtr();
		delete pTemp;
		
	}
	return *returnValue;
}
void Queue::printQueue() {
	QueueNode *mpQueue = this->pHead;
	while (mpQueue != nullptr) {
		Data *mpData = mpQueue->getData();
		cout << "Customer: " << mpData->getCustomerNumber() << endl;
		cout << "\tTime in line: " << mpData->getServiceTime() << endl;
		mpQueue = mpQueue->getNextPtr();
	}
	if (this->isEmpty()) {
		cout << "Queue is Empty, cannot run simulation" << endl;
	}
}
