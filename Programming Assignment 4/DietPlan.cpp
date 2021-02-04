#include "DietPlan.h"
Diet::Diet() {
	dGoal = 0;
	dName = dDate = "";
}
Diet::Diet(int newGoal, string newName, string newDate) {
	dGoal = newGoal;
	dName = newName;
	dDate = newDate;
}
Diet::Diet( Diet &newDiet) {
	dGoal = newDiet.getdGoal();
	dName = newDiet.getdName();
	dDate = newDiet.getdDate();
}
int Diet::getdGoal()const {
	return dGoal;
}
void Diet::setdGoal(int newGoal) {
	dGoal = newGoal;
}
string Diet::getdName()const {
	return dName;
}
void Diet::setdName(string newName) {
	dName = newName;
}
string Diet::getdDate()const {
	return dDate;
}
void Diet::setdDate(string newDate) {
	dDate = newDate;
}
void Diet::editGoal() {
	int newGoal = 0;
	cout << "What would you like your new calorie goal to be? (PLEASE KEEP NUMBER UNDER 11 DIGITS)" << endl;
	cin >> newGoal;
	setdGoal(newGoal);

}
Diet::~Diet() {

}
ostream & operator<< (ostream &fileStream, const Diet &dietPlan) {
	fileStream << dietPlan.getdName() << endl;
	fileStream << dietPlan.getdGoal() << endl;
	fileStream << dietPlan.getdDate() << endl;

	return fileStream;
}
istream & operator>> (istream &fileStream,  Diet &dietPlan) {
	string line;
	getline(fileStream, line);
	dietPlan.setdName(line);
	getline(fileStream, line);
	dietPlan.setdGoal(stoi(line));
	getline(fileStream, line);
	dietPlan.setdDate(line);
	fileStream.ignore(1); //ignores one character from the infile in order to skip the \n
	return fileStream;
}