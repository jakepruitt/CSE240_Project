#include "ListCreation.h"
#include "HubNode.h"
#include "FlightNode.h"
#include <string>

void addHub(string airport, string city) {
	HubNode *newHubNode = new HubNode();

	newHubNode->name = airport;
	newHubNode->location = city;
	newHubNode->next = NULL;
	newHubNode->headFlights = NULL;
};

void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName) {
	
};