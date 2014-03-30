#include "Search.h"
#include <string>
#include "Date_Time.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"
#include <iostream>

using namespace std;

/* Flight Plan Constructor */
FlightPlan::FlightPlan() {
	startTime = new Date_Time();
};

FlightPlan::~FlightPlan() {
	delete startTime;
	startHub = NULL;
	endHub = NULL;
};

/* Returns the price of the flights and baggage.  Returns -1 if there are no flights */
float FlightPlan::calculateCost(int numBags) {
	float total = 0;
	if (path[0] == NULL)
	{
		return -1;
	}

	for (int i = 0; i < 2; i++)
	{
		total += (float) path[i]->price + path[i]->getBaggageFees(numBags);
	}

	return total;
}

/* Returns the arrival time of flight.  Returns 0 if there are no flights */
Date_Time* FlightPlan::calculateArrivalTime() {
	int i = 0;
	Date_Time* flightPlanArrival = path[0]->arrival;
	while (path[i] != NULL && i < 2) {
		flightPlanArrival = path[i]->arrival;
		i++;
	}

	return flightPlanArrival;
}

/* Returns the duration of the flight.  Returns -1 if there are no flights */
int FlightPlan::calculateDuration() {
	if (path[0] == NULL)
	{
		return 99999;
	}
	
	int totalDuration = 0;
	
	for (int i = 0; i < 2; i++)
	{
		if (path[i] != NULL)
		{
			totalDuration += path[i]->duration + path[i]->getDelay();
		}
	}


	return totalDuration;
}

/* Output the  */
void FlightPlan::printItinerary() {
	int i = 0;  //Iterator
	while(path[i] != NULL && i < 2){
		std::cout <<  "\n" << endl;
		std::cout << path[i]->flightNumber << "\t" << path[i]->flightCompany << "\t" << "\t" << path[i]->source->location << "\t" << path[i]->departure->ToString() << endl;
		std::cout << "\t\t" << path[i]->destination->location << "\t" << "Arrival Date time";  
		std::cout << "\t\t" << "Price " <<endl;
		std::cout << "\n"	<< endl;
		i = i + 1; 
	}

	std:: cout << "TOTAL PRICE" << endl;
}

/* Handler function to take in the user's input from the command line and call the appropriate recursive search algorthm.  
	Ends with a call to a print function and deletes the FlightPlan used to find the lowest. */
void createFlightPlan(Date_Time* startDate, Date_Time* endDate, string destination, int bags, string cheapOrShort) {
	FlightPlan* lowest = new FlightPlan();
	FlightPlan* tracking = new FlightPlan();
	tracking->bags = lowest->bags = bags;
	tracking->startHub = lowest->startHub = searchHub("Phoenix Sky Harbor International Airport", headHub);
	tracking->path[0] = lowest->path[0] = tracking->path[1] = lowest->path[1] = NULL;
	tracking->startTime = startDate;

	if (cheapOrShort.compare("cheapest") == 0) {
		searchForCheapest(lowest->startHub, destination, lowest, tracking, 0, startDate, endDate, bags);
	} else {
		searchForShortest(lowest->startHub, destination, lowest, tracking, 0, startDate, endDate);
	}

	lowest->startTime = lowest->path[0]->departure;

	lowest->printItinerary();

	// Create a confirmation UI function called here that will restart if the user does not want the ticket

	delete lowest;
	delete tracking;
};

/* Recursive function that searches for the cheapest flight.
	Parameters:
		HubNode* source => a pointer to the hubNode that the function is currently iterating through
		string destination => the string name of the destination city (e.g. Phoenix)
		FlightPlan* lowest => a pointer to the FlightPlan holding the currently cheapest flight
		FlightPlan* tracking => a pointer to the FlightPlan holding the current path
		int depth => an integer tracking the current number of flights in the tracking path
*/
void searchForCheapest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth, Date_Time *startDate, Date_Time *endDate, int bags) {
	if (tracking->endHub != NULL && tracking->endHub->location.compare(destination) == 0 && timeBetween(startDate, tracking->startTime) >= 0 && timeBetween(tracking->calculateArrivalTime(), endDate) >=0 ) {
		/* If the tracking FlightPlan ends at our desired location, we need to check if it is cheaper than
			the lowest flight plan, and then return. */
		if (lowest->calculateCost(bags) < 0 || tracking->calculateCost(bags) < lowest->calculateCost(bags)) {
			// If the tracking FlightPlan is cheaper than the lowest FlightPlan, transfer all data to lowest
			for (int i = 0; i < 2; i++) {
				lowest->path[i] = tracking->path[i];
			}
			*lowest->startTime = *tracking->startTime;
			lowest->endHub = tracking->endHub;
		}

		return;
	} else if (depth == 2) {
		/* If the depth has reached 2 without arriving to the desired destination, return */
		return;
	} else {
		/* If we have only 0 or 1 flights, we must iterate through the sourceHub's flights, adding the flight
			to the tracking FlightPlan and calling the recursive function again on that flight's destination */
		FlightNode* tempFlight = source->headFlights;

		while (tempFlight != NULL) {
			/* Iterates through all of the flights, adding the flight to the FlightPlan's path, and setting the
				FlightPlan's endHub equal to the flight's destination. */

			/* Conditional check to see if second flight starts after first. */
			if (tracking->path[0] == NULL || timeBetween(tracking->calculateArrivalTime(), tempFlight->departure) >= 0 ) {
				tracking->path[depth] = tempFlight;
				tracking->endHub = tempFlight->destination;
				*tracking->startTime = *tempFlight->departure;
				tracking->startTime->AddMinutes(tempFlight->getDelay());
				searchForCheapest(tempFlight->destination,destination, lowest, tracking, (depth + 1), startDate, endDate, bags);
			}


			tempFlight = tempFlight->next;
		}
	}
};



/* Recursive function that takes searches for the shortest flight.
	Parameters:
		HubNode* source => a pointer to the hubNode that the function is currently iterating through
		string destination => the string name of the destination location (e.g. Phoenix)
		FlightPlan* lowest => a pointer to the FlightPlan holding the currently cheapest flight
		FlightPlan* tracking => a pointer to the FlightPlan holding the current path
		int depth => an integer tracking the current number of flights in the tracking path
*/
void searchForShortest(HubNode* source, string destination, FlightPlan* lowest, FlightPlan* tracking, int depth, Date_Time *startDate, Date_Time *endDate) {
	if (tracking->endHub != NULL && tracking->endHub->location.compare(destination) == 0 && timeBetween(startDate, tracking->startTime) >= 0 && timeBetween(tracking->calculateArrivalTime(), endDate) >=0 ) {
		/* If the tracking FlightPlan ends at our desired location, we need to check if it is cheaper than
			the lowest flight plan, and then return. */
		int shortestTime = lowest->calculateDuration();
		int trackingTime = tracking->calculateDuration();
		if (shortestTime < 0 || trackingTime < shortestTime) {
			// If the tracking FlightPlan is cheaper than the lowest FlightPlan, transfer all data to lowest
			for (int i = 0; i < 2; i++) {
				lowest->path[i] = tracking->path[i];
			}
			*lowest->startTime = *tracking->startTime;
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
			if (depth == 0)
			{
				tracking->path[0] = NULL;
				tracking->path[1] = NULL;
			}
			
			/* Conditional check to see if second flight starts after first. */
			if (tracking->path[0] == NULL || timeBetween(tracking->calculateArrivalTime(), tempFlight->departure) >= 0 ) {
				tracking->path[depth] = tempFlight;
				tracking->endHub = tempFlight->destination;
				*tracking->startTime = *tempFlight->departure;
				tracking->startTime->AddMinutes(tempFlight->getDelay());
				searchForShortest(tempFlight->destination,destination, lowest, tracking, (depth + 1), startDate, endDate);
			}


			tempFlight = tempFlight->next;
		}
	}
};