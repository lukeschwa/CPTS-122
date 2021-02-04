#include "function.h"
/**********************************************************************************************
* Programmer: Luke Schauble
* Class: CptS 122,lab Section: 4
* Programming Assignment: 2
* Created: January 31th,2019
* Last Revised: Febuary 8th,2019
* Description: Does various functions revolving around music, a music manager
*********************************************************************************************/
int main(void) {
	int masterValue = 0, select = 0;
	Node *pHead = (Node *)malloc(sizeof(Node));
	FILE *outfile = NULL;
	outfile = fopen("writeData.csv", "w");

	

	initList(&pHead);

	do {
		while (masterValue == 0) {
			printf("(1)   load\n(2)   store\n(3)   display\n(4)   insert\n(5)   delete\n(6)   edit\n(7)   sort\n(8)   rate\n(9)   play\n(10) shuffle\n(11) exit\n");
			printf("Please select an option: ");
			scanf("%d", &select);
			system("cls");
			masterValue = menuSelect(select);
		}
		while (masterValue == 1) {
			initList(&pHead);
			loadFromFile(&pHead);
			printf("Songs have been loaded.");
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 2) {
			if (outfile == NULL) {
				printf("Could not open file");
			}
			else {
			storeToFile(pHead, outfile);
		    }
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 3) {
			int select;
			printf("Would you like to:\n1.Print all records\n2.Search for records");
			scanf("%d", &select);
			if (select == 1) {
			printListOptOne(pHead);
			}
			else {
				printListOptTwo(&pHead);
			}
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 4) {
			insertNewRecord(&pHead);
			system("pause");
			system("cls");
			masterValue = 0;
			
		}
		while (masterValue == 5) {
			deleteRecord(&pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 6) {
			editRecord(&pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 7) {
			sortRecord(pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 8) {
			rateRecord(&pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 9) {
			playSong(pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 10) {
			shuffle(pHead);
			system("pause");
			system("cls");
			masterValue = 0;
		}
		while (masterValue == 11) {
			printf("Goodbye\n");
			system("pause");
			masterValue = -3;
		}










	} while (masterValue > -2);

	return 0;
}