#include "HubNode.h"
#include "Traversal.h"

HubNode::~HubNode() {
	deallocateFlights(headFlights);
}