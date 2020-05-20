#include "Landscape.h"


Mountains::Mountains() {
	name = "Mountains";
	shortName = "M";
	canMove = false;
}

bool Mountains::canHoldCreature() const { return true; }

FieldObject* Mountains::copy() {
	return new Mountains(*this);
}

std::string Mountains::info() {
	std::string out = "Info class: Landscape - Mountains\n";
	return out;
}



Ground::Ground() {
	name = "Ground";
	shortName = "G";
	canMove = false;
}
bool Ground::canHoldCreature() const{ return true; }

FieldObject* Ground::copy() {
	return new Ground(*this);
}

std::string Ground::info() {
	std::string out = "Info class: Landscape - Ground\n";
	return out;
}


Water::Water() {
	name = "Water";
	shortName = "W";
	canMove = false;
}

bool Water::canHoldCreature() const{ return false; }

FieldObject* Water::copy(){
	return new Water(*this);
}
std::string Water::info() {
	std::string out = "Info class: Landscape - Water\n";
	return out;
}
