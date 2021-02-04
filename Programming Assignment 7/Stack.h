#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <ctime>
#include <sstream>
using std::istringstream;
using std::ostringstream;
using std::stringstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::getline;
using std::feof;
using std::atoi;
using std::fopen;
using std::ofstream;

class Stack {
public:
	Stack();
	~Stack();
	void push(string newData);
	string pop();
	string peek();
	bool isEmpty();

private:
	string data[50];
	int i;
};