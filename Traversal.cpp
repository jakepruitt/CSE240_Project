#include <iostream>
#include <string>

public void deallocation(int *head)
{
	if(head != NULL)
	{
		deallocation(head->next);
		delete head;
	}
}

public void printFlights(int *hub)
{
	while(hub->next != NULL)
	{
		std::string hub_name = hub->name;
		std::string hub_location = hub->location
		int *flight = hub->headflight;
		std::cout<<hub_name<<std::endl;
		std::cout<<hub_location<<std::endl;
		
		while(flight->next != NULL)
		{
			std::string Destination = flight->destination->name;
			flight_number = flight->flightNumber;
			Date_Time date_time = flight->Date_Time;
			
			std::cout<<Destination<<std::endl;
			std::cout<<flight_number<<std::endl:
			ToString(date_time);
		}
	}
}

public int searchHub(std::string hub_name, int *hub)
{
	while(hub-> != NULL)
	{
		if((hub->name).compare(hub_name))
		{
			return hub;
		}
		
		hub = hub->next;
	}
}