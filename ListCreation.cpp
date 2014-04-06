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
	newHubNode->next = headHub;
	headHub = newHubNode;
	
};

// Inserts flight into LinkedList based on string parameters for Flight attributes
void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName, string company) {
	
	FlightNode *newFlightNode;					
	if (company.compare("USAirway") == 0) {
		newFlightNode = new FlightUSAirway();	// Inhertiance
	} else if (company.compare("Delta") == 0) {
		newFlightNode = new FlightDelta();		// Inhertiance 
	} else {
		newFlightNode = new FlightSouthWest();	// Inhertiance 
	}
	

	Date_Time *departureTime = new Date_Time(departure);		// create pointer to date_time class and use the ptr to access the date and time values
	Date_Time *arrivalTime = new Date_Time(departure);
	HubNode* sourceHub = searchHub(sourceAirportName, headHub);  
	HubNode* destinationHub = searchHub(destinationAirportName, headHub);  

	newFlightNode->flightCompany = company;
	newFlightNode->flightNumber = FlightNumber;
	newFlightNode->price = price;
	newFlightNode->departure = departureTime; 
	newFlightNode->departure->AddMinutes(newFlightNode->getDelay());
	newFlightNode->duration = duration;
	newFlightNode->source = sourceHub;
	newFlightNode->destination = destinationHub;
	arrivalTime->AddMinutes(duration + newFlightNode->getDelay());
	newFlightNode->arrival = arrivalTime;

	// Insert new flight node into linked list
	newFlightNode->next = sourceHub->headFlights;
	sourceHub->headFlights = newFlightNode;

};