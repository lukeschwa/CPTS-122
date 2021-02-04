#include "data.h"
Data::Data() {
	customerNumber = -1;
	serviceTime = -1;
	totalTime = -1;
}
Data::Data(const Data &temp) {
	customerNumber = temp.getCustomerNumber();
	serviceTime = temp.getServiceTime();
	totalTime = temp.getTotalTime();
}
Data::Data(int customerNum, int service, int time) {
	customerNumber = customerNum;
	serviceTime = service;
	totalTime = serviceTime + time;
}
Data::Data(int customer, int service) {

}
Data::~Data() {

}
int Data::getCustomerNumber()const {
	return customerNumber;
}
int Data::getServiceTime()const {
	return serviceTime;
}
int Data::getTotalTime()const {
	return totalTime;
}
void Data::setCustomerNumber(int num) {
	customerNumber = num;
}
void Data::setServiceTime(int num) {
	serviceTime = num;
}
void Data::setTotalTime(int num) {
	totalTime = num;
}