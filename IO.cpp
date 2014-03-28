//CSV IO
//Author:  Andrew Farber
#include "IO.h"

// Import Lib
#include <iostream>
#include <fstream>	
#include <sstream>

#include "ListCreation.h"


using namespace std;

//  Load hub csv and calls addHub(...) to create hub linked list
void importHub() {
	
	// CSV Format
	// airport, cityName
	std::string airport;	// Holds the name of the airport
	std::string cityName;	// Holds the full name of the city 
	std::string ignore;

	fstream fileHandler;
	fileHandler.open("Hub.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		getline(fileHandler, ignore, '\n');
		while(getline(fileHandler, airport, ',')){
			getline(fileHandler, cityName, '\n');
			//getline(fileHandler, ignore, '\n');  // deleted line
			addHub(airport, cityName);
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

};

// Load flight csv and calls addFlights(...) to create flight linked list
void importFlight() {

	// CSV Format
	// flightNumber, price, sourceAirport, destinationAiport, departureTime, duration, company
	std::string flightNumber;			// Hold flight number
	std::string price;					// Holds price of ticket
	std::string sourceAirport;			// Holds source aiport (takeoff location)
	std::string destinationAirport;     // Holds destination aiport (landing location)
	std::string departureTime;			// Holds time that plan leaves sourceAirport
	std::string duration;				// Holds time of flight
	std::string company;				// Holds company of airline 
	std::string ignore;

	double price_num;
	int duration_num;

	fstream fileHandler;
	fileHandler.open("Flight.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		getline(fileHandler, ignore, '\n');
		while(getline(fileHandler, flightNumber, ',')){
			getline(fileHandler, price, ',');
			istringstream(price) >> price_num;				//converts from string to double
			getline(fileHandler, sourceAirport, ',');
			getline(fileHandler, destinationAirport, ',');
			getline(fileHandler, departureTime, ',');
			getline(fileHandler, duration, ',');
			istringstream(duration) >> duration_num;		//converts from string to int
			getline(fileHandler, company, '\n');			
			//getline(fileHandler, ignore, '\n'); delete
			addFlight(flightNumber, price_num, departureTime, duration_num, sourceAirport, destinationAirport, company);  
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

};


