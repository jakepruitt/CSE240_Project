#ifndef LIST_CREATION_H
#define LIST_CREATION_H

#include <string>
using namespace std;

// Creates hub linked list
void addHub(string airport, string city);

//  Creates flight linked list
void addFlight(string FlightNumber, double price, string departure, int duration, string sourceAirportName, string destinationAirportName, string company);

#endif