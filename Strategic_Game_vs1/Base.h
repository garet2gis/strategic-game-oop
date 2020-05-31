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
	~Base() {
		delete warriorFactory;
		delete shooterFactory;
		delete bufferFactory;
		delete flyweightFactory;
	}

	//virtual void render(sf::RenderWindow& window) const;
	void setMaxCreateUnits(int newMax);
	virtual std::string getName();
	virtual std::string getShortName();
	virtual std::string info();
	virtual std::string getAbstractClass() {
		return "Base";
	}
	virtual void unitInfluence(Unit* unit) {}
	bool isAlive() {
		return alive;
	}
	bool isMovable() {
		return canMove;
	}
	void setAlive(bool flag) {
		alive = flag;
	}
	FieldObject* copy()
	{
		return new Base(*this);
	}
	Unit* createUnit(std::string UnitType, std::string color, unsigned row, unsigned column);

	void onUnitDestroyed(Unit* destroyedUnit) {
		
		for (unsigned int i = 0; i < units.size();i++) {
			if (units[i] == destroyedUnit) {
				units.erase(units.begin()+i);
				field->deleteObject(destroyedUnit);
				std::cout << "Base: Unit deleted\n";
				return;
			}
		}
	}

	void moveUnit(unsigned X_old, unsigned Y_old, unsigned X_new, unsigned Y_new) {
		if (field->getUnitPtr(X_old, Y_old)) {
			Unit* unit = dynamic_cast<Unit*>(field->getUnitPtr(X_old, Y_old));
			bool isMyUnit = false;
			for (int i = 0; i < units.size(); i++) {
				if (unit == units[i]) {
					isMyUnit = true;
					break;
				}
			}
			if (!isMyUnit) {
				std::cout << "Base: Its not your unit\n";
				return;
			}
			else {
				field->moveUnit(X_old, Y_old, X_new, Y_new);
			}
		}
		else {
			std::cout << "Base: There is not Unit here\n";
		}

	}



};

