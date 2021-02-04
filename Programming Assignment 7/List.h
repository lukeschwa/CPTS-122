#pragma once
#include "Node.h"
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <sstream>

using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::getline;
using std::feof;
using std::atoi;
class List {
public:
	List();
	bool isEmpty();
	Node *getHeadPtr() const;
	void setHeadPtr(Node * const newHead);
	void insert(Node *newData);
private:
	Node *pHead;

};