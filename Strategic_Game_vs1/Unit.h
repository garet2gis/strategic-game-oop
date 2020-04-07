#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

class FieldObject
{
protected:
	std::string name;
public:
	virtual std::string getName() = 0;
	virtual std::string info() = 0;
	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};

class Unit : public FieldObject
{
protected:
	std::string name;
	int healPoints;
	int armorPoints;
	int damage;
	bool alreadyMooved;
	int flagForConsole;
	//sf::Sprite sprite;
public:
	Unit();
	Unit(const Unit& copyUnit);
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	//virtual void render(sf::RenderWindow& window) const;

	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};

class Structure : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};

class Warrior : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};

class Stormtrooper : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};
class Medic : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual int getConsoleFlag() const = 0;
	virtual FieldObject* copy() = 0;
};


/*class HumanStructure : public Structure
{

};


class AlienStructure : public Structure
{

};
*/

class HumanWarrior : public Warrior
{
public:
	HumanWarrior();
	FieldObject* copy()
	{
		return new HumanWarrior(*this);
	}
	std::string info();
	std::string getName();
	int getConsoleFlag() const 
	{
		return flagForConsole;
	}
};

class HumanStormtrooper : public Stormtrooper
{
public:
	HumanStormtrooper();
	FieldObject* copy() {
		return new HumanStormtrooper(*this);
	}
	std::string info();
	std::string getName();
	int getConsoleFlag() const
	{
		return flagForConsole;
	}
};

class HumanMedic : public Medic
{
public:
	HumanMedic();
	FieldObject* copy() {
		return new HumanMedic(*this);
	}
	std::string info();
	std::string getName();
	int getConsoleFlag() const
	{
		return flagForConsole;
	}
};

class AlienWarrior : public Warrior
{
public:
	AlienWarrior();
	FieldObject* copy() {
		return new AlienWarrior(*this);
	}
	std::string info();
	std::string getName();
	int getConsoleFlag() const
	{
		return flagForConsole;
	}
};

class AlienStormtrooper : public Stormtrooper
{
public:
	AlienStormtrooper();
	std::string getName();
	FieldObject* copy() {
		return new AlienStormtrooper(*this);
	}
	std::string info();
	int getConsoleFlag() const
	{
		return flagForConsole;
	}
};

class AlienMedic : public Medic
{
public:
	AlienMedic();
	FieldObject* copy() {
		return new AlienMedic(*this);
	}
	std::string info();
	std::string getName();
	int getConsoleFlag() const
	{
		return flagForConsole;
	}

};

class ArmyFactory
{
public:
	virtual Warrior* createWarrior() = 0;
	virtual Stormtrooper* createStormtrooper() = 0;
	virtual Medic* createMedic() = 0;
	virtual ~ArmyFactory() {}
};

class HumanArmyFactory : public ArmyFactory
{
public:
	Warrior* createWarrior(){
		return new HumanWarrior();
	}
	Stormtrooper* createStormtrooper() {
		return new HumanStormtrooper();
	}
	Medic* createMedic() {
		return new HumanMedic();
	}
};

class AlienArmyFactory : public ArmyFactory
{
public:
	Warrior* createWarrior() {
		return new AlienWarrior;
	}
	Stormtrooper* createStormtrooper() {
		return new AlienStormtrooper;
	}
	Medic* createMedic() {
		return new AlienMedic;
	}
};



