#include "Search.h"
#include <string>
#include "Date_Time.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"

using namespace std;

float FlightPlan::calculateCost() {
	return 0;
}
float FlightPlan::calculateArrivalTime() {
	return 0;
}
float FlightPlan::calculateDuration() {
	return 0;
}
void FlightPlan::printItinerary() {
	return;
}

/* Handler function to take in the user's input from the command line and call the appropriate recursive search algorythm.  
	Ends with a call to a print function and deletes the FlightPlan used to find the lowest. */
void flightSearchController(Date_Time* startDate, Date_Time* endDate, string destination, int bags, string cheapOrShort) {
	FlightPlan* lowest = new FlightPlan();
	lowest->bags = bags;
	lowest->startHub = searchHub("Phoenix SkyHarbor International Airport", headHub);
	FlightPlan* tracking = lowest;

	if (cheapOrShort.compare("cheapest") == 0) {
		searchForCheapest(lowest->startHub, destination, lowest, tracking, 0);
	} else {
		searchForShortest(lowest->startHub, destination, lowest, tracking, 0);
	}

	lowest->printItinerary();
	tracking = NULL;
	delete lowest;
	return;
};

/* Recursive function that takes searches for the cheapest flight.
	Parameters:
		HubNode* source => a pointer to the hubNode that the function is currently iterating through
		string destination => the string name of the destination airport (e.g. Phoenix SkyHarbor International Airport)
		FlightPlan* lowest => a pointer to the FlightPlan holding the currently cheapest flight
		FlightPlan* tracking => a pointer to the FlightPlan holding the current path
		int depth => an integer tracking the current number of flights in the tracking path
*/
void searchForCheapest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth) {
	if (tracking->endHub->name.compare(destination) == 0) {
		/* If the tracking FlightPlan ends at our desired location, we need to check if it is cheaper than
			the lowest flight plan, and then return. */
		if (tracking->calculateCost() < lowest->calculateCost()) {
			// If the tracking FlightPlan is cheaper than the lowest FlightPlan, transfer all data to lowest
			for (int i = 0; i < 2; i++) {
				lowest->path[i] = tracking->path[i];
			}
			lowest->startTime = tracking->startTime;
		}

		return;
	} else if (depth == 2) {
		/* If the depth has reached 2 without arriving to the desired destination, return */
		return;
	} else {
		/* If we have only 0 or 1 flights, we must iterate through the sourceHub's flights, adding the flight
			to the tracking FlightPlan and calling the recursive function again */
		FlightNode* tempFlight = source->headFlights;

		while (tempFlight != NULL) {
			/* Iterates through all of the flights, adding the flight to the FlightPlan's path, and setting the
				FlightPlan's endHub equal to the flight's destination. */
			tracking->path[depth] = tempFlight;
			tracking->endHub = tempFlight->destination;

			searchForCheapest(tempFlight->destination,destination, lowest, tracking, (depth + 1));

			tempFlight = tempFlight->next;
		}
	}
};



/* Recursive function that takes searches for the shortest flight.
	Parameters:
		HubNode* source => a pointer to the hubNode that the function is currently iterating through
		string destination => the string name of the destination airport (e.g. Phoenix SkyHarbor International Airport)
		FlightPlan* lowest => a pointer to the FlightPlan holding the currently cheapest flight
		FlightPlan* tracking => a pointer to the FlightPlan holding the current path
		int depth => an integer tracking the current number of flights in the tracking path
*/
void searchForShortest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth) {
	if (tracking->endHub->name.compare(destination) == 0) {
		/* If the tracking FlightPlan ends at our desired location, we need to check if it is cheaper than
			the lowest flight plan, and then return. */
		if (tracking->calculateDuration() < lowest->calculateDuration()) {
			// If the tracking FlightPlan is cheaper than the lowest FlightPlan, transfer all data to lowest
			for (int i = 0; i < 2; i++) {
				lowest->path[i] = tracking->path[i];
			}
			lowest->startTime = tracking->startTime;
		}

		return;
	} else if (depth == 2) {
		/* If the depth has reached 2 without arriving to the desired destination, return */
		return;
	} else {
		/* If we have only 0 or 1 flights, we must iterate through the sourceHub's flights, adding the flight
			to the tracking FlightPlan and calling the recursive function again */
		FlightNode* tempFlight = source->headFlights;

		while (tempFlight != NULL) {
			/* Iterates through all of the flights, adding the flight to the FlightPlan's path, and setting the
				FlightPlan's endHub equal to the flight's destination. */
			tracking->path[depth] = tempFlight;
			tracking->endHub = tempFlight->destination;

			searchForCheapest(tempFlight->destination,destination, lowest, tracking, (depth + 1));

			tempFlight = tempFlight->next;
		}
	}
};