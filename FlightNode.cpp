#include "FlightNode.h"

//NOTE!!!:  We do not use a constructor when creating FlightNodes!

float FlightNode::getBaggageFees(int numBags) { return 0; };
int FlightNode::getDelay() { return 0; };

float FlightSouthWest::getBaggageFees(int numBags) {
	return (float) numBags * 25;
};

int FlightSouthWest::getDelay() {
	if(departure->getHours() >= 7 && departure->getHours() <= 17){return 30;}  // Add delay if time between 7 AM - 5 PM
	return 0;  // No delay
};

float FlightDelta::getBaggageFees(int numBags) {
	return 0;
};

int FlightDelta::getDelay() {
	return 20;  // Add constant time delay
};

float FlightUSAirway::getBaggageFees(int numBags) {
	return (float) 25*(numBags - 1);
};

int FlightUSAirway::getDelay() {
	if(departure->getHours() >= 7 && departure->getHours() <= 17){return 10;}  // Add delay if time between 7 AM - 5 PM
	if((departure->getHours() >= 7 && departure->getMinutes() >= 1) && departure->getHours() <= 1){return 15;} // Add delay if time between 5:01 PM - 1 AM
	return 0;  // No delay
};

FlightNode::~FlightNode() {
	delete departure;  
};



