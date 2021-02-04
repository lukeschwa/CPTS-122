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

class Exercise {
private:
	int eGoal;
	string eName;
	string eDate;
public:
	Exercise();
	Exercise(int newGoal, string newName, string newDate);
	Exercise(Exercise &newExercise);
	int geteGoal()const;
	void seteGoal(int newGoal);
	string geteName()const;
	void seteName(string newName);
	string geteDate()const;
	void seteDate(string newDate);
	void editGoal();
	~Exercise();
};
ostream& operator<< (ostream &fileStream, const Exercise &exercisePlan);
istream& operator>> (istream &fileStream, Exercise &exercisePlan);