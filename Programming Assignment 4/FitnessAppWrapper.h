#pragma once
#include "DietPlan.h"
#include "ExersicePlan.h"
using std::fstream;

class Wrapper {
private:
	string *dietWeek[7];
	string *exerciseWeek[7];
public:
	void runApp(void);
	void loadDailyPlan(fstream &fileStream, Diet &plan);
	void loadDailyPlan(fstream &fileStream, Exercise &plan);
	void loadWeeklyPlan(fstream &fileStream, Diet *weeklyPlan[]);
	void loadWeeklyPlan(fstream &fileStream, Exercise *weeklyPlan[]);
	void displayDailyPlan(Diet diet);
	void displayDailyPlan(Exercise exercise);
	void displayWeeklyPlan(Diet diet[]);
	void displayWeeklyPlan(Exercise exercise[]);
	void displayDailyName(Diet diet[]);
	void displayDailyName(Exercise exercise[]);
	void storeDailyPlan(fstream &fileStream, Diet diet);
	void storeDailyPlan(fstream &fileStream, Exercise exercise);
	void storeWeeklyPlan(fstream &fileStream, Diet diet[]);
	void storeWeeklyPlan(fstream &fileStream, Exercise exercise[]);
	int displayMenu();
};