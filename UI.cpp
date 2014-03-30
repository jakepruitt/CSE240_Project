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

	std::cout<<"Please enter your desired destination: "<<std::endl;
	std::cin>>destination;
	std::cout<<"\n"<<std::endl;

	for(compareNode = headHub; compareNode->next!=NULL; compareNode=compareNode->next){
		if(compareNode->location == destination){
			break;
		}
	}
	if(compareNode==NULL){
		std::cout<<"Destination error. Try again.\n"<<endl;
		UI_destination();
	}

	return destination;
}

//Set departure date and time
void UI_departureDateTime(){

	string dayChoice, startString, endString;
	int startDay, startMonth, endDay, endMonth;

	//Asks for a certain departure date or range of dates
	std::cout<<"Would you like a range of dates to choose from?(Yes or No) ";
	std::cin>>dayChoice;
	std::cout<<"\n";

	//Asks user for start date
	std::cout<<"Enter the start date.\n";
	std::cout<<"Month(Ex: 05): ";
	std::cin>>startMonth;
	std::string startM = std::to_string(startMonth);
	std::cout<<"Day(Ex: 17): ";
	std::cin>>startDay;
	std::string startD = std::to_string(startDay);

	startString = "00/00/" + startD + "/" + startM + "/2013";

	startDate = new Date_Time(startString);
	

	//Asks user for end date
	if(dayChoice=="yes"){
		std::cout<<"\nEnter the end date.\n";
		std::cout<<"Month(Ex: 11): ";
		std::cin>>endMonth;
		std::string endM = std::to_string(endMonth);
		std::cout<<"Day(Ex: 07): ";
		std::cin>>endDay;
		std::string endD = std::to_string(endDay);

		endString = "59/11/" + endD + "/" + endM + "/2013";

		endDate = new Date_Time(endString);
	}
	
	//If the user picks a specific date(not range), then the end date will be the same as
	//the start date(except for the time)
	if(&endDate==NULL){
		endString = "59/11" + startD + "/" + startM + "/" + "2013";
		endDate = new Date_Time(endString);
	}

}

//Set number of bags
int numBags(){

	int bagNum;

	std::cout<<"How many bags will you have? ";
	std::cin>>bagNum;
	std::cout<<"\n"<<std::endl;

	return bagNum;
}

//Set whether flight plan is organized by cheapest or shortest flight
string filterType(){
	string fType;

	std::cout<<"Do you want the cheapest or shortest flights?\nCheapest or shortest(lowercase)? ";
	std::cin>>fType;
	std::transform(fType.begin(), fType.end(), fType.begin(), ::tolower);
	std::cout<<"\n"<<std::endl;
	
	if(fType!="cheapest"){
		if(fType!="shortest"){
			std::cout<<"Filter type error. Try again.\n"<<endl;
			filterType();
		}
	}

	return fType;
}

void displayMenu(){
	int selection;

	string destination = "";
	int departTime = 0;
	int bagNum = 0;
	string fType = "";
	string sortChoice = "";

	do{
		std::cout<<"-----Flight Booking System Main Menu-----\n"<<std::endl;
		std::cout<<"   1. Select departure date and time."<<std::endl;
		std::cout<<"   2. Select destination."<<std::endl;
		std::cout<<"   3. Enter number of bags."<<std::endl;
		std::cout<<"   4. Select flight search by time or price."<<std::endl;
		std::cout<<"   5. Exit.\n"<<std::endl;

		std::cout<<"Please make a selection: ";
		std::cin>>selection;
		std::cout<<std::endl;

		switch(selection){
			case 1:
				UI_departureDateTime();
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
				break;
			default:
				std::cout<<"Enter a valid input.\n\n"<<std::endl;
				break;
		}
	}while(selection!=5);

	createFlightPlan(startDate, endDate, destination, bagNum, sortChoice);
}
