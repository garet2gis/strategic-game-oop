#pragma once
#include "Flyweight.h"
#include "Field.h"
#include "ArmyFactory.h"
#include "observer_interfaces.h"

class Base : public FieldObject, IBase
{
protected:
	std::string name;
	int healPoints = 0;

	int maxCreateUnits;
	unsigned unitCounter;

	ArmyFactory* warriorFactory;
	ArmyFactory* shooterFactory;
	ArmyFactory* bufferFactory;

	FlyweightFactory* flyweightFactory;

	PlayingField* field;
	//sf::Sprite sprite
	std::vector<Unit*> units;
public:
	Base(int maxCreateUnits = 1, PlayingField* field_ = nullptr, int X = 0, int Y = 0);
	//virtual void render(sf::RenderWindow& window) const;
	void setMaxCreateUnits(int newMax);
	virtual std::string getName();
	virtual std::string getShortName();
	virtual std::string info();

	bool isMovable() {
		return canMove;
	}
	FieldObject* copy()
	{
		return new Base(*this);
	}
	//void makeUnits(int numb, std::string kind);
	void createUnit(std::string UnitType, std::string color, unsigned row, unsigned column);
	void sendUnitToField(FieldObject* unit, unsigned row, unsigned column);

	void onUnitDestroyed(Unit* destroyedUnit) {
		for (unsigned int i = 0; i < units.size();i++) {
			if (units[i] == destroyedUnit) {
				units.erase(units.begin()+i);
				delete destroyedUnit;
				return;
			}
		}
	}

};

