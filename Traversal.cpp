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


void printFlights(HubNode *headHub)
{
	
	HubNode* hub = headHub;

	while(hub != NULL)  
	{

		std::string hub_name = hub->name;
		std::string hub_location = hub->location;
		FlightNode *flight = hub->headFlights;  

		std::cout<<"\n\n"<< hub_name << " - " << hub_location<< endl;
		std::cout<<"=================================================\n\nDepartures:\n"<< endl;
		
		while(flight != NULL)	
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

bool hubExists(std::string hub_location)
{
	 
	HubNode* tempHub = headHub;

	while(tempHub != NULL)
	{
		if((tempHub->location).compare(hub_location) == 0)
		{
			return true;
		}
		
		tempHub = tempHub->next;
	}
	return false;
};