#pragma once
#include "BSTNode.h"
BSTNode::BSTNode(char *newKey, string *morseValue) {
	key = newKey;//the english charcter 
	morse = morseValue;// the cooresponding morse code value
	this->left = nullptr;
	this->right = nullptr;

}
char BSTNode::getKey() { // gets the english letter
	return *key;
}
string BSTNode::getMorse() { // gets morse code value
	return *morse;
}
BSTNode *BSTNode::getRightPtr() const { //gets the next right pointer
	return this->right;
}
BSTNode *BSTNode::getLeftPtr() const{ //gets the next left pointer
	return this->left;
}
void BSTNode::setKey(char &newKey) { //sets the english letter to a new value
	*(this->key) = newKey;
}
void BSTNode::setMorse(string &newMorse) {//sets the morse code to a new value
	*(this->morse) = newMorse;
}
void BSTNode::setLeftPtr(BSTNode *const &newLeft) { //sets the left pointer
	this->left = newLeft;
}
void BSTNode::setRightPtr(BSTNode *const &newRight) {// sets the right pointer
	this->right = newRight;
}