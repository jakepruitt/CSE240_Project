#include "FlightNode.h"

float FlightNode::getBaggageFees(int numBags) { return 0; };
int FlightNode::getDelay() { return 0; };

float FlightSouthWest::getBaggageFees(int numBags) {
	return 2;
};
int FlightSouthWest::getDelay() {
	return 2;
};

float FlightDelta::getBaggageFees(int numBags) {
	return 2;
};
int FlightDelta::getDelay() {
	return 2;
};

float FlightUSAirway::getBaggageFees(int numBags) {
	return 2;
};
int FlightUSAirway::getDelay() {
	return 2;
};