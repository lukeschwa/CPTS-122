/**********************************************************************************************
* Programmer: Luke Schauble
* Class: CptS 122,lab Section: 4
* Programming Assignment: 1
* Created: January 13th,2019
* Last Revised: January 21st,2019
* Description: Analyses 24 hours of fitbit data and performs calculations on them
*********************************************************************************************/
#include "function.h"
int main(void) {
	FILE *infile = NULL;
	FILE *outfile = NULL;
	infile = fopen("FitbitData.csv", "r");
	outfile = fopen("Results.csv", "w");
	FitbitData record[1442] = { {"\0"} };
	double totalCalories = 0, totalDistance = 0,avarageHeartrate = 0;
	int totalFloors = 0, maxSteps = 0, totalSteps = 0;
	char line[100] = "", *token, poorSleepStart[10], poorSleepEnd[10];
	int missingDataFixed = 0;


	if (infile != NULL) { //file opened succesfully

		fgets(line, 100, infile);//read in the first to lines of the csv file, as we do not need them
		fgets(line, 100, infile);


		for (int i = 0; i < 1442; i++) {
			fgets(line, 100, infile);
			strcpy(record[i].patient, strtok(line, ","));
			char correctPatient = strcmp(record[i].patient, "12cx7"); //compairs the patients ID with the target ID
					if (correctPatient == 0) {
						token = strtok(NULL, ",");
						if (token != NULL) {
							strcpy(record[i].minute, token);
						}
						else {
							missingDataFixed++; //counts the number of times a missing data field has been fixed
						}

						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].calories = atof(token);
							totalCalories += record[i].calories; // finds total calories
						}
						else{
							missingDataFixed++;
						}
						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].distance = atof(token);
							totalDistance += record[i].distance; // finds total distance
						}
						else {
							missingDataFixed++;
						}

						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].floors = atoi(token);
							totalFloors += record[i].floors; //finds total floors
						}
						else {
							missingDataFixed++;
						}

						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].heartRate = atoi(token);
							avarageHeartrate += record[i].heartRate; // finds total heartrate
						}
						else {
							missingDataFixed++;
						}

						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].steps = atoi(token);
							totalSteps += record[i].steps; //finds total steps
							if (record[i].steps > maxSteps) {
								maxSteps = record[i].steps; //finds max steps
							}
						}
						else {
							missingDataFixed++;
						}

						token = strtok(NULL, ",");
						if (token != NULL) {
							record[i].sleepLevel = atoi(token);
						}
						else {
							missingDataFixed++;
						}
						//printf("Patient:%s\nMinute:%s\nCalories:%lf\nDistance:%lf\nFloors:%d\nHeartrate:%d\nSteps:%d\nSleep Level:%d\n\n", record[i].patient, record[i].minute, record[i].calories, record[i].distance, record[i].floors, record[i].heartRate, record[i].steps, record[i].sleepLevel);
					}
		}
		poorSleep(record, poorSleepStart, poorSleepEnd);
		computeAndPrint(totalCalories, totalDistance, totalFloors, totalSteps, avarageHeartrate, maxSteps, poorSleepStart, poorSleepEnd, outfile);
		fprintf(outfile, "Number of missing data fields fixed: %d\n", missingDataFixed);
		for (int i = 0; i < 1442; i++) { //output parsed info to output file (DOES NOT READ ANY LINES WITH PATIENT ID'S OTHER THAN 12cx7 ALTHOUGH THEY SHOW UP IN OUTFILE)
			fprintf(outfile, "%s,%s,%lf,%lf,%d,%d,%d,%d\n", record[i].patient, record[i].minute, record[i].calories, record[i].distance, record[i].floors, record[i].heartRate, record[i].steps, record[i].sleepLevel);
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t---------------------------------------------\n");
		printf("\t\t\t\t\t| Done!, results are found in 'Results.csv' |\n");
		printf("\t\t\t\t\t---------------------------------------------\n\n\n\n\n\n\n\n\n\n\n\n");
		fclose(infile);
		fclose(outfile);

		return 0;
	}
}