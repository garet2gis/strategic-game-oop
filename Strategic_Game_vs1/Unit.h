#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include "UnitAttributes.h"

class FieldObject
{
protected:
	std::string name;
	std::string shortName;
	bool canMove;
public:
	virtual bool isMovable() {
		return canMove;
	}
	virtual std::string getName() = 0;
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
	virtual std::string getShortName()=0;
};


class Unit : public FieldObject
{
protected:
	//int flagForConsole;
	UnitAttributes attributes;
	int number;
	static int count;
public:
	Unit();
	virtual std::string info() = 0;
	virtual std::string getName();
	virtual std::string getShortName();
	//virtual void render(sf::RenderWindow& window) const;
	virtual FieldObject* copy() = 0;
	friend std::ostream& operator<<(std::ostream& os, const Unit& fu) {
		return os << "Nuber: ["<< number<<"]";
	}
};

/*class Structure : public Unit
{
public:
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
};
*/
class Warrior : public Unit
{
public:
	virtual std::string info() =0;
	virtual FieldObject* copy() =0;
};

class Shooter : public Unit
{
public:
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
};
class Buffer : public Unit
{
public:
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
};


/*class HumanStructure : public Structure
{

};


class AlienStructure : public Structure
{

};
*/

class WarriorTank :public Warrior
{
public:
	WarriorTank();
	FieldObject* copy()
	{
		return new WarriorTank(*this);
	}
	std::string info();

};


class WarriorDamager : public Warrior
{
public:
	WarriorDamager();
	FieldObject* copy()
	{
		return new WarriorDamager(*this);
	}
	std::string info();

};


class ShooterTank :public Shooter
{
public:
	ShooterTank();
	FieldObject* copy()
	{
		return new ShooterTank(*this);
	}
	std::string info();

};




class ShooterDamager :public Shooter
{
public:
	ShooterDamager();
	FieldObject* copy()
	{
		return new ShooterDamager(*this);
	}
	std::string info();

};



class BufferTank :public Buffer
{
public:
	BufferTank();
	FieldObject* copy()
	{
		return new BufferTank(*this);
	}
	std::string info();

};



class BufferDamager :public Buffer
{
public:
	BufferDamager();
	FieldObject* copy()
	{
		return new BufferDamager(*this);
	}
	std::string info();

};


/*class HumanStructure : public Structure
{

};
*/