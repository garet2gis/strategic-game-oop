#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>
#include "UnitAttributes.h"
#include "observer_interfaces.h"
#include "FieldObject.h"
#include "Flyweight.h"

class Unit : public FieldObject, IUnit
{
protected:
	Flyweight* fly;
	UnitAttributes attributes;
	int number;
	static int count;
public:
	Unit();
	std::string info() {
		std::cout << attributes;
		return "error69";
	}
	virtual std::string getName();
	virtual std::string getShortName();

	//virtual void render(sf::RenderWindow& window) const;
	virtual FieldObject* copy() = 0;
	/*friend std::ostream& operator<<(std::ostream& os, const Unit& fu) {
		return os << "Number: [" << number << "]";
	}*/

	void attachBase(IBase* base) { this->base = base; }
	bool isMovable() {
		return canMove;
	}
	void iAmDead() {
		if (base) {
			base->onUnitDestroyed(this);
		}
	}
	void setFlyweight(Flyweight* flyweight_) {
		this->fly = flyweight_;
	}
};

class Warrior : public Unit
{
public:

	virtual FieldObject* copy() =0;
};

class Shooter : public Unit
{
public:

	virtual FieldObject* copy() = 0;
};
class Buffer : public Unit
{
public:

	virtual FieldObject* copy() = 0;
};


class WarriorTank :public Warrior
{
public:
	WarriorTank();
	FieldObject* copy()
	{
		return new WarriorTank(*this);
	}
	

};


class WarriorDamager : public Warrior
{
public:
	WarriorDamager();
	FieldObject* copy()
	{
		return new WarriorDamager(*this);
	}


};


class ShooterTank :public Shooter
{
public:
	ShooterTank();
	FieldObject* copy()
	{
		return new ShooterTank(*this);
	}


};


class ShooterDamager :public Shooter
{
public:
	ShooterDamager();
	FieldObject* copy()
	{
		return new ShooterDamager(*this);
	}
};


class BufferTank :public Buffer
{
public:
	BufferTank();
	FieldObject* copy()
	{
		return new BufferTank(*this);
	}
};

class BufferDamager :public Buffer
{
public:
	BufferDamager();
	FieldObject* copy()
	{
		return new BufferDamager(*this);
	}
};

