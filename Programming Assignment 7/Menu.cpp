#include "Menu.h"
Menu::Menu() {
	masterValue = 0;
}
void Menu::runMenu(List **pList) {
	do {
		while (masterValue == 0) {
			cout << "1.    Import course list" << endl;
			cout << "2.    Load master list" << endl;
			cout << "3.    Store master list" << endl;
			cout << "4.    Mark absences" << endl;
			cout << "5.    Edit absences" << endl;
			cout << "6.    Generate report" << endl;
			cout << "7.    Exit" << endl;
			cout << "Please input a selection:";
			cin >> masterValue;
		}

		//import course List
		while (masterValue == 1) {
			List *pMem = *pList;
			Data tempData = {};
			ifstream infile("classList.csv");
			string line,data;
			getline(infile, line, '\n');
			while (getline(infile, line, '\n')) {

				for (int index = 0; index <= 7; index++) {

					getline(infile, line, '|');

					switch (index) {
					case 0:
						tempData.RN = atoi(data.c_str());
						break;
					case 1:
						tempData.ID = atoi(data.c_str());
						break;
					case 2:
						tempData.name = data;
						break;
					case 3:
						tempData.email = data;
						break;
					case 4:
						if (data == "AU") {
							tempData.units = 000;
						}
						else {
							tempData.units = atoi(data.c_str());
						}
						break;
					case 5:
						tempData.major = data;
						break;
					case 6:
						tempData.YIS = data;
						break;

					}

				}
				Node *nodeToInsert = new Node(tempData);
				pMem->insert(nodeToInsert);
			}
			*pList = pMem;
		}
		//Load Master List
		while (masterValue == 2) {
			List *pMem = *pList;
			Data tempData = {};
			ifstream infile("master.txt");
			string line, data,dateOfAbs;
			getline(infile, line, '\n');
			while (getline(infile, line, '\n')) {

				for (int index = 0; index <= 7; index++) {

					getline(infile, line, '|');

					switch (index) {
					case 0:
						tempData.RN = atoi(data.c_str());
						break;
					case 1:
						tempData.ID = atoi(data.c_str());
						break;
					case 2:
						tempData.name = data;
						break;
					case 3:
						tempData.email = data;
						break;
					case 4:
						if (data == "AU") {
							tempData.units = 000;
						}
						else {
							tempData.units = atoi(data.c_str());
						}
						break;
					case 5:
						tempData.major = data;
						break;
					case 6:
						tempData.YIS = data;
						break;
					case 7:
						tempData.abs = 0;
						break;
					case 8:
						istringstream absStr(data);

						while (getline(absStr, dateOfAbs, '|')) {
							tempData.dateAbs.push(dateOfAbs);
						}
					}

				}
				Node *nodeToInsert = new Node(tempData);
				pMem->insert(nodeToInsert);
			}
			*pList = pMem;
		}
		while (masterValue == 3) {
			List *pMem = *pList;
			Node *tNode = pMem->getHeadPtr();
			ofstream outfile;
			outfile.open("Text.txt");
			
			
		}
		while (masterValue == 4) {
			List *pMem = *pList;
			Node *tNode = pMem->getHeadPtr();
			char absYN;
			if (tNode != nullptr) {
				cout << tNode->getName() << "->Absent?(Y/N):";
				cin >> absYN;
			}
			if (absYN == 'Y' || absYN == 'y') {
				tNode->setDateAbs();
				cout << "\n" << tNode->getName() << " absent" << endl;
			}
		}
		while (masterValue == 5) {

		}
		while (masterValue == 6) {

		}
		while (masterValue == 7) {

		}




	} while (masterValue != -1);
}