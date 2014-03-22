//Date_Time Class
//Description:  
//Author:  Andrew Farber

//Import Lib
#include "Date_Time.h"
#include <iostream>
#include <string.h>
#include <string> 
#include <sstream>

#pragma warning(disable: 4996)

using namespace std;

//Default Constructor
Date_Time::Date_Time(){minutes = hours = day = month = year = 0;}

//Constructor
Date_Time::Date_Time(string dateText){

	//Format of dateText (all have ## integer format)
	//min/hour/day/month/year
	
	// Temporary variables for error checking
	int min, hr, dy, mnth, yr;  

	//Parse dateText into date and time categories
	std::string min_txt 	= dateText.substr(0,2);
	std::string hr_txt 		= dateText.substr(3,5);
	std::string dy_txt 		= dateText.substr(6,8);
	std::string mnth_txt 	= dateText.substr(9,11);
	std::string yr_txt 		= dateText.substr(12,16);

	//Convert String to integer 
	min 	= atoi(min_txt.c_str());
	hr		= atoi(hr_txt.c_str());
	dy 		= atoi(dy_txt.c_str());
	mnth	= atoi(mnth_txt.c_str());
	yr 		= atoi(yr_txt.c_str());

	// Check for errors in date and time
	try{
		if(min < 0 || min > 59) 	throw 1;
		if(hr < 0 || hr > 23) 		throw 2; 	
		if(dy < 0 || day > 31) 		throw 3;
		if(mnth < 1 || mnth > 12) 	throw 4;
		if(yr_txt.length() != 4) 	throw 5;
	 }
	catch(int ie){
		string error;
		if(ie == 1){error = "Exception: Incorrect Minute";}
		if(ie == 2){error = "Exception: Incorrect Hour";}
		if(ie == 3){error = "Exception: Incorrect Day";}
		if(ie == 4){error = "Exception: Incorrect Month";}
		if(ie == 5){error = "Exception: Incorrect Year";}
		cout << error << "\n";
	}
	
	// If no errors make temp variables class instance variables
	minutes = min;
	hours 	= hr;
	day 	= dy;
	month 	= mnth;
	year 	= yr;
}

//AddMinutes:  increases the number of minutes instance variable
void Date_Time::AddMinutes(int min){ minutes = minutes + min;}

//Prints date and time to console
string Date_Time::ToString(){
	
	//Converts integers to strings then concatenates into output
	string mnths 	= static_cast<ostringstream*>( &(ostringstream() << month) )->str();
	string dys 		= static_cast<ostringstream*>( &(ostringstream() << day) )->str();
	string yrs 		= static_cast<ostringstream*>( &(ostringstream() << year) )->str();
	string hrs 		= static_cast<ostringstream*>( &(ostringstream() << hours) )->str();
	string mins 	= static_cast<ostringstream*>( &(ostringstream() << minutes) )->str();
	string output = mnths + "/" + dys + "/" + yrs + "   " + hrs + ":" + mins;
	return output;
}

