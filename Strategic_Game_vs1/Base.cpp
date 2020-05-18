#include "Base.h"

Base::Base(int maxCreateUnits, PlayingField* field) {
	this->maxCreateUnits = maxCreateUnits;
	this->field = field;

	healPoints = 1000;
	warriorFactory = new WarriorFactory();
	shooterFactory = new ShooterFactory();
	bufferFactory = new BufferFactory();

	flyweightFactory = new FlyweightFactory({ {"green"},{"blue"},{"red"}});


	name = "Base";
	shortName = "_B_";

}
std::string Base::getShortName() {
	return shortName;
}
std::string Base::getName() {
	return name;
}
std::string Base::info() {
	std::string out = "Base , current healpoints: " + std::to_string(healPoints) +  "\n";
	return out;
}

void Base::setMaxCreateUnits(int newMax) {
	maxCreateUnits = newMax;
}

void Base::createUnit(std::string UnitType, unsigned row, unsigned column, std::string color)
{
	Unit* newUnit;
	
	Flyweight newFlyweight = flyweightFactory->GetFlyweight({ color });



	if (UnitType == "W_t") {
		newUnit = warriorFactory->createTank();
	}
	else if (UnitType == "W_d") {
		newUnit = warriorFactory->createDamager();
	}
	else if (UnitType == "S_t") {
		newUnit = shooterFactory->createTank();
	}
	else if (UnitType == "S_d") {
		newUnit = shooterFactory->createDamager();
	}
	else if (UnitType == "B_t") {
		newUnit = bufferFactory->createTank();
	}
	else if (UnitType == "B_d") {
		newUnit = bufferFactory->createDamager();
	}
	else {
		std::cout << "Wrong UnitType \n";
		return;
	}
	units.push_back(new FullUnit(newUnit, &newFlyweight));
}


template <class T>
void Base::makeUnits(int numb, std::string kind) {
	if (numb > maxCreateUnits) {
		std::cout << "Impossible to make this numb of Units\n";
		return;
	}

	ArmyFactory* humanFactory = new HumanArmyFactory();
	



}



