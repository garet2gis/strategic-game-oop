#include "Base.h"

Base::Base(int maxCreateUnits, PlayingField* field) {
	this->maxCreateUnits = maxCreateUnits;
	this->field = field;
	this->flagForConsole = 666;
	this->baseType = abstract;
	this->healPoints = 0;


}

HumanBase::HumanBase() : Base() {
	flagForConsole = 4;
	healPoints = 500;
	baseType = Human;
}

AlienBase::AlienBase() : Base() {
	flagForConsole = -4;
	healPoints = 400;
	baseType = Alien;
}

void Base::setMaxCreateUnits(int newMax) {
	maxCreateUnits = newMax;
}

int Base::getConsoleFlag() const{
	return flagForConsole;
}

std::string HumanBase::info() {
	std::string out = "Info: race: human, class: Base, healpoints: " + std::to_string(healPoints) + "\n";
	return out;
}

FieldObject* HumanBase::copy() {
	return new HumanBase(*this);
}

std::string AlienBase::info() {
	std::string out = "Info: race: alien, class: Base, healpoints: " + std::to_string(healPoints) + "\n";
	return out;
}
std::string HumanBase::getName() {
	std::string out = "Info: race: human, class: Base \n";
	return out;
}


std::string AlienBase::getName() {
	std::string out = "Info: race: alien, class: Base \n";
	return out;
}


FieldObject* AlienBase::copy() {
	return new AlienBase(*this);
}



/*template <class T>
void Base::makeUnits(int numb, std::string kind) {
	if (numb > maxCreateUnits) {
		std::cout << "Impossible to make this numb of Units\n";
		return;
	}

	ArmyFactory* humanFactory = new HumanArmyFactory();
	



}
*/


