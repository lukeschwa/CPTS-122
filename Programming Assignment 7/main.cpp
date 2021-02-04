#include "Menu.h"

int main(void) {
	Menu run = Menu();	
	List *pList = new List;
	pList->setHeadPtr(nullptr);

	run.runMenu(&pList);



	delete pList;

	return 0;
}