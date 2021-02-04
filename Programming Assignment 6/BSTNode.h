#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::fstream;
using namespace std;

class BSTNode {
public:
	BSTNode(char *newKey, string *morseValue);
	char getKey();
	string getMorse();
	BSTNode *getRightPtr() const;
	BSTNode *getLeftPtr() const;
	void setKey(char &newKey);
	void setMorse(string &newMorse);
	void setLeftPtr(BSTNode *const &newLeft);
	void setRightPtr(BSTNode *const &newRight);

private:
	char *key;
	string *morse;
	BSTNode *left;
	BSTNode *right;

};
