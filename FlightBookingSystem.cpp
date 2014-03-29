#include <iostream>
#include <string>
#include "ListCreation.h"
#include "IO.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"
#include "Search.h"

// Global Variables
HubNode *headHub = NULL;	// Global pointer to start of HubNode linked list

int main()
{
	importHub();				//  Load hub csv and creates hub linked list
	importFlight();				//	Load flights csv and creates flight linked list
	printFlights(headHub);		//  Prints flights (debug function)
	deallocateHubs(headHub);	//  Frees heap memory 
	headHub = NULL;
	return 0;
}