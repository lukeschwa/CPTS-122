#include "FitnessAppWrapper.h"
void Wrapper::runApp(void) {
	fstream dietFile, exerciseFile;
	dietFile.open("dietPlans.txt");
	exerciseFile.open("exercisePlans.txt");
	int menuSelect;
	Diet *diet = new Diet[7];
	Exercise *exercise = new Exercise[7];
	
	do {
		system("cls");
		menuSelect = displayMenu();
		switch (menuSelect) {
		case 1:
			loadWeeklyPlan(dietFile,&diet);
			cout << "Done" << endl;
			system("pause");
			break;
		case 2:
			loadWeeklyPlan(exerciseFile, &exercise);
			cout << "Done" << endl;
			system("pause");
			break;
		case 3:
			storeWeeklyPlan(dietFile, diet);
			cout << "Done" << endl;
			system("pause");
			break;
		case 4:
			storeWeeklyPlan(exerciseFile, exercise);
			cout << "Done" << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			displayWeeklyPlan(diet);
			system("pause");
			break;
		case 6:
			system("cls");
			displayWeeklyPlan(exercise);
			system("pause");
			break;
		case 7:
			system("cls");
			int select;
			displayDailyName(diet);
			cout << "\nWhat plan would you like to edit?" << endl;
			cin >> select;
			if (select > 7) {
				cout << "invalid input" << endl;
			}
			else {
				select = select - 1;
				diet[select].editGoal();
				cout << "Done" << endl;
			}
			system("pause");
			break;
			
		case 8:
			system("cls");
			int selectTwo;
			displayDailyName(exercise);
			cout << "\nWhat plan would you like to edit?" << endl;
			cin >> selectTwo;
			if (selectTwo > 7) {
				cout << "invalid input" << endl;
			}
			else {
				selectTwo = selectTwo - 1;
				diet[selectTwo].editGoal();
				cout << "Done" << endl;
			}
			system("pause");

			break;
		case 9:
			cout << "Goodbye" << endl;
			storeWeeklyPlan(dietFile, diet);
			storeWeeklyPlan(exerciseFile, exercise);



		}
	} while (menuSelect != 9);
}
//_________________________________________________________
void Wrapper::loadDailyPlan(fstream &fileStream, Diet &plan) {
	fileStream >> plan;
}
void Wrapper::loadDailyPlan(fstream &fileStream, Exercise &plan) {
	fileStream >> plan;
}


//_________________________________________________________
void Wrapper::loadWeeklyPlan(fstream &fileStream, Diet *weeklyPlan[]) {
	Diet temp;
	for (int i = 0; i < 7; ++i) {
		loadDailyPlan(fileStream, temp);
		(*weeklyPlan)[i] = temp;
	}
}
void Wrapper::loadWeeklyPlan(fstream &fileStream, Exercise *weeklyPlan[]) {
	Exercise temp;
	for (int i = 0; i < 7; ++i) {
		loadDailyPlan(fileStream, temp);
		(*weeklyPlan)[i] = temp;
	}
}


//_________________________________________________________
void Wrapper::displayDailyPlan(Diet diet) {
	cout << diet << endl;
}
void Wrapper::displayDailyPlan(Exercise exercise) {
	cout << exercise << endl;
}
void Wrapper::displayDailyName(Diet diet[]) {
	for (int i = 0; i < 7; ++i) {
		cout << i + 1 << "." << diet[i].getdName() << endl;
	}
}
void Wrapper::displayDailyName(Exercise exercise[]) {
	for (int i = 0; i < 7; ++i) {
		cout << i + 1 << "." << exercise[i].geteName() << endl;
	}
}

//_________________________________________________________
void Wrapper::displayWeeklyPlan(Diet diet[]) {
	for (int i = 0; i < 7; ++i) {
		displayDailyPlan(diet[i]);
	}
}
void Wrapper::displayWeeklyPlan(Exercise exercise[]) {
	for (int i = 0; i < 7; ++i) {
		displayDailyPlan(exercise[i]);
	}
}


//_________________________________________________________
void Wrapper::storeDailyPlan(fstream &fileStream, Diet diet) {
	fileStream << diet << endl;
}
void Wrapper::storeDailyPlan(fstream &fileStream, Exercise exercise) {
	fileStream << exercise << endl;
}


//_________________________________________________________
void Wrapper::storeWeeklyPlan(fstream &fileStream, Diet diet[]) {
	fstream dietFile;
	dietFile.open("dietPlans.txt");
	for (int i = 0; i < 7; ++i) {
		storeDailyPlan(dietFile, diet[i]);
	}
	dietFile.close();
}
void Wrapper::storeWeeklyPlan(fstream &fileStream, Exercise exercise[]) {
	fstream exerciseFile;
	exerciseFile.open("exercisePlans.txt");
	exerciseFile.close();
}
int Wrapper::displayMenu() {
	int select = 0;
	cout << "1.    Load weekly diet plan from file.\n2.    Load weekly exercise plan from file.\n3.    Store weekly diet plan to file.\n4.    Store weekly exercise plan to file.\n5.    Display weekly diet plan to screen.\n6.    Display weekly exercise plan to screen.\n7.    Edit daily diet plan.\n8.    Edit daily exercise plan.\n9.    Exit."  << endl;
	cout << "Please Select: " << endl;
	cin >> select;
	return select;

}
