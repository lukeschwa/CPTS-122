#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct length {
	int minute;
	int second;

}Length;

typedef struct record {
	char *artist;
	char *album;
	char *song;
	char *genre;
	Length length;
	int notp;
	int rating;

}Record;
typedef struct node {
	Record data;
	struct node *pNext;
	struct node *pPrev;
}Node;
int menuSelect(int selection);
void initList(Node **pList);
Node *makeNode(Record newItem);
void loadFromFile(Node **pHead);
int insertAtFront(Node **pList, Record newItem);
int isEmpty(Node *pList);
void printListOptOne(Node *pHead);
void storeToFile(Node *pHead, FILE *file);
void insertNewRecord(Node **pHead);
void deleteRecord(Node **pHead);
void editRecord(Node **pHead);
void swapRecords(Node *pRecA, Node *pRecB);
void rateRecord(Node **pHead);
void sortRecord(Node *pHead);
void playSong(Node *pHead);
void shuffle(Node *pHead);
void printListOptTwo(Node **pHead);



