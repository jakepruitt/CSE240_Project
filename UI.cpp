#include "UI.h"
#include <iostream>
#include <string>
#include "Search.h"
#include "HubNode.h"
#include "Date_Time.h"
#include "Traversal.h"
#include <algorithm>
#include <fstream>	
#include <sstream>

using namespace std;

Date_Time* startDate;
Date_Time* endDate;

/*Make sure start date is before end date*/

//Set destination
string UI_destination(){

	HubNode *compareNode = new HubNode();

	//Destination input as a character array
	//Converted to a string (must hit Enter twice for input b/c of cin.ignore())
	char dest[200];

	cout<<"Please enter your desired destination: ";
	cin.getline(dest, 200, '\n');
	cout << endl;

	string destination(dest);

	if (!hubExists(destination))
	{
		cout << "\n\nThat is not a valid destination. Please try again\n" << endl;
		destination = UI_destination();
	}
	
	return destination;
	
};

//Set departure date and time
Date_Time* UI_departureStartDateTime() {

	string dayChoice, startString;

	Date_Time* startDateInput;
	int startDay, startMonth, startYear;


	//Asks user for start date
	cout<<"Enter the start date.\n";
	try {
		cout<<"Year(Ex: 2013): ";
		string startYear_txt;
		cin>>startYear_txt;
		istringstream(startYear_txt) >> startYear;

		if (startYear <= 2012 || startYear > 2014)
		{
			throw 0;
		}

		string startY = to_string(startYear);

		cout<<"Month(Ex: 05): ";
		string startMonth_txt;
		cin>>startMonth_txt;
		istringstream(startMonth_txt) >> startMonth;

		if (startMonth <= 0 || startMonth > 12)
		{
			throw 1;
		}

		string startM = to_string(startMonth);
		//Adds a '0' to the month if it's a single digit
		if(startMonth<10)
		{
			startM = "0" + startM;
		}

		cout<<"Day(Ex: 17): ";
		string startDay_txt;
		cin>>startDay_txt;
		istringstream(startDay_txt) >> startDay;

		if ((startDay > 31) || 
			(startDay < 1) || 
			(startDay > 30 && (startMonth == 4 || startMonth == 6 || startMonth == 9 || startMonth == 11 ) ) || 
			(startDay > 29 && (startMonth == 2 && startYear % 4 == 0) /* It's a leap year */) ||
			(startDay > 28 && (startMonth == 2 && startYear % 4 != 0) /* It's not a leap year */))
		{
			throw 2;
		}

		string startD = to_string(startDay);
		//Adds a '0' to the day if it's a single digit
		if(startDay<10)
		{
			startD = "0" + startD;
		}

		startString = "00/00/" + startD + "/" + startM + "/" + startY;

		startDateInput = new Date_Time(startString);

	} catch (int err) {
		if (err == 0)
		{
			cout << "\n\nYour Year was invalid, please try re-entering\n" << endl;
		}
		else if (err == 1)
		{
			cout << "\n\nYour Month was invalid, please try re-entering\n" << endl;
		}
		else if (err == 2)
		{
			cout << "\n\nYour Day was invalid, please try re-entering\n" << endl;
		}

		startDateInput = UI_departureStartDateTime();
	}

	return startDateInput;
};

