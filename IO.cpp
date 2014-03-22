//CSV IO
//Author:  Andrew Farber
#include "IO.h"

// Import Lib
#include <iostream>
#include <fstream>	
#include <sstream>

#include "ListCreation.h"


using namespace std;


void importHub() {
	
	// CSV Format
	// airport, cityName
	string airport;		// Holds the name of the airport
	string cityName;	// Holds the full name of the city 
	string ignore;

	fstream fileHandler;
	fileHandler.open("Hub.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		getline(fileHandler, ignore, '\n');
		while(getline(fileHandler, airport, ',')){
			getline(fileHandler, cityName, '\r');
			getline(fileHandler, ignore, '\n');
			addHub(airport, cityName);
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

};

void importFlight() {

	// CSV Format
	// flightNumber, price, sourceAirport, destinationAiport, departureTime, duration, company
	string flightNumber;			// Hold flight number
	string price;					// Holds price of ticket
	string sourceAirport;			// Holds source aiport (takeoff location)
	string destinationAirport;      // Holds destination aiport (landing location)
	string departureTime;			// Holds time that plan leaves sourceAirport
	string duration;				// Holds time of flight
	string company;					// Holds company of airline 
	string ignore;

	double price_num;
	int duration_num;

	fstream fileHandler;
	fileHandler.open("Flight.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		getline(fileHandler, ignore, '\n');
		while(getline(fileHandler, flightNumber, ',')){
			getline(fileHandler, price, ',');
			istringstream(price) >> price_num;			//converts from string to double
			getline(fileHandler, sourceAirport, ',');
			getline(fileHandler, destinationAirport, ',');
			getline(fileHandler, departureTime, ',');
			getline(fileHandler, duration, ',');
			istringstream(duration) >> duration_num;		//converts from string to int
			getline(fileHandler, company, '\r');
			getline(fileHandler, ignore, '\n');
			addFlight(flightNumber, price_num, departureTime, duration_num, sourceAirport, destinationAirport, company);  //Note i added company to inputs
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

};


