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
	virtual FieldObject* copy() = 0;
	virtual std::string getShortName()=0;
};

class Unit : public FieldObject
{
protected:
	std::string name;
	std::string shortName;
	int healPoints;
	int armorPoints;
	int damage;
	bool alreadyMooved;
	//int flagForConsole;
	int range;
	//sf::Sprite sprite;
public:
	Unit();
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual std::string getShortName();
	//virtual void render(sf::RenderWindow& window) const;
	virtual FieldObject* copy() = 0;
};

class Structure : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};

class Warrior : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};

class Shooter : public Unit
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};
class Medic : public Unit
{
protected:
	int healDmg;
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
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
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};


class HumanWarriorTank : public HumanWarrior
{
public:
	HumanWarriorTank();
	FieldObject* copy()
	{
		return new HumanWarriorTank(*this);
	}
	std::string info();
	std::string getName();
};

class HumanWarriorDamager : public HumanWarrior
{
public:
	HumanWarriorDamager();
	FieldObject* copy()
	{
		return new HumanWarriorDamager(*this);
	}
	std::string info();
	std::string getName();

};



class HumanShooter  : public Shooter
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};


class HumanShooterSniper : public HumanShooter
{
public:
	HumanShooterSniper();
	FieldObject* copy() {
		return new HumanShooterSniper(*this);
	}
	std::string info();
	std::string getName();

};

class HumanShooterStormtrooper : public HumanShooter
{
public:
	HumanShooterStormtrooper();
	FieldObject* copy() {
		return new HumanShooterStormtrooper(*this);
	}
	std::string info();
	std::string getName();

};

class HumanMedic : public Medic
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};

class HumanMedicTank : public HumanMedic
{
public:
	HumanMedicTank();
	FieldObject* copy() {
		return new HumanMedicTank(*this);
	}
	std::string info();
	std::string getName();

};

class HumanMedicRange : public HumanMedic
{
public:
	HumanMedicRange();
	FieldObject* copy() {
		return new HumanMedicRange(*this);
	}
	std::string info();
	std::string getName();

};





/*class HumanStructure : public Structure
{

};


class AlienStructure : public Structure
{

};
*/

class AlienWarrior : public Warrior
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};


class AlienWarriorTank : public AlienWarrior
{
public:
	AlienWarriorTank();
	FieldObject* copy()
	{
		return new AlienWarriorTank(*this);
	}
	std::string info();
	std::string getName();

};

class AlienWarriorDamager : public AlienWarrior
{
public:
	AlienWarriorDamager();
	FieldObject* copy()
	{
		return new AlienWarriorDamager(*this);
	}
	std::string info();
	std::string getName();

};



class AlienShooter : public Shooter
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};


class AlienShooterSniper : public AlienShooter
{
public:
	AlienShooterSniper();
	FieldObject* copy() {
		return new AlienShooterSniper(*this);
	}
	std::string info();
	std::string getName();

};

class AlienShooterStormtrooper : public AlienShooter
{
public:
	AlienShooterStormtrooper();
	FieldObject* copy() {
		return new AlienShooterStormtrooper(*this);
	}
	std::string info();
	std::string getName();

};

class AlienMedic : public Medic
{
public:
	virtual std::string info() = 0;
	virtual std::string getName() = 0;
	virtual FieldObject* copy() = 0;
};

class AlienMedicTank : public AlienMedic
{
public:
	AlienMedicTank();
	FieldObject* copy() {
		return new AlienMedicTank(*this);
	}
	std::string info();
	std::string getName();

};

class AlienMedicRange : public AlienMedic
{
public:
	AlienMedicRange();
	FieldObject* copy() {
		return new AlienMedicRange(*this);
	}
	std::string info();
	std::string getName();

};

