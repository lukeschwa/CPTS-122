#include "function.h"
/**********************************************************************************************
* Function: menuSelec
* Last Revised: Febuary 8th,2019
* Inputs: selection
* Outputs: mv
* Description: determains what the user wants to do
*********************************************************************************************/
int menuSelect(int selection){
	int mv = 0;
	if (selection == 1) {
		mv = 1;
	}
	else if (selection == 2) {
		mv = 2;
	}
	else if (selection == 3) {
		mv = 3;
	}
	else if (selection == 4) {
		mv = 4;
	}
	else if (selection == 5) {
		mv = 5;
	}
	else if (selection == 6) {
		mv = 6;
	}
	else if (selection == 7) {
		mv = 7;
	}
	else if (selection == 8) {
		mv = 8;
	}
	else if (selection == 9) {
		mv = 9;
	}
	else if (selection == 10) {
		mv = 10;
	}
	else if (selection == 11) {
		mv = 11;
	}
	else {
		mv = 0;
	}
	return mv;
}

/**********************************************************************************************
* Function: initList
* Last Revised: Febuary 1st,2019
* Inputs: **pList
* Outputs: none
* Description: initializes the list
*********************************************************************************************/
void initList(Node **pList){
	*pList = NULL;
}

/**********************************************************************************************
* Function: makeNode
* Last Revised: Febuary 1st,2019
* Inputs: newData
* Outputs: pMem
* Description: makes a new node
*********************************************************************************************/
Node *makeNode(Record newData) {
	Node *pMem = NULL;
	Record *pRec = NULL;
	(Record *)malloc(sizeof(Record));
	pMem = (Node *)malloc(sizeof(Node));


	if (pMem != NULL) {
		//allocating data for the size of a char times how many chars there are in the given string
		pMem->data.artist = (char *)malloc((strlen(newData.artist) + 1) * sizeof(char));
		strcpy(pMem->data.artist, newData.artist);

		pMem->data.album = (char *)malloc((strlen(newData.album) + 1) * sizeof(char));
		strcpy(pMem->data.album, newData.album);

		pMem->data.song = (char *)malloc((strlen(newData.song) + 1) * sizeof(char));
		strcpy(pMem->data.song, newData.song);

		pMem->data.genre = (char *)malloc((strlen(newData.artist) + 1) * sizeof(char));
		strcpy(pMem->data.genre, newData.genre);
		//dont have to go through that procsess with variables other than strings
		pMem->data.length.minute = newData.length.minute;
		pMem->data.length.second = newData.length.second;
		pMem->data.notp = newData.notp;
		pMem->data.rating = newData.rating;
		pMem->pNext = NULL;
		pMem->pPrev = NULL;

	}
	return pMem;
}

/**********************************************************************************************
* Function: loadFromFile
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description: loads data from file
*********************************************************************************************/
void loadFromFile(Node **pHead) {
	FILE *infile = NULL;
	infile = fopen("musicPlayList.csv", "r");
	Record details = { "","","","",{ -1,-1 },-1,-1 };
	char line[100] = "";

	if (infile != NULL) {

		while (fgets(line, 100, infile) != NULL) {//changed artists names with commas in them as they mess up strtok, i believe this is fine, assignment sheet said it was a sample .csv
			details.artist = strtok(line, "|"); //changed delim in file because '|' helped me visualize it better by more drastic seperation
			details.album = strtok(NULL, "|");
			details.song = strtok(NULL, "|");
			details.genre = strtok(NULL, "|");
			details.length.minute = atoi(strtok(NULL, ":"));
			details.length.second = atoi(strtok(NULL, "|"));
			details.notp = atoi(strtok(NULL, "|"));
			details.rating = atoi(strtok(NULL, "|"));
			insertAtFront(&*pHead, details);
		}
	}
	fclose(infile);
}

/**********************************************************************************************
* Function: insertAtFront
* Last Revised: Febuary 1st,2019
* Inputs: **pList, newItem
* Outputs: success
* Description: adds nodes to the front of list
*********************************************************************************************/
int insertAtFront(Node **pList, Record newItem) {
	Node *pMem = NULL;
	int success = 0;
	pMem = makeNode(newItem);

	if (pMem != NULL) {
		success = 1;
		pMem->pNext = *pList;
		if (!isEmpty(*pList)) {
			(*pList)->pPrev = pMem;
		}
		*pList = pMem;
	}
	return success;
}


