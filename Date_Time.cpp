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

//String based Constructor
Date_Time::Date_Time(string dateText){

	// Format of dateText (all have ## integer format)
	// min/hour/day/month/year
	
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
		if(dy < 1 || day > 31) 		throw 3;
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

//AddMinutes:  increases the number of minutes (used for flight delays)
void Date_Time::AddMinutes(int min){ 
	
	int increaseInHours;
	
	if(min >= 60){  //Increase hour and minutes
		increaseInHours = min / 60;
		hours += increaseInHours;
		minutes = min % 60;
	}
	else{
		minutes = minutes + min;
	}
	if (hours > 23)
	{
		hours %= 24;
		day++;
	}

}

//Prints date and time to console
string Date_Time::ToString(){
	
	//Converts integers to strings then concatenates into output
	string mnths 	= static_cast<ostringstream*>( &(ostringstream() << month) )->str();
	string dys 		= static_cast<ostringstream*>( &(ostringstream() << day) )->str();
	string yrs 		= static_cast<ostringstream*>( &(ostringstream() << year) )->str();
	string hrs 		= static_cast<ostringstream*>( &(ostringstream() << hours) )->str();
	string mins 	= static_cast<ostringstream*>( &(ostringstream() << minutes) )->str();
	
	//Special Case
	if (minutes < 10) {
		mins = "0" + mins;
	}
	
	string output = mnths + "/" + dys + "/" + yrs + "   " + hrs + ":" + mins;
	return output;

}

int Date_Time::ToInteger() {
	int total = (year - 2013) * 365;
	switch (month)
	{
	case 1:
		total += 0;
		break;
	case 2:
		total += 31;
		break;
	case 3:
		total += 31 + 28;
		break;
	case 4:
		total += 31 + 28 + 31;
		break;
	case 5:
		total += 31 + 28 + 31 + 30;
		break;
	case 6:
		total += 31 + 28 + 31 + 30 + 31;
		break;
	case 7:
		total += 31 + 28 + 31 + 30 + 31 + 30;
		break;
	case 8:
		total += 31 + 28 + 31 + 30 + 31 + 30 + 31;
		break;
	case 9:
		total += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
		break;
	case 10:
		total += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
		break;
	case 11:
		total += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
		break;
	case 12:
		total += 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
		break;
	}
	total += day;
	total *= 24*60;
	total += hours*60;
	total += minutes;
	return total;
}

// Get minutes
int Date_Time::getMinutes(){return minutes;	}

// Get hours
int Date_Time::getHours(){return hours;}

int timeBetween(Date_Time* start, Date_Time* end) {
	return end->ToInteger() - start->ToInteger();
}


