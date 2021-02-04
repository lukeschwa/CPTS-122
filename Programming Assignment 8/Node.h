#pragma once
#include "StandardResources.h"

class Node {

public:
	Node();
	Node(string newData);
	virtual Node::~Node();
	Node *&getLeftPtr();
	Node *&getRightPtr();
	string getData();
	void setLeftPtr(Node *newLeft);
	void setRightPtr(Node *newRight);
	void setData(string newData);
	virtual void printData() {
		cout << mData << endl;
	}

private:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};

class tNode : public Node {
public:
	tNode();
	tNode(string newData, int units);
	~tNode();
	int getUnits() { return mUnits; }
	void setUnits(int newData) { mUnits = newData; }
	void printData();
private:
	int mUnits;
};