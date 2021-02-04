#include "data.h"
#include "queueNode.h"
#include "queue.h"

int main(void) {
	int minutes = 0;
	srand(time(NULL));
	cout << "Run the simulation for(minutes):";
	cin >> minutes;
	Queue expressLane;
	Queue normalLane;
	int expressTime = (rand() % 5) + 1, normalTime = (rand() % 5) + 4, customer = 0, time = 0, expressSum = 0, normalSum = 0;
	Data *expressData = new Data(1, expressTime, 0);
	Data *normalData = new Data(1, normalTime, 0);
	for (time; time < minutes; time++) {

		if (time == expressTime || (time == expressData->getTotalTime() && time != 0)) {
			expressLane.enqueue(*expressData);
			cout << time << "\tExpress\tCustomer #"<< expressData->getCustomerNumber() <<" queued" << endl;
		}
		if (time == normalTime || (time == normalData->getTotalTime() && time != 0)) {
			normalLane.enqueue(*normalData);
			cout << time << "\tNormal\tCustomer #" << expressData->getCustomerNumber() << " queued" << endl;
		}
		if (time == expressData->getTotalTime()) {
			Data dequeue = expressLane.dequeue();
			cout << time << "\tExpress\tCustomer #" << dequeue.getCustomerNumber() << " dequeued" << endl;
			expressData = new Data(expressData->getCustomerNumber() + 1, expressTime, time);
		}
		if (time == normalData->getTotalTime()) {
			Data dequeue = normalLane.dequeue();
			cout << time << "\tNormal\tCustomer #" << dequeue.getCustomerNumber() << " dequeued" << endl;
			expressData = new Data(expressData->getCustomerNumber() + 1, expressTime, time);
		}
		if (time % 10 == 0 && time != 0) {
			cout << "\nExpress Lane: \n" << time << endl << endl;
			expressLane.printQueue();

			cout << "Normal Lane:" << endl << endl;
			normalLane.printQueue();
		}
	}

	return 0;
}