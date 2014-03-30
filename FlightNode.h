#ifndef FLIGHT_NODE_H
#define FLIGHT_NODE_H

#include <string>
#include "HubNode.h"
#include "Date_Time.h"

using namespace std;

class HubNode;  

class FlightNode{  // May want to consider making some var private
	public:
		string flightNumber;
		double price;
		string flightCompany;
		Date_Time *departure;
		Date_Time *arrival;
		int duration;
		HubNode *source;
		HubNode *destination;
		FlightNode *next;
		virtual float getBaggageFees(int numBags);
		virtual int getDelay();
		virtual ~FlightNode();
};

// Derived Class of FlightNode
class FlightSouthWest : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};

// Derived Class of FlightNode
class FlightDelta : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};

// Derived Class of FlightNode
class FlightUSAirway : virtual public FlightNode{
	public:
		float getBaggageFees(int numBags);
		int getDelay();
};

#endif

