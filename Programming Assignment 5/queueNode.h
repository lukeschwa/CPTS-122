#pragma once
#include "data.h"
class QueueNode
{
public: 
	QueueNode();
	QueueNode(const Data &newData);
	QueueNode(const QueueNode &temp);
	QueueNode *getNextPtr();
	Data *getData();
	void setNextPtr(QueueNode *mpQueue);
	void setNewData(Data *newData);


private:
	Data *pData;    
	QueueNode *pNext;
};