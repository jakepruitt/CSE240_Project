#ifndef UI_H
#define UI_H

#include "Date_Time.h"
#include <string>

string UI_destination();
Date_Time* UI_departureStartDateTime();
Date_Time* UI_departureEndDateTime(Date_Time* startDateInput);
int numBags();
string filterType();
void displayMenu();


#endif