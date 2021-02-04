#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char patient[10];
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

double computeAndPrint(double calories, double distance, int floors, int totalSteps, double aveHeartrate, int maxSteps, char *sleepStart, char *sleepEnd, FILE *outfile);
unsigned int poorSleep(FitbitData sleep[], char *startTime, char *endTime);