int isEmpty(Node *pList){
	return (pList == NULL);
}
/**********************************************************************************************
* Function: printListOptOne
* Last Revised: Febuary 1st,2019
* Inputs: *Head
* Outputs: none
* Description: prints all the records
*********************************************************************************************/
void printListOptOne(Node *pHead) {
	if (pHead != NULL) {

		printf(">Song:%s, Artist:%s, Album: %s, Genre: %s, Length: %d:%d, Plays: %d, Rating: %d\n\n", pHead->data.song, pHead->data.artist, pHead->data.album, pHead->data.genre, pHead->data.length.minute, pHead->data.length.second, pHead->data.notp, pHead->data.rating);
		printListOptOne(pHead->pNext);
	}
}
/**********************************************************************************************
* Function: printListOptTwo
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description: prints a user selected record
*********************************************************************************************/
void printListOptTwo(Node **pHead) {
	Node *pCur = *pHead;
	char song[30] = "";
	printf("Enter the name of the song you would like to edit:");
	scanf(" %[^\n]s", &song);
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->data.song, song) == 0) {
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}
	system("cls");
	printf("\nSong:%s \n Artist:%s \n Album: %s \n Genre: %s \n Length: %d:%d \n Plays: %d \n Rating: %d\n\n", pCur->data.song, pCur->data.artist, pCur->data.album, pCur->data.genre, pCur->data.length.minute, pCur->data.length.second, pCur->data.notp, pCur->data.rating);
}
/**********************************************************************************************
* Function: storeToFile
* Last Revised: Febuary 1st,2019
* Inputs: *pHead, *file
* Outputs: none
* Description:  prints all records to a file
*********************************************************************************************/
void storeToFile(Node *pHead, FILE *file) {//-->  -->  -->  -->  --> YOU MUST SELECT EXIT ON THE MENU FOR THIS FUNCTION TO WORK <---  <---  <---  <---  <---
		while (pHead->pNext != NULL) {
			fprintf(file, "%s |", pHead->data.artist);
			fprintf(file, "%s |", pHead->data.album);
			fprintf(file, "%s |", pHead->data.song);
			fprintf(file, "%s |", pHead->data.genre);
			fprintf(file, "%d :", pHead->data.length.minute);
			fprintf(file, "%d |", pHead->data.length.second);
			fprintf(file, "%d |", pHead->data.notp);
			fprintf(file, "%d\n", pHead->data.rating);
			pHead = pHead->pNext;
			if (pHead->pNext == NULL) {
				fprintf(file, "%s |", pHead->data.artist);
				fprintf(file, "%s |", pHead->data.album);
				fprintf(file, "%s |", pHead->data.song);
				fprintf(file, "%s |", pHead->data.genre);
				fprintf(file, "%d :", pHead->data.length.minute);
				fprintf(file, "%d |", pHead->data.length.second);
				fprintf(file, "%d |", pHead->data.notp);
				fprintf(file, "%d\n", pHead->data.rating);
			}
	  }	
		system("cls");
		printf("Done");
}
/**********************************************************************************************
* Function: insertNewRecord
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description:  inserts a new record into the linked list
*********************************************************************************************/
void insertNewRecord(Node **pHead) {
	Record songInfo = { "","","","",{-1,-1},-1,-1 };
	Node *pMem;
	pMem = makeNode(songInfo);
	printf("Artist: ");
	scanf("%s", pMem->data.artist);
	printf("\nAlbum: ");
	scanf("%s", pMem->data.album);
	printf("\nSong: ");
	scanf("%s", pMem->data.song);
	printf("\nGenre:");
	scanf("%s", pMem->data.genre);
	printf("\nLength:\nMinutes: ");
	scanf("%d", &pMem->data.length.minute);
	printf("Seconds:");
	scanf("%d", &pMem->data.length.second);
	printf("\nTotal plays: ");
	scanf("%d", &pMem->data.notp);
	printf("\nRating (1-5): ");
	scanf("%d", &pMem->data.rating);
	pMem->pNext = *pHead;
	pMem->pPrev = NULL;
	*pHead = pMem;
	
}
/**********************************************************************************************
* Function: deleteRecord
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description:  deletes a record from the linked list
*********************************************************************************************/
//I CANT FIND WHERE I GOT IT FROM BUT "%[^\n]s" WAS FOUND ON STACK OVERFLOW
void deleteRecord(Node **pHead) {
	Node *pCur = *pHead;
	char song[30] = "";
	printf("Enter the name of the song you would like to delete:");
	scanf(" %[^\n]s", &song);
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->data.song, song) == 0) {
			pCur->pPrev->pNext = pCur->pNext;
			pCur->pNext->pPrev = pCur->pPrev;
			system("cls");
			printf("The song '%s' was deleted\n", song);
			free(pCur);
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}
	if (pCur->pNext == NULL) {
		printf("Song not found\n");
	}
}
/**********************************************************************************************
* Function: editRecord
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description:  edits records in the linked list
*********************************************************************************************/
void editRecord(Node **pHead) {
	Node *pCur = *pHead;
	char song[30] = "",strEdit[30]= "";
	int artist = 1, album = 2, songEdit = 3, genre = 4, length = 5, notp = 6, rating = 7, intEdit = 0,intEdit2=0;
	int edit = 0;
	printf("Enter the name of the song you would like to edit:");
	scanf(" %[^\n]s", &song);
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->data.song, song) == 0) {
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}
	if (pCur->pNext == NULL) {
		printf("Song not found");
	}
	else {
		printf("\nWhat would you like to edit about '%s'\n", song);
		printf("1. Artist\n2. Album\n3. Song name\n4. Genre\n5. Length\n6. plays\n7. rating\n");
		scanf("%d", &edit);
		system("cls");
		if (edit == 1) {
			printf("What would you like the artist name to be:");
			scanf(" %[^\n]s", pCur->data.artist);
			printf("Done");
		}
		else if (edit == 2) {
			printf("What would you like the Album name to be:");
			scanf(" %[^\n]s", pCur->data.album);
			printf("Done");
		}
		else if (edit == 3) {
			printf("What would you like the Song name to be:");
			scanf(" %[^\n]s", pCur->data.song);
			printf("Done");
		}
		else if (edit == 4) {
			printf("What would you like the Genre name to be:");
			scanf(" %[^\n]s", pCur->data.genre);
			printf("Done");
		}
		else if (edit == 5) {
			printf("What would you like the length to be:\n");
			printf("Minutes: ");
			scanf("%d", &pCur->data.length.minute);
			printf("\nSeconds: ");
			scanf("%d", &pCur->data.length.second);
			printf("\nDone");
		}
		else if (edit == 6) {
			printf("How many times have you played this song:");
			scanf("%d", &pCur->data.notp);
			printf("Done");
		}
		else if (edit == 7) {
			printf("Give this song a new rating:");
			scanf("%d", &pCur->data.rating);
			printf("Done\n");
		}
	}
}
/**********************************************************************************************
* Function: sortRecord
* Last Revised: Febuary 1st,2019
* Inputs: *pHead
* Outputs: none
* Description:  dsorts the records in the linked list by user specified type
*********************************************************************************************/
void sortRecord(Node *pHead) {
	Node *pCur = { "" }, *pPrev = NULL;
	int selectSortMethod = 0, intOrStr = 0, success = 0;
	printf("How would you like to sort your music:\n1.Artist(A-Z)\n2.Album(A-Z)\n3.Rating\n4.Times played");
	scanf("%d", &selectSortMethod);
	//Select Sort Method
	if (selectSortMethod == 1) { //ARTIST
		if (pCur == NULL) {
			printf("No Records to sort, please add or load records.\n");
			return;
		}
		do {
			pCur = pHead;
			success = 0;
			while (pCur->pNext != pPrev) {
				if (strcmp(pCur->data.artist, pCur->pNext->data.artist) > 0) {
					swapRecords(pCur, pCur->pNext); //swap data to Node with artist that is in order
					success = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;

		} while (success);
	}

	else if(selectSortMethod == 2) { //ALBUM
		if (pCur == NULL) {
			printf("No Records to sort, please add or load records.");
			return;
		}
		do {
			pCur = pHead;
			success = 0;
			while (pCur->pNext != pPrev) {
				if (strcmp(pCur->data.album, pCur->pNext->data.album) > 0) {
					swapRecords(pCur, pCur->pNext);
					success = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;

		} while (success);
	}
	else if (selectSortMethod == 3) { //RATING

		if (pCur == NULL) {
			printf("No Records to sort, please add or load records.");
			return;
		}
		do {
			pCur = pHead;
			success = 0;
			while (pCur->pNext != pPrev) {
				if (pCur->data.rating < pCur->pNext->data.rating) {
					swapRecords(pCur, pCur->pNext);
					success = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;

		} while (success);
	}

	else if (selectSortMethod == 4) { //NUMBER OF TIMES PLAYED
		if (pCur == NULL) {
			printf("No Records to sort, please add or load records.");
			return;
		}
		do {
			pCur = pHead;
			success = 0;
			while (pCur->pNext != pPrev) {
				if (pCur->data.notp < pCur->pNext->data.notp) {
					swapRecords(pCur, pCur->pNext);
					success = 1;
				}
				pCur = pCur->pNext;
			}
			pPrev = pCur;

		} while (success);
	}
	else {
		printf("Not a valid input");
	}
	system("cls");
	printf("\nRecords have been sorted\n");

}
//part of sort function
void swapRecords(Node *pRecA, Node *pRecB) {
	Record swap;
	swap = pRecA->data;
	pRecA->data = pRecB->data;
	pRecB->data = swap;
}
/**********************************************************************************************
* Function: rateRecord
* Last Revised: Febuary 1st,2019
* Inputs: **pHead
* Outputs: none
* Description:  allows the user to rate a record
*********************************************************************************************/
void rateRecord(Node **pHead) {
	char song[30] = "";
	Node *pCur = *pHead;
	printf("Enter the name of the song you would like to edit:");
	scanf(" %[^\n]s", &song);
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->data.song, song) == 0) {
			break;
		}
		else {
			pCur = pCur->pNext;
		}
	}
	printf("Give this song a new rating:");
	scanf("%d", &pCur->data.rating);
	printf("Done");
}
/**********************************************************************************************
* Function: playRecord
* Last Revised: Febuary 1st,2019
* Inputs: *pHead
* Outputs: none
* Description:  plays all the songs till the end of the linked list starting with the one the user selects
*********************************************************************************************/
void playSong(Node *pHead) {
	int count = 0;
	Node *pCur = pHead;
	char song[30];
	printf("\nWhich song would you like to play:");
	scanf(" %[^\n]s", song);
	while (pCur->pNext != NULL) {
		if (strcmp(pCur->data.song, song) == 0) {
			count = 1;
			break;
			
		}
		else {
			pCur = pCur->pNext;
		}
	}
	while (pCur != NULL) {
		if (count == 1) {
			system("cls");
		}
		printf("NOW PLAYING");
		printf("\nSong:%s \n Artist:%s \n Album: %s \n Genre: %s \n Length: %d:%d \n Plays: %d \n Rating: %d\n\n", pCur->data.song, pCur->data.artist, pCur->data.album, pCur->data.genre, pCur->data.length.minute, pCur->data.length.second, pCur->data.notp, pCur->data.rating);	
		Sleep(1 * 1000);
		system("cls");
		pCur = pCur->pNext;
	}
}
/**********************************************************************************************
* Function: shuffle
* Last Revised: Febuary 1st,2019
* Inputs: *pHead
* Outputs: none
* Description:  shuffles the records then plays them in a random order
*********************************************************************************************/
void shuffle(Node *pHead) {
	Node *pCur = pHead, *pMem = pHead;
	int length = 0, *pPlay = NULL, index = 0, curIndex = 0;
	srand((unsigned)time(NULL));
	for (length = 0; pCur != NULL; length++) {
		pCur = pCur->pNext;
	}
	pPlay = malloc(sizeof(int) * length);

	for (index = 0; index < length; index++) {
		pPlay[index] = index;
	}
	for (index = 0; index < length; index++) {
		int temp = pPlay[index], random = rand() % (index + 1);
		pPlay[index] = pPlay[random];
		pPlay[random] = temp;
	}
	for (index = 0; index < length; index++) {
		while (curIndex != pPlay[index]) {
			if (curIndex < pPlay[index]) {
				curIndex++;
				pMem = pMem->pNext;
			}
			else {
				curIndex--;
				pMem = pMem->pPrev;
			}
		}
		playSong(pMem);
		Sleep(5000);
		system("cls");
	}
}

