#ifndef HUB_NODE_H
#define HUB_NODE_H 

#include <string>
#include "FlightNode.h"

class HubNode{
	public:
		string name;
		string location;
		HubNode *next;
		FlightNode* headFlights;
};

#endif