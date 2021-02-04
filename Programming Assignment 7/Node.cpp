#include "Node.h"

Node::Node() {
	record.abs = NULL;
	record.RN = NULL;
	record.ID = NULL;
	record.units = NULL;
	record.name = "";
	record.email = "";
	record.major = "";
	record.YIS = "";
	pNext = nullptr;
}
Node::Node(Data newData) {
	record.abs = newData.abs;
	record.RN = newData.RN;
	record.ID = newData.ID;
	record.units = newData.units;
	record.name = newData.name;
	record.email = newData.email;
	record.major = newData.major;
	record.dateAbs = newData.dateAbs;
}
Node::Node(const Node &copy) {
	this->record.abs = copy.getAbs();
	this->record.RN = copy.getRN();
	this->record.ID = copy.getID();
	this->record.units = copy.getUnits();
	this->record.name = copy.getName();
	this->record.email = copy.getEmail();
	this->record.major = copy.getMajor();
	this->record.dateAbs = copy.getStackOfAbs();
}

//GET AND SET ABSENCES
int Node::getAbs() const {
	return record.abs;
}
void Node::setAbs(int newData) {
	record.abs = newData;
}

//GET AND SET RECORD NUMBER
int Node::getRN() const {
	return record.RN;
}
void Node::setRN(int newData) {
	record.RN = newData;
}

//GET AND SET ID NUMBER
int Node::getID() const {
	return record.ID;
}
void Node::setID(int newData) {
	record.ID = newData;
}

//GET AND SET UNITS
int Node::getUnits() const {
	return record.units;
}
void Node::setUnits(int newData) {
	record.units = newData;
}

//GET AND SET NAME
string Node::getName() const {
	return record.name;
}
void Node::setName(string newData) {
	record.name = newData;
}

//GET AND SET EMAIL
string Node::getEmail() const {
	return record.email;
}
void Node::setEmail(string newData) {
	record.email = newData;
}

//GET AND SET MAJOR
string Node::getMajor() const {
	return record.major;
}
void Node::setMajor(string newData) {
	record.major = newData;
}

//GET AND SET YEAR IN SCHOOL(LEVEL)
string Node::getYearInSchool() const {
	return record.YIS;
}
void Node::setYearInSchool(string newData) {
	record.YIS = newData;
}

//GET ALL RECORD DATA
Data Node::getData() const {
	return record;
}

//GET AND PEEK ABSENCE LIST
string Node::peekAbsList() {
	return record.dateAbs.peek();
}
Stack Node::getStackOfAbs() const {
	return record.dateAbs;
}
void Node::setStackOfAbs(Stack newData) {
	record.dateAbs = newData; 
}

//GET AND SET NEXT POINTER
Node *Node::getNext()const {
	return pNext;
}
void Node::setNextPtr(Node *pNewNext) {
	pNext = pNewNext;
}

void Node::setDateAbs() {
	stringstream date;
	time_t t = time(0);   // get time now
	struct tm * now = localtime(&t);
	date << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< endl;
	record.dateAbs.push(date.str());
	setAbs(getAbs() + 1);
}