#ifndef FLIGHT_NODE_H
#define FLIGHT_NODE_H

#include <string>
#include "HubNode.h"
#include "Date_Time.h"

using namespace std;

class HubNode;

class FlightNode{
	public:
		string flightNumber;
		double price;
		string flightCompany;
		Date_Time departure;
		int duration;
		HubNode *source;
		HubNode *destination;
		FlightNode *next;
		virtual float getBaggageFees(int numBags);
		virtual int getDelay();
};

class FlightSouthWest : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};

class FlightDelta : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};

class FlightUSAirway : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};


#endif
