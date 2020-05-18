#include "Unit.h"

Unit::Unit() {
	name = "Abstract Unit";
	shortName = "A_U";
	healPoints = 0;
	armorPoints = 0;
	damage = 0;
	alreadyMooved = 0;
}

HumanWarriorTank::HumanWarriorTank() {
	name = "Human Warrior Tank";
	shortName = "H_W_t";
	healPoints = 300;
	armorPoints = 100;
	damage = 40;
	alreadyMooved = false;
	range = 0;
}

HumanWarriorDamager::HumanWarriorDamager() {
	name = "Human Warrior Damager";
	shortName = "H_W_d";
	healPoints = 220;
	armorPoints = 70;
	damage = 60;
	alreadyMooved = false;
	range = 0;
}

HumanShooterStormtrooper::HumanShooterStormtrooper() {
	name = "Human Shooter Stormtrooper";
	shortName = "H_S_st";
	healPoints = 175;
	armorPoints = 60;
	damage = 60;
	alreadyMooved = false;
	range = 1;
}

HumanShooterSniper::HumanShooterSniper() {
	name = "Human Shooter Sniper";
	shortName = "H_S_sn";
	healPoints = 150;
	armorPoints = 50;
	damage = 150;
	alreadyMooved = false;
	range = 3;
}

HumanMedicTank::HumanMedicTank() {
	name = "Human Medic Tank";
	shortName = "H_M_t";
	healPoints = 250;
	armorPoints = 60;
	damage = 35;
	healDmg = 40;
	alreadyMooved = false;
	range = 0;
}


HumanMedicRange::HumanMedicRange() {
	name = "Human Medic Range";
	shortName = "H_M_r";
	healPoints = 150;
	armorPoints = 50;
	damage = 30;
	healDmg = 50;
	alreadyMooved = false;
	range = 2;
}

AlienWarriorTank::AlienWarriorTank() {
	name = "Alien Warrior Tank";
	shortName = "A_W_t";
	healPoints = 300;
	armorPoints = 100;
	damage = 40;
	alreadyMooved = false;
	range = 0;
}

AlienWarriorDamager::AlienWarriorDamager() {
	name = "Alien Warrior Damager";
	shortName = "A_W_d";
	healPoints = 220;
	armorPoints = 70;
	damage = 60;
	alreadyMooved = false;
	range = 0;
}

AlienShooterStormtrooper::AlienShooterStormtrooper() {
	name = "Alien Shooter Stormtrooper";
	shortName = "A_S_st";
	healPoints = 175;
	armorPoints = 60;
	damage = 60;
	alreadyMooved = false;
	range = 1;
}

AlienShooterSniper::AlienShooterSniper() {
	name = "Alien Shooter Sniper";
	shortName = "A_S_sn";
	healPoints = 150;
	armorPoints = 50;
	damage = 150;
	alreadyMooved = false;
	range = 3;
}

AlienMedicTank::AlienMedicTank() {
	name = "Alien Medic Tank";
	shortName = "A_M_t";
	healPoints = 250;
	armorPoints = 60;
	damage = 35;
	healDmg = 40;
	alreadyMooved = false;
	range = 0;
}


AlienMedicRange::AlienMedicRange() {
	name = "Alien Medic Range";
	shortName = "A_M_r";
	healPoints = 150;
	armorPoints = 50;
	damage = 30;
	healDmg = 50;
	alreadyMooved = false;
	range = 2;
}

//Human
std::string HumanWarriorTank::info() {
	std::string out = "Info: race: Human, class: Warrior, specialization: Tank, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string HumanWarriorDamager::info() {
	std::string out = "Info: race: Human, class: Warrior, specialization: Damager, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string HumanShooterStormtrooper::info() {
	std::string out = "Info: race: Human, class: Shooter, specialization: Stormtrooper, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string HumanShooterSniper::info() {
	std::string out = "Info: race: Human, class: Shooter, specialization: Sniper, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string HumanMedicTank::info() {
	std::string out = "Info: race: Human, class: Medic, specialization: Tank, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}
std::string HumanMedicRange::info() {
	std::string out = "Info: race: Human, class: Medic, specialization: Range, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

//Alien

std::string AlienWarriorTank::info() {
	std::string out = "Info: race: Alien, class: Warrior, specialization: Tank, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string AlienWarriorDamager::info() {
	std::string out = "Info: race: Alien, class: Warrior, specialization: Damager, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string AlienShooterStormtrooper::info() {
	std::string out = "Info: race: Alien, class: Shooter, specialization: Stormtrooper, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string AlienShooterSniper::info() {
	std::string out = "Info: race: Alien, class: Shooter, specialization: Sniper, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}

std::string AlienMedicTank::info() {
	std::string out = "Info: race: Alien, class: Medic, specialization: Tank, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}
std::string AlienMedicRange::info() {
	std::string out = "Info: race: Alien, class: Medic, specialization: Range, current healpoints: " + std::to_string(healPoints) + ", current armorpoints: " + std::to_string(armorPoints) + ", current damage: " + std::to_string(damage) + ", current range: " + std::to_string(range) + "\n";
	return out;
}
std::string Unit::getShortName() {
	return shortName;
}

//getName
//Human
std::string HumanWarriorTank::getName() {
	return name;
}

std::string HumanWarriorDamager::getName() {
	return name;
}
std::string HumanShooterStormtrooper::getName() {
	return name;
}

std::string HumanShooterSniper::getName() {
	return name;
}

std::string HumanMedicTank::getName() {
	return name;
}
std::string HumanMedicRange::getName() {
	return name;
}

//Alien

std::string AlienWarriorTank::getName() {
	return name;
}

std::string AlienWarriorDamager::getName() {
	return name;
}

std::string AlienShooterStormtrooper::getName() {
	return name;
}

std::string AlienShooterSniper::getName() {
	return name;
}

std::string AlienMedicTank::getName() {
	return name;
}
std::string AlienMedicRange::getName() {
	return name;
}