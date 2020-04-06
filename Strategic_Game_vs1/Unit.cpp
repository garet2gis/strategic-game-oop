#include "Unit.h"

Unit::Unit() {
	name = "Abstract Unit";
	healPoints = 0;
	armorPoints = 0;
	damage = 0;
	alreadyMooved = 0;
	flagForConsole = 0;
}

Unit::Unit(const Unit& copyUnit) {
	name = copyUnit.name;
	healPoints = copyUnit.healPoints;
	damage = copyUnit.damage;
	alreadyMooved = copyUnit.alreadyMooved;
	flagForConsole = copyUnit.flagForConsole;
}

HumanWarrior::HumanWarrior() {
	name = "Human Warrior";
	healPoints = 200;
	armorPoints = 60;
	damage = 50;
	alreadyMooved = false;
	flagForConsole = 1;
}

HumanStormtrooper::HumanStormtrooper() {
	name = "Human Stormtrooper";
	healPoints = 150;
	armorPoints = 70;
	damage = 30;
	alreadyMooved = false;
	flagForConsole = 2;
}

HumanMedic::HumanMedic() {
	name = "HumanMedic";
	healPoints = 100;
	armorPoints = 40;
	damage = 15;
	alreadyMooved = false;
	flagForConsole = 3;
}
AlienWarrior::AlienWarrior() {
	name = "Alien Warrior";
	healPoints = 150;
	armorPoints = 100;
	damage = 45;
	alreadyMooved = false;
	flagForConsole = -1;
}

AlienStormtrooper::AlienStormtrooper() {
	name = "Alien Stormtrooper";
	healPoints = 125;
	armorPoints = 110;
	damage = 25;
	alreadyMooved = false;
	flagForConsole = -2;

}

AlienMedic::AlienMedic() {
	name = "AlienMedic";
	healPoints = 40;
	armorPoints = 80;
	damage = 20;
	alreadyMooved = false;
	flagForConsole = -3;
}


std::string HumanWarrior::info() {
	std::string out = "Info: race: Human, class: Warrior, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:"+ std::to_string(damage) + "\n";
	return out;
}
std::string HumanStormtrooper::info() {
	std::string out = "Info: race: Human, class: Stormtrooper, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:" + std::to_string(damage) + "\n";
	return out;
}
std::string HumanMedic::info() {
	std::string out = "Info: race: Human, class: Medic, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:" + std::to_string(damage) + "\n";
	return out;
}
std::string AlienWarrior::info() {
	std::string out = "Info: race: Alien, class: Warrior, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:" + std::to_string(damage) + "\n";
	return out;
}
std::string AlienStormtrooper::info() {
	std::string out = "Info: race: Alien, class: Stormtrooper, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:" + std::to_string(damage) + "\n";
	return out;
}
std::string AlienMedic::info() {
	std::string out = "Info: race: Alien, class: Medic, healpoints: " + std::to_string(healPoints) + ", armorpoints: " + std::to_string(armorPoints) + ", damage:" + std::to_string(damage) + "\n";
	return out;
}

std::string HumanWarrior::getName() {
	return name;
}
std::string HumanStormtrooper::getName() {
	return name;
}
std::string HumanMedic::getName() {
	return name;
}
std::string AlienWarrior::getName() {
	return name;
}
std::string AlienStormtrooper::getName() {
	return name;
}
std::string AlienMedic::getName() {
	return name;
}
