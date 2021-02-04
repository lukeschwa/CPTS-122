#pragma once
#include "Stack.h"


struct Data {
	int abs;
	int RN;
	int ID;
	int units;
	string name;
	string email;
	string major;
	string YIS;
	Stack dateAbs;
};

class Node {
public:
	Node();
	Node(Data newData);
	Node(const Node &copy);
	~Node();

	int getAbs() const;
	void setAbs(int newData);
	int getRN() const;
	void setRN(int newData);
	int getID() const;
	void setID(int newData);
	int getUnits() const;
	void setUnits(int newData);
	string getName() const;
	void setName(string newData);
	string getEmail() const;
	void setEmail(string newData);
	string getMajor() const;
	void setMajor(string newData);
	string getYearInSchool() const;
	void setYearInSchool(string newData);
	Stack getStackOfAbs() const;
	void setStackOfAbs(Stack newData);
	string peekAbsList();
	Data getData() const;
	Node *getNext()const;
	void setNextPtr(Node *pNewNext);
	void setDateAbs();
private:
	Data record;
	Node *pNext = (Node *)malloc(sizeof(Node));
};



