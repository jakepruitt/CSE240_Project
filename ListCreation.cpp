#include "ListCreation.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Date_Time.h"
#include "Traversal.h"
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
	if (headHub == NULL) {
		headHub = newHubNode;
	} else {
		newHubNode->next = headHub->next;
		headHub->next = newHubNode;
	}
};

// Inserts flight into LinkedList based on string parameters for Flight attributes
void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName, string company) {
	FlightNode *newFlightNode;
	if (company.compare("USAirway") == 0) {
		newFlightNode = new FlightUSAirway();
	} else if (company.compare("Delta") == 0) {
		newFlightNode = new FlightDelta();
	} else {
		newFlightNode = new FlightSouthWest();
	}
	string flightCompany = company;

	Date_Time departureTime = Date_Time(departure);
	HubNode* sourceHub = searchHub(sourceAirportName, headHub);
	HubNode* destinationHub = searchHub(destinationAirportName, headHub);

	newFlightNode->flightNumber = FlightNumber;
	newFlightNode->price = price;
	newFlightNode->departure = departureTime;
	newFlightNode->duration = duration;
	newFlightNode->source = sourceHub;
	newFlightNode->destination = destinationHub;

	if (sourceHub->headFlights == NULL) {
		sourceHub->headFlights = newFlightNode;
	} else {
		newFlightNode->next = sourceHub->headFlights;
		sourceHub->headFlights = newFlightNode;
	}
};