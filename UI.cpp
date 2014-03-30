#include "UI.h"
#include <iostream>
#include <string>
#include "Search.h"
#include "HubNode.h"
#include "Date_Time.h"
#include <algorithm>

using namespace std;

Date_Time* startDate;
Date_Time* endDate;

//Set destination
string UI_destination(){

	HubNode *compareNode = new HubNode();
	string destination;

	cout<<"Please enter your desired destination: "<<endl;
	cin>>destination;
	
	cout<<"\n"<<endl;

	for(compareNode = headHub; compareNode->next!=NULL; compareNode=compareNode->next){
		if(compareNode->location == destination){
			break;
		}
	}
	if(compareNode==NULL){
		cout<<"Destination error. Try again.\n"<<endl;
		UI_destination();
	}

	return destination;
};

//Set departure date and time
Date_Time* UI_departureStartDateTime() {

	string dayChoice, startString;
	int startDay, startMonth;


	//Asks user for start date
	cout<<"Enter the start date.\n";
	cout<<"Month(Ex: 05): ";
	cin>>startMonth;
	
	string startM = to_string(startMonth);
	cout<<"Day(Ex: 17): ";
	cin>>startDay;
	
	string startD = to_string(startDay);

	startString = "00/00/" + startD + "/" + startM + "/2013";

	Date_Time* startDate = new Date_Time(startString);

	return startDate;

};
	
Date_Time* UI_departureEndDateTime() {
	//Asks user for end date
	string endString;
	int endDay, endMonth;

	cout<<"\nEnter the end date.\n";
	cout<<"Month(Ex: 11): ";
	cin>>endMonth;
	
	string endM = to_string(endMonth);
	cout<<"Day(Ex: 07): ";
	cin>>endDay;
	
	string endD = to_string(endDay);

	endString = "59/11/" + endD + "/" + endM + "/2013";

	Date_Time* endDate = new Date_Time(endString);

	return endDate;

};

//Set number of bags
int numBags() {

	int bagNum;

	cout<<"How many bags will you have? ";
	cin>>bagNum;
	
	cout<<"\n"<<endl;

	return bagNum;
}

//Set whether flight plan is organized by cheapest or shortest flight
string filterType(){
	string fType;

	cout<<"Do you want the cheapest or shortest flights?\nCheapest or shortest(lowercase)? ";
	cin>>fType;
	
	transform(fType.begin(), fType.end(), fType.begin(), ::tolower);
	cout<<"\n"<<endl;
	
	if(fType!="cheapest"){
		if(fType!="shortest"){
			cout<<"Filter type error. Try again.\n"<<endl;
			filterType();
		}
	}

	return fType;
}

void displayMenu(){
	int selection;

	string destination = "";
	int departTime = 0;
	int bagNum = -1;
	string fType = "";
	string sortChoice = "";
	Date_Time *startDate = NULL, *endDate = NULL;

	do{
		cout<<"-----Flight Booking System Main Menu-----\n"<<endl;
		cout<<"   1. Select departure date and time."<<endl;
		cout<<"   2. Select destination."<<endl;
		cout<<"   3. Enter number of bags."<<endl;
		cout<<"   4. Select flight search by time or price."<<endl;
		cout<<"   5. Search for a flight."<<endl;
		cout<<"   6. Exit.\n"<<endl;

		cout<<"Please make a selection: ";
		std::cin >> selection;
		cout<<endl;
		

		switch(selection){
			case 1:
				startDate = UI_departureStartDateTime();
				endDate = UI_departureEndDateTime();
				break;
			case 2:
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
					createFlightPlan(startDate, endDate, destination, bagNum, sortChoice);
				}
				break;
			case 6:
				break;
			default:
				cout<<"Enter a valid input.\n\n"<<endl;
				break;
		}
		cin.ignore();
	}while(selection!=6);

	delete endDate;
	delete startDate;
};
