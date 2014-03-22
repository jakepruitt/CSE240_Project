#include "ListCreation.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Date_Time.h"
#include <string>

using namespace std;

// Inserts hub into LinkedList based on string parameters for Hub attributes
void addHub(string airport, string city) {
	HubNode *newHubNode = new HubNode();

	// Use arguements to create new HubNode
	newHubNode->name = airport;
	newHubNode->location = city;
	newHubNode->next = NULL;
	newHubNode->headFlights = NULL;

	// Insert new HubNode into linkedlist
	newHubNode->next = headHub->next;
	headHub->next = newHubNode;
};

// Inserts flight into LinkedList based on string parameters for Flight attributes
void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName, string company) {
	FlightNode *newFlightNode = new FlightNode();
	string flightCompany = company;

	/*string companyInitials = FlightNumber.substr(0,2);
	switch (companyInitials) {
		case 'UA':
			flightCompany = "United Airlines";
		case 'SW':
			flightCompany = "Southwest";
		case 'AA':
			flightCompany = "American Airlines";
		default:
			flightCompany = "";
	}*/


	Date_Time departure = Date_Time(departure);
	HubNode* sourceHub = findHub(sourceAirportName);
	HubNode* destinationHub = findHub(destinationAirportName);

	newFlightNode->flightNumber = FlightNumber;
	newFlightNode->price = price;
	newFlightNode->departure = departure;
	newFlightNode->duration = duration;
	newFlightNode->source = sourceHub;
	newFlightNode->destination = destinationHub;

	newFlightNode->next = sourceHub->headFlights;
	sourceHub->headFlights = newFlightNode;
};