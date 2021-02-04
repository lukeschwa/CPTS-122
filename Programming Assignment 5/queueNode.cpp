#include "queueNode.h"
QueueNode::QueueNode() {
	pData = nullptr;
	pNext = nullptr;
	pData = (Data *)malloc(sizeof(Data));
}
QueueNode::QueueNode(const Data &newData) {
	pData = (Data *)malloc(sizeof(Data));
	this->pData = new Data(newData);
	this->pNext = nullptr;

}
QueueNode::QueueNode(const QueueNode &temp) {
	pData = (Data *)malloc(sizeof(Data));
	this->pData = temp.pData;
	this->pNext = temp.pNext;
}
QueueNode *QueueNode::getNextPtr() {
	return this->pNext;
}
Data *QueueNode::getData() {
	return this->pData;
}
void QueueNode::setNextPtr(QueueNode *mpQueue) {
	this->pNext = mpQueue;
}
void QueueNode::setNewData(Data *newData) {
	this->pData = newData;
}
