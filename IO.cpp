//CSV IO
//Author:  Andrew Farber

// Import Lib
#include <iostream>
#include <fstream>	
#include <sstream>	

using namespace std;

#pragma warning(disable: 4996)


void importHub(){
	
	// CSV Format
	// airport, cityName
	string airport;		// Holds the name of the airport
	string cityName;	// Holds the full name of the city 

	fstream fileHandler;
	fileHandler.open("Hub.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		while(getline(fileHandler, airport, ',')){
			getline(fileHandler, cityName, ',');
			addhub(airport, cityName);
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

}

void importFlight(){

	// CSV Format
	// flightNumber, price, sourceAirport, destinationAiport, departureTime, duration, company
	string flightNumber;			// Hold flight number
	string price;					// Holds price of ticket
	string sourceAirport;			// Holds source aiport (takeoff location)
	string destinationAirport;      // Holds destination aiport (landing location)
	string departureTime;			// Holds time that plan leaves sourceAirport
	string duration;				// Holds time of flight
	string company;					// Holds company of airline 

	fstream fileHandler;
	fileHandler.open("Flight.csv", ios::in | ios:: binary);

	if(fileHandler.is_open()){
		while(getline(fileHandler, flightNumber, ',')){
			getline(fileHandler, price, ',');
			getline(fileHandler, sourceAirport, ',');
			getline(fileHandler, destinationAirport, ',');
			getline(fileHandler, departureTime, ',');
			getline(fileHandler, duration, ',');
			getline(fileHandler, company, ',');
			addFlight(flightNumber, price, departureTime, duration, sourceAirport, destinationAirport, company);  //Note i added company to inputs
		}
		fileHandler.close();
	}
	else{
		cout << "\nERROR:  Could not open file for loading data.\n";
	}

}


