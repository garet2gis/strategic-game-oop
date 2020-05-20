#include "Base.h"

Base::Base(int maxCreateUnits, PlayingField* field, int X, int Y) {
	this->maxCreateUnits = maxCreateUnits;
	this->field = field;
	healPoints = 1000;
	warriorFactory = new WarriorFactory();
	shooterFactory = new ShooterFactory();
	bufferFactory = new BufferFactory();
	flyweightFactory = new FlyweightFactory({{"green"},{"blue"},{"red"}});
	name = "Base";
	shortName = "_B_";
	canMove = false;

	field->addObject(this, X, Y);

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

void Base::createUnit(std::string UnitType, std::string color,unsigned row, unsigned column)
{
	if (maxCreateUnits == units.size()) {
		std::cout << "Base can't create more units\n";
		return;
	}
	Unit* newUnit;
	Flyweight newFlyweight = flyweightFactory->GetFlyweight({ color }); //если легковес с таким цветом существует возвращает его, иначе возвращает новый легковес
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
	newUnit->setFlyweight(&newFlyweight);
	units.push_back(newUnit);
	if (field->addObject(newUnit, row, column)) {
		std::cout << "Unit added correctly\n";
	}
}


void Base::sendUnitToField(FieldObject* unit, unsigned row, unsigned column) {
	if (field->addObject(unit, row, column)) {
		std::cout << "Unit added correctly\n";
	}
}


