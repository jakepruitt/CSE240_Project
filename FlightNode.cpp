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
		FlightHub *next;

		virtual float getBaggageFees()
		{

		}

		virtual int getDelay()
		{

		}
};

class FlightSouthWest : virtual public FlightNode{
	public:
		float getBaggageFees()
		{

		}
};

class FlightUSAirway : virtual public FlightNode{
	public:
		float getBaggageFees()
		{

		}
};

class FlightDelta : virtual public FlightNode{
	public:
		float getBaggageFees()
		{

		}
};
>>>>>>> 520d43a90db9e97deb35161793ce6066f7c2dfc7
