#pragma once
#include "BSTNode.h"
class BST {

public:
	BST();
	void insert(char newKey, string newMorse);
	string search(BSTNode *pTree, char &letter);
	BSTNode *getRootPtr();
	void print();
	~BST();
private:
	BSTNode *root;
	void insert(BSTNode *pTree, char newKey, string newMorse);
	void print(BSTNode *pTree);
	void destroyTree(BSTNode *pTree);
};