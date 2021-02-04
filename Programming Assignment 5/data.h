#pragma once
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
class Data
{
public: 
	Data();
	Data(const Data &temp);
	Data(int customerNum, int service, int time);
	Data(int customer, int service);
	~Data();
	int getCustomerNumber() const;
	int getServiceTime() const;
	int getTotalTime()const;
	void setCustomerNumber(int num);
	void setServiceTime(int num);
	void setTotalTime(int num);

private:
	int customerNumber; 
	int serviceTime;   
	int totalTime;     
}; 