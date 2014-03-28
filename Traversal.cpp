#include <iostream>
#include <string>
#include "HubNode.h"
#include "FlightNode.h"
#include "Date_Time.h"

void deallocateHubs(HubNode *head)
{
	if(head != NULL)
	{
		deallocateHubs(head->next);
		delete head;
	}
};

void deallocateFlights(FlightNode *head)
{
	if(head != NULL)
	{
		deallocateFlights(head->next);
		delete head;
	}
};


//NOT WORKING NOT PRINTING TOP OF LIST - If debug the top of list starts to print but later gets removed (not sure why this happens)
void printFlights(HubNode *headHub)
{
	
	//Error:  passed by address, when moving hub previously the values
	// of headHub was changed (i.e. the address)
	
	// Created local HubNode ptr variable (maybe rename tempHub)
	HubNode* hub = headHub;

	while(hub != NULL)  //changed from hub->next != NULL, does not print entire list
	{

		std::string hub_name = hub->name;
		std::string hub_location = hub->location;
		FlightNode *flight = hub->headFlights;  // made local

		std::cout<<"\n\n"<< hub_name << " - " << hub_location<< endl;
		std::cout<<"=================================================\n\nDepartures:\n"<< endl;
		
		while(flight != NULL)	// same change as first while loop
		{

			std::string Destination = flight->destination->name;
			std::string flight_number = flight->flightNumber;
			Date_Time *date_time = flight->departure;
			
			std::cout<<Destination<<std::endl;
			std::cout<<flight_number<<std::endl;
			std::cout<<date_time->ToString()<<std::endl<<std::endl;
			flight = flight->next;

		}

		hub = hub->next;

	}
};

HubNode* searchHub(std::string hub_name, HubNode *hub)
{
	//Error:  passed by address, when moving hub prev the value
	// of headHub was changed (i.e. the address)
	
	// Created local HubNode ptr variable 
	HubNode* tempHub = hub;

	while(tempHub != NULL)
	{
		if((tempHub->name).compare(hub_name) == 0)
		{
			return tempHub;
		}
		
		tempHub = tempHub->next;
	}
	return NULL;
};