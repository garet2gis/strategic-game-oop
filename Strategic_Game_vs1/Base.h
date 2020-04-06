#pragma once
#include "Unit.h"
#include "Field.h"

class Base : public FieldObject
{
protected:
	std::string name;
	enum baseType {abstract=-1, Human, Alien};
	int healPoints;
	int maxCreateUnits;
	int flagForConsole;
	int baseType;
	PlayingField* field;
	//sf::Sprite sprite;
	enum unitKind {warrior, stormtrooper,medic};
public:
	Base(int maxCreateUnits = 1, PlayingField* field_ = nullptr);
	//virtual void render(sf::RenderWindow& window) const;
	void setMaxCreateUnits(int newMax);
	int getConsoleFlag() const;
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
	
	void makeUnits(int numb, std::string kind);
};

class HumanBase : public Base
{
public:
	HumanBase();
	std::string info();
	FieldObject* copy();
	//void makeUnits(int numb, int kind);
};

class AlienBase : public Base
{
public:
	AlienBase();
	std::string info();
	FieldObject* copy();
	//void makeUnits(int numb, int kind);
};
