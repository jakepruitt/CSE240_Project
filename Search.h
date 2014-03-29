#ifndef SEARCH_H
#define SEARCH_H

#include "FlightNode.h"

class FlightPlan
{
public:
	FlightPlan();
	~FlightPlan();
	
	FlightNode *path;
};


void searchForCheapest();
void searchForShortest();

#endif