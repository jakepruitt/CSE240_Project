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

void printFlights(HubNode *hub)
{
	std::string hub_name;
	std::string hub_location;
	FlightNode *flight;
	std::string flight_number;

	while(hub->next != NULL)
	{
		hub_name = hub->name;
		hub_location = hub->location;
		flight = hub->headFlights;
		std::cout<<"\n\n"<<hub_name<<" - "<<hub_location<<std::endl;
		std::cout<<"=================================================\n\nDepartures:\n"<<std::endl;
		
		while(flight->next != NULL)
		{
			std::string Destination = flight->destination->name;
			flight_number = flight->flightNumber;
			Date_Time date_time = flight->departure;
			
			std::cout<<Destination<<std::endl;
			std::cout<<flight_number<<std::endl;
			std::cout<<date_time.ToString()<<std::endl<<std::endl;
			flight = flight->next;
		}
		hub = hub->next;
	}
};

HubNode* searchHub(std::string hub_name, HubNode *hub)
{
	while(hub != NULL)
	{
		if((hub->name).compare(hub_name) == 0)
		{
			return hub;
		}
		
		hub = hub->next;
	}
	return NULL;
};