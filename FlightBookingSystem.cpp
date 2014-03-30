#include <iostream>
#include <string>
#include "ListCreation.h"
#include "IO.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"
#include "Search.h"
#include "Date_Time.h"

// Global Variables
HubNode *headHub = NULL;	// Global pointer to start of HubNode linked list

int main()
{
	importHub();				//  Load hub csv and creates hub linked list
	importFlight();				//	Load flights csv and creates flight linked list

	Date_Time* startTestDate = new Date_Time("00/00/16/12/2013");
	Date_Time* endTestDate = new Date_Time("00/00/19/12/2013");

	createFlightPlan(startTestDate, endTestDate, "Honolulu", 5, "shortest");

	delete startTestDate;
	delete endTestDate;

	deallocateHubs(headHub);	//  Frees heap memory 
	headHub = NULL;
	return 0;
}