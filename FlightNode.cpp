<<<<<<< HEAD
#include "FlightNode.h"
=======
#include <iostream>

using namespace std;

class FlightNode{
	public:
		string flightNumber;
		double price;
		string flightCompany;
		Date_Time departure;
		int duration;
		HubNode* source;
		HubNode* destination;
		FlightNode *next;
		
		virtual float getBaggageFees()
		{
			
		}
		
		virtual int getDelay()
		{
			
		}
};

class FlightSouthWest{
	public:
		float getBaggageFees()
		{
			
		}
};

class FlightUSAirway{
	public:
		float getBaggageFees()
		{
			
		}
};

class FlightDelta{
	public:
		float getBaggageFees()
		{
			
		}
};
>>>>>>> 2b33974027473240f198a78304556a9b91eeb648
