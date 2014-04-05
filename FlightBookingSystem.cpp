#include <iostream>
#include <string>
#include "ListCreation.h"
#include "IO.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"
#include "Search.h"
#include "Date_Time.h"
#include "UI.h"

// Global Variables
HubNode *headHub = NULL;	// Global pointer to start of HubNode linked list

int main()
{
	importHub();		//  Load hub csv and creates hub linked list
	importFlight();		//	Load flights csv and creates flight linked list

	// OS CSV READING ERROR!
	// If error occurs when loading csv files go to IO.cpp and change lines 30, 31 and 71, 72 (see comments in code)

	//UI Functionality (not finished)
	//displayMenu();

	//Test Case 1
	Date_Time* startTestDate1 = new Date_Time("00/00/16/12/2013");
 	Date_Time* endTestDate1 = new Date_Time("00/00/18/12/2013");
	cout << "\nTEST CASE 1: Shortest \n" << endl;
 	createFlightPlan(startTestDate1, endTestDate1, "Los Angeles", 3, "shortest");
	cout << "\n\n\nTEST CASE 1: Cheapest \n" << endl;
	createFlightPlan(startTestDate1, endTestDate1, "Los Angeles", 3, "cheapest");
 	delete startTestDate1;
 	delete endTestDate1;

	//Test Case 2
	Date_Time* startTestDate = new Date_Time("00/00/16/12/2013");
 	Date_Time* endTestDate = new Date_Time("00/00/19/12/2013");
	cout << "\n\n\nTEST CASE 2: Shortest\n" << endl;
	createFlightPlan(startTestDate, endTestDate, "Honolulu", 5, "shortest");
	cout << "\n\n\nTEST CASE 2: Cheapest\n" << endl;
	createFlightPlan(startTestDate, endTestDate, "Honolulu", 5, "cheapest");
 	delete startTestDate;
 	delete endTestDate;

	deallocateHubs(headHub);	//  Frees heap memory 
	headHub = NULL;
	return 0;
}