#include "Stack.h"
Stack::Stack() {
	i = -1;
}
Stack::~Stack() {
	for (int index = 0; !isEmpty(); index++) {
		pop();
	}
}
void Stack::push(string newData) {
	i++;
	data[i] = newData;
	
}
string Stack::pop() {
	string tempPeek = peek();
	data[i] = "";
	i--;
	return tempPeek;
}
string Stack::peek() {
	return data[i];
}
bool Stack::isEmpty() {
	if (i == -1) {
		return true;
	}
	else {
		return false;
	}
}