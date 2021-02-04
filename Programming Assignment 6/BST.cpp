#include "BST.h"
//Constructer
//sets the root value to nullptr, opens the morseTable.txt file, and builds the tree
BST::BST() {
	this->root = nullptr;
	char letter = '\0';
	string morseValue = "";
	fstream infile;
	infile.open("morseTable.txt", fstream::in);
	while (!infile.eof()) {
			infile >> letter;
			infile >> morseValue;
			insert(letter, morseValue);//inserts a new node with the values "letter" and "morsevalue" into the tree
	}
	infile.close();
}

BSTNode *BST::getRootPtr() {//gets the root pointer
	return this->root;
}

//Insert
//called by the constructer to build the tree, inserts a new node
void BST::insert(char newKey, string newMorse) {
	insert(this->root, newKey, newMorse);
}
void BST::insert(BSTNode *pTree, char newKey, string newMorse) {
	if (pTree == nullptr) {
		char *pKey = new char; //allocates space Node to hold the value of a letter(key)
		*pKey = newKey;
		string *pMorse = new string;//allocates space Node to hold the value of a morse code string
		*pMorse = newMorse;
		this->root = new BSTNode(pKey, pMorse);//sets the values of the root node 
	}
	else {
		if (newKey < pTree->getKey()) {
			if (pTree->getLeftPtr() != nullptr) { // already a node there, iterates the tree to the left and run function again
				insert(pTree->getLeftPtr(), newKey, newMorse); 
			}
			else {// enter a new node only of no other node is connected on the left
				char *pKey = new char;
				*pKey = newKey;
				string *pMorse = new string;
				*pMorse = newMorse;
				pTree->setLeftPtr(new BSTNode(pKey,pMorse)); // connect a new node
			}
		}
		else {// same as above but for the right pointer
			if (pTree->getRightPtr() != nullptr) {// enter a new node only of no other node is connected on the left
				insert(pTree->getRightPtr(), newKey, newMorse);
			}
			else {
				char *pKey = new char;
				*pKey = newKey;
				string *pMorse = new string;
				*pMorse = newMorse;
				pTree->setRightPtr(new BSTNode(pKey, pMorse));
			}
		}
	}
}
//searches the tree for the correct letter
//returns the value of the letter that was found
string BST::search(BSTNode *pTree, char &letter) {
	string morseValue;
	char targetLetter;
	if (pTree != nullptr) { //run if tree is not empty
		if (letter == pTree->getKey()) {//the letter was found
			morseValue = pTree->getMorse();
			return morseValue;
		}
		else if (letter < pTree->getKey()) {//letter is smaller than the current node, run function again but iterate left pointer first
			return search(pTree->getLeftPtr(), letter);
		}
		else if (letter > pTree->getKey()) {//letter is larger than the current node, run function again but iterate right pointer first
			return search(pTree->getRightPtr(), letter);
		}
	}
	else {
		return morseValue;//last node in the tree, return it
	}
}
//simple print tree in order using recursion
void BST::print() {
	print(this->root);
}
void BST::print(BSTNode *pTree) {
	if (pTree != nullptr) {
		print(pTree->getLeftPtr());
		cout << '[' << pTree->getKey() << ']' << ':' << ' ' << pTree->getMorse() << endl;
		print(pTree->getRightPtr());
	}
}
//destroys the tree
BST::~BST() {
	this->destroyTree(this->root);
}
void BST::destroyTree(BSTNode *pTree) {
	if (pTree != nullptr) {
		destroyTree(pTree->getLeftPtr());
		destroyTree(pTree->getRightPtr());
		delete pTree;
	}
}