#include <iostream>

using namespace std;

class HubNode{
	public:
		string name;
		string location;
		HubNode* next;
		FlightNode* headFlights;
};
