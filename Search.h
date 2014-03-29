#ifndef SEARCH_H
#define SEARCH_H

#include "FlightNode.h"
#include "HubNode.h"
#include <string>

class FlightPlan
{
public:

	int bags;
	Date_Time startTime;
	HubNode *startHub;
	HubNode *endHub;
	FlightNode *path[2];

	float calculateCost();
	float calculateArrivalTime();
	float calculateDuration();
	void printItinerary();
};

void flightSearchController(Date_Time* startDate, Date_Time* endDate, string destination, int bags, string cheapOrShort);

void searchForCheapest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth);
void searchForShortest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth);

#endif