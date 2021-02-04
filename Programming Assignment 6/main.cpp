#include <iostream>
#include "BSTNode.h"
#include "BST.h"
int main() {
	BST tree;
	fstream infile;
	infile.open("Convert.txt", fstream::in);
	string morseValue = "";
	char line[100];
	int selection = 0;
	do {
		while (selection == 0) { //main menu
			cout << "1. Convert from file into morse code\n2. Print morse code conversion table in alphabetical order\n3. Exit" << endl;
			cin >> selection;
		}
		while (selection == 1) { //print from file
			system("cls");
			while (!infile.eof()) {
				infile.getline(line, 100);

				for (int i = 0; i < strlen(line); ++i) {
					line[i] = toupper(line[i]); //converts all lowercase entries to uppercase
					if (line[i] == '\n') { //if the file is at the end of a line, start printing on the next line
						cout << endl;
					}
					else if (line[i] == ' ') {
						cout << "   "; // prints 3 spaces for in between morse words
					}
					else {
						morseValue = tree.search(tree.getRootPtr(), line[i]);
						cout << morseValue << " "; //prints one space in between individual letters
					}

				}
				cout << endl << endl;
				
			}
			system("pause");
			system("cls");
			selection = 0; // back to main menu
		}
		while(selection == 2){//print tree in increasing ascii value order
			system("cls");
			tree.print();
			system("pause");
			system("cls");
			selection = 0; //back to main menu
		}
	} while (selection != 3); // Exit, then destroy the tree
	tree.~BST();
	cout << "tree deleted" << endl;
	return 0;
}