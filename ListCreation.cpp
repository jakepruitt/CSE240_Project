#include "ListCreation.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Date_Time.h"
#include "Traversal.h"
#include <string>

using namespace std;

// Inserts hub into LinkedList based on string parameters for Hub attributes
void addHub(string airport, string city) {
	
	HubNode *newHubNode = new HubNode();  //NOTE!: We do not have a construtor!

	// Use arguements to create new HubNode
	newHubNode->name = airport;
	newHubNode->location = city;
	newHubNode->next = NULL;
	newHubNode->headFlights = NULL;

	// Insert new HubNode into linkedlist 
	if (headHub == NULL) {
		headHub = newHubNode;				
	} else {
		newHubNode->next = headHub;
		headHub = newHubNode;
	}

	// Insert new HubNode into linkedlist
	//if (headHub == NULL) {
	//	headHub = newHubNode;				
	//} else {
	//	newHubNode->next = headHub->next;	// headHub is a pointer (i.e. an address) and does not have a next
	//	headHub->next = newHubNode;			
	//}

};

// Inserts flight into LinkedList based on string parameters for Flight attributes
void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName, string company) {
	
	FlightNode *newFlightNode;					// Ptr to base class
	if (company.compare("USAirway") == 0) {
		newFlightNode = new FlightUSAirway();	// Inhertiance - We do not have a constructor
	} else if (company.compare("Delta") == 0) {
		newFlightNode = new FlightDelta();		// Inhertiance - We do not have a constructor
	} else {
		newFlightNode = new FlightSouthWest();	// Inhertiance - We do not have a  constructor
	}
	

	Date_Time *departureTime = new Date_Time(departure);		// create pointer to date_time class and use the ptr to access the date and time values
	Date_Time *arrivalTime = new Date_Time(departure);
	HubNode* sourceHub = searchHub(sourceAirportName, headHub);  // fixed searchHub error (see function for more details)
	HubNode* destinationHub = searchHub(destinationAirportName, headHub);  // see above 

	newFlightNode->flightCompany = company;
	newFlightNode->flightNumber = FlightNumber;
	newFlightNode->price = price;
	newFlightNode->departure = departureTime;  //now a ptr
	newFlightNode->duration = duration;
	newFlightNode->source = sourceHub;
	newFlightNode->destination = destinationHub;
	arrivalTime->AddMinutes(duration + newFlightNode->getDelay());
	newFlightNode->arrival = arrivalTime;

	if (sourceHub->headFlights == NULL) {
		sourceHub->headFlights = newFlightNode;
	} else {
		newFlightNode->next = sourceHub->headFlights;
		sourceHub->headFlights = newFlightNode;
	}
};