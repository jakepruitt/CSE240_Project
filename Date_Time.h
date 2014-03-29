#ifndef DATE_TIME_H
#define DATE_TIME_H

#include <iostream>
#include <string> 

using namespace std;

class Date_Time{
	public:
		Date_Time();				// Default constructor (initializes all values to 0)
		Date_Time(string dateText); // Constructor (parses string input to time and date information)
		void AddMinutes(int min);   // Increases the minutes instance variable (used for calculating delays)
		string ToString();			// Prints date to console 
		int ToInteger();			// Translates date into number of minutes since 1/1/2013
		int getMinutes();			// Get minutes
		int getHours();				// get hours
	private:  
		int minutes, hours;  		// Time variables
		int day, month, year;		// Date variables
};

int timeBetween(Date_Time *start, Date_Time *end);

#endif