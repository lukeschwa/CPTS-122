#include "List.h"
List::List() {
	pHead = new Node();
}
bool List::isEmpty() {//SOMETHING WENT TERRIBLY WRONG, WHEN RUNNING, IT SAYS I HAVE 192 ERRORS, AND I CANT FIX IT
	if (this->pHead == nullptr) {
		return true;
	}
	else {
		return false;
	}
}
Node *List::getHeadPtr() const {
	return pHead;
}
void List::setHeadPtr(Node * const newHead) {
	pHead = newHead;
}
void List::insert(Node *newData) {
	if (newData != nullptr) {
		newData->setNextPtr(pHead);
	}
}