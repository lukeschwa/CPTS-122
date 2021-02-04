#include "function.h"

/**********************************************************************************************
* Function: computeAndPrint
* Last Revised: January 21st,2019
* Inputs: calories, distance, floors, totalSteps, aveHeartrate, maxSteps, *sleepStart, *sleepEnd, Outfile
* Outputs: none
* Description: computes avarage heartrate and prints them to the outfile
*********************************************************************************************/
double computeAndPrint(double calories, double distance, int floors, int totalSteps, double aveHeartrate, int maxSteps,char *sleepStart, char *sleepEnd, FILE *outfile) {
	double avarageHeart = aveHeartrate / 1440;
	fprintf(outfile, "Total Calories,Total Distance,Total Floors,Total Steps,Avg Heartrate,Max Steps, Poor Sleep Range:\n");
	fprintf(outfile, "%lf, %lf, %d, %d, %lf, %d, %s : %s\n\n", calories, distance, floors, totalSteps, avarageHeart, maxSteps,sleepStart,sleepEnd);

}


/**********************************************************************************************
* Function: poorSleep
* Last Revised: January 21st,2019
* Inputs: sleep[], *startTime, *endTime
* Outputs: maxRange
* Description: computes the longest period of time with sleep value above 1(bad sleep)
*********************************************************************************************/
unsigned int poorSleep(FitbitData sleep[], char *startTime, char *endTime) {
	unsigned lastIndex = 0, rangeStart = 0, rangeEnd = 0,rangeSum = 0,rangeMax = 0;
	int i = 0;
	for (i = 0; i < 1442; i++) {
		if (sleep[i].sleepLevel > 1) { //indicates poor sleep
			if ((lastIndex + 1) != i) {
				rangeSum = 0;//sleep levels are not consecutive sum of ranges goes back to 0
				rangeStart = i;//sets start of range to next index to continue through the data

			}
			rangeSum += sleep[i].sleepLevel; //adds the amount of consecutive times poor sleep occured
			
			if (rangeSum > rangeMax) { // if the current amount of times poor sleep occured is greater than the the previous max time poor sleep occured, this current time is the max
				rangeMax = rangeSum;
				rangeEnd = i;
			}
			lastIndex = i;
		}
	}
	if (rangeEnd < rangeStart) { //checks to make sure the beginning and end of poor sleep are not the same
		rangeStart = rangeEnd;
	}
	strcpy(startTime, sleep[rangeStart].minute);
	strcpy(endTime, sleep[rangeEnd].minute);
	
	return rangeMax;

}