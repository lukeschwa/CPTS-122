#include "ExersicePlan.h"
Exercise::Exercise() {
	eGoal = 0;
	eName = "";
	eDate = "";
}
Exercise::Exercise(int newGoal, string newName, string newDate) {
	eGoal = newGoal;
	eName = newName;
	eDate = newDate;
}
Exercise::Exercise(Exercise &newExercise) {
	eGoal = newExercise.geteGoal();
	eName = newExercise.geteName();
	eDate = newExercise.geteDate();
}
int Exercise::geteGoal()const {
	return eGoal;
}
void Exercise::seteGoal(int newGoal) {
	eGoal = newGoal;
}
string Exercise::geteName()const {
	return eName;
}
void Exercise::seteName(string newName) {
	eName = newName;
}
string Exercise::geteDate()const {
	return eDate;
}
void Exercise::seteDate(string newDate) {
	eDate = newDate;
}
void Exercise::editGoal() {
	int newGoal = 0;
	cout << "What would you like your new steps goal to be? (PLEASE KEEP NUMBER UNDER 11 DIGITS)" << endl;
	cin >> newGoal;
	seteGoal(newGoal);

}
Exercise::~Exercise() {

}
ostream & operator<< (ostream &fileStream, const Exercise &exercisePlan) {
	fileStream << exercisePlan.geteName() << endl;
	fileStream << exercisePlan.geteGoal() << endl;
	fileStream << exercisePlan.geteDate() << endl;

	return fileStream;
}
istream & operator >> (istream &fileStream, Exercise &exercisePlan) {
	string line;
	getline(fileStream, line);
	exercisePlan.seteName(line);
	getline(fileStream, line);
	exercisePlan.seteGoal(stoi(line));
	getline(fileStream, line);
	exercisePlan.seteDate(line);
	fileStream.ignore(1); //ignores new line character
	return fileStream;
}