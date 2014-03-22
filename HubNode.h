#ifndef HUB_NODE_H
#define HUB_NODE_H 

#include <string>
#include "FlightNode.h"

using namespace std;

class FlightNode;

class HubNode{
	public:
		string name;
		string location;
		HubNode *next;
		FlightNode* headFlights;
		virtual ~HubNode();
};

extern HubNode *headHub;

#endif