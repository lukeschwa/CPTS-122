#pragma once
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::fstream;
using std::istream;
using std::ostream;
using std::getline;
using std::stoi;

class Diet {
private:
	int dGoal;
	string dName;
	string dDate;
public:
	Diet();
	Diet(int newGoal, string newName, string newDate);
	Diet(Diet &newDiet);
	int getdGoal()const;
	void setdGoal(int newGoal);
	string getdName()const;
	void setdName(string newName);
	string getdDate()const;
	void setdDate(string newDate);
	void editGoal();
	~Diet();
};
ostream& operator<< (ostream &fileStream, const Diet &dietPlan);
istream& operator >> (istream &fileStream, Diet &dietPlan);