#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include <string>
#include "HubNode.h"
#include "FlightNode.h"

	HubNode* searchHub(std::string hub_name, HubNode *hub);
	void deallocateHubs(HubNode *head);
	void deallocateFlights(FlightNode *head);
	void printFlights(HubNode *hub);
#endif