#pragma once
#include "Unit.h"
class ArmyFactory
{
public:
	virtual Warrior* createWarriorTank() = 0;
	virtual Warrior* createWarriorDamager() = 0;
	virtual Shooter* createShooterSniper() = 0;
	virtual Shooter* createShooterStormtrooper() = 0;
	virtual Medic* createMedicTank() = 0;
	virtual Medic* createMedicRange() = 0;
};

class HumanArmyFactory : public ArmyFactory
{
public:
	Warrior* createWarriorTank() {
		return new HumanWarriorTank;
	}
	Warrior* createWarriorDamager() {
		return new HumanWarriorDamager;
	}
	Shooter* createShooterSniper() {
		return new HumanShooterSniper;
	}
	Shooter* createShooterStormtrooper() {
		return new HumanShooterStormtrooper;
	}
	Medic* createMedicTank() {
		return new HumanMedicTank;
	}
	Medic* createMedicRange() {
		return new HumanMedicRange;
	}
};

class AlienArmyFactory : public ArmyFactory
{
public:
	Warrior* createWarriorTank() {
		return new AlienWarriorTank;
	}
	Warrior* createWarriorDamager() {
		return new AlienWarriorDamager;
	}
	Shooter* createShooterSniper() {
		return new AlienShooterSniper;
	}
	Shooter* createShooterStormtrooper() {
		return new AlienShooterStormtrooper;
	}
	Medic* createMedicTank() {
		return new AlienMedicTank;
	}
	Medic* createMedicRange() {
		return new AlienMedicRange;
	}
};
