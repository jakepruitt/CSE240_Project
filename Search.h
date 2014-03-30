#ifndef SEARCH_H
#define SEARCH_H

#include "FlightNode.h"
#include "HubNode.h"
#include <string>

class FlightPlan
{
public:

	int bags;
	Date_Time *startTime;
	HubNode *startHub;
	HubNode *endHub;
	FlightNode *path[2];

	float calculateCost(int numBags);
	Date_Time* calculateArrivalTime();
	int calculateDuration();
	void printItinerary();
};

void createFlightPlan(Date_Time* startDate, Date_Time* endDate, string destination, int bags, string cheapOrShort);

void searchForCheapest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth, Date_Time *startDate, Date_Time *endDate, int bags);
void searchForShortest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth, Date_Time *startDate, Date_Time *endDate);

#endif