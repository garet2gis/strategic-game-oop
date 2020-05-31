#include "Landscape.h"


Mountains::Mountains() {
	name = "Mountains";
	shortName = "M";
	canMove = false;
}

bool Mountains::canHoldFieldObject(FieldObject* unit) const { return true; }

Landscape* Mountains::copy() {
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
bool Ground::canHoldFieldObject(FieldObject* unit) const{ return true; }

Landscape* Ground::copy() {
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

bool Water::canHoldFieldObject(FieldObject* object) const{
	if (object->getAbstractClass() == "Unit") {
		std::cout << "Unit can't swim\n";
		object->setAlive(false);
	}
	return false; 
}

Landscape* Water::copy(){
	return new Water(*this);
}
std::string Water::info() {
	std::string out = "Info class: Landscape - Water\n";
	return out;
}
