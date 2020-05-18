#pragma once
#include "Flyweight.h"
#include "Field.h"
#include "ArmyFactory.h"

class Base : public FieldObject
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
	std::vector<FullUnit*> units;
public:
	Base(int maxCreateUnits = 1, PlayingField* field_ = nullptr);
	//virtual void render(sf::RenderWindow& window) const;
	void setMaxCreateUnits(int newMax);
	virtual std::string getName();
	virtual std::string getShortName();
	virtual std::string info();
	FieldObject* copy()
	{
		return new Base(*this);
	}
	void makeUnits(int numb, std::string kind);
	void createUnit(std::string UnitType, unsigned row, unsigned column, std::string color);

};