Date_Time* UI_departureEndDateTime(Date_Time* startDateInput) {
	//Asks user for end date
	string endString;
	int endDay, endMonth, endYear;
	Date_Time* endDateInput;

	cout<<"\nEnter the end date.\n";
	try {
		cout<<"Year(Ex: 2013): ";
		string endYear_txt;
		cin>>endYear_txt;
		istringstream(endYear_txt) >> endYear;

		if (endYear <= 2012 || endYear > 2014)
		{
			throw 0;
		}

		string endY = to_string(endYear);

		cout<<"Month(Ex: 05): ";
		string endMonth_txt;
		cin>>endMonth_txt;
		istringstream(endMonth_txt) >> endMonth;

		if (endMonth <= 0 || endMonth > 12)
		{
			throw 1;
		}

		string endM = to_string(endMonth);
		//Adds a '0' to the month if it's a single digit
		if(endMonth<10)
		{
			endM = "0" + endM;
		}

		cout<<"Day(Ex: 17): ";
		string endDay_txt;
		cin>>endDay_txt;
		istringstream(endDay_txt) >> endDay;

		if ((endDay > 31) || 
			(endDay < 1) || 
			(endDay > 30 && (endMonth == 4 || endMonth == 6 || endMonth == 9 || endMonth == 11 ) ) || 
			(endDay > 29 && (endMonth == 2 && endYear % 4 == 0) /* It's a leap year */) ||
			(endDay > 28 && (endMonth == 2 && endYear % 4 != 0) /* It's not a leap year */))
		{
			throw 2;
		}

		string endD = to_string(endDay);
		//Adds a '0' to the day if it's a single digit
		if(endDay<10)
		{
			endD = "0" + endD;
		}

		endString = "59/23/" + endD + "/" + endM + "/" + endY;

		endDateInput = new Date_Time(endString);

		if (timeBetween(startDateInput, endDateInput) < 0){
			throw 3;
		}

	} catch (int err) {
		if (err == 0)
		{
			cout << "\n\nYour Year was invalid, please try re-entering\n" << endl;
		}
		else if (err == 1)
		{
			cout << "\n\nYour Month was invalid, please try re-entering\n" << endl;
		}
		else if (err == 2)
		{
			cout << "\n\nYour Day was invalid, please try re-entering\n" << endl;
		}
		else if (err == 3)
		{
			cout << "\n\nPlease check that your end date comes after your start date.\n" << endl;
		}

		endDateInput = UI_departureEndDateTime(startDateInput);
	}

	return endDateInput;
};

//Set number of bags
int numBags() {

	int bagNum;

	cout<<"How many bags will you have? ";
	cin>>bagNum;

	cout<<endl;

	//Check if number of bags is not acceptable
	try{
		if(bagNum<0)	throw 1;
	}
	catch(int ie){
		if(ie == 1){cout<<"Exception: Cannot have negative bags\n";}
	}

	return bagNum;
}

//Set whether flight plan is organized by cheapest or shortest flight
string filterType(){
	string fType;

	cout<<"Do you want the cheapest or shortest flights?\ncheapest or shortest(lowercase)? ";
	cin>>fType;

	transform(fType.begin(), fType.end(), fType.begin(), ::tolower);

	if(fType!="cheapest"){
		if(fType!="shortest"){
			cout<<"Filter type error. Try again.\n"<<endl;
			filterType();
		}
	}

	return fType;
}

void displayMenu(){
	int selection = 0;
	string input;
	string destination = "";
	int departTime = 0;
	int bagNum = -1;
	string fType = "";
	string sortChoice = "";
	string option = "";
	Date_Time *startDate = NULL, *endDate = NULL;

	do{
		cout<<"\n-----Flight Booking System Main Menu-----\n"<<endl;
		cout<<"   1. Select departure date and time."<<endl;
		cout<<"   2. Select destination."<<endl;
		cout<<"   3. Enter number of bags."<<endl;
		cout<<"   4. Select flight search by time or price."<<endl;
		cout<<"   5. Search for a flight."<<endl;
		cout<<"   6. Exit.\n"<<endl;

		selection = 0;
		cout<<"Please make a selection(e.g. 1): ";
		std::cin >> input;
		istringstream(input) >> selection;
		cout<<endl;


		switch(selection){
		case 1:
			startDate = UI_departureStartDateTime();
			endDate = UI_departureEndDateTime(startDate);
			break;
		case 2:
			cin.ignore();
			destination = UI_destination();
			break;
		case 3:
			bagNum = numBags();
			break;
		case 4:
			fType = filterType();
			break;
		case 5:
			if (startDate == NULL || endDate == NULL || fType == "" || bagNum == -1 || destination == "")
			{
				cout << "Please check that you have entered all of the required information" << endl;
			} else {
				createFlightPlan(startDate, endDate, destination, bagNum, fType);

				//Allows user to go back to Main Menu and check for different flights
				cin>>option;
				if(option == "N" || option == "n")
				{
					break;
				}
				cout << "\nWonderful! Your tickets have been booked.  See above for details." << endl;
				selection = 6;
			}
			
			break;
		case 6:
			break;
		default:
			cout<<"Enter a valid input."<<endl;
			cin.ignore();
			break;
		}
	}while(selection!=6);

	delete endDate;
	delete startDate;
};
