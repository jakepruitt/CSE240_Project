#include <iostream>
#include <string>
#include "ListCreation.h"
#include "IO.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Traversal.h"


HubNode *headHub = NULL;

int main()
{
	importHub();
	importFlight();

	printFlights(headHub);

	deallocateHubs(headHub);
	return 0;
}