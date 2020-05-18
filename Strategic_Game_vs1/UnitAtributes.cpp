#include "UnitAtributes.h"


void UnitAtributes::setAll(int hp, int ap, int dmg, int r) {
	healPoints = hp;
	armorPoints = ap;
	damage = dmg;
	range = r;
}

int UnitAtributes::getHealPoints() const{
	return healPoints;
}
int UnitAtributes::getArmorPoints() const{
	return armorPoints;
}
int UnitAtributes::getDamage() const {
	return damage;
}
int UnitAtributes::getRange() const {
	return range;
}

void UnitAtributes::setHealPoints(int hp) {
	healPoints = hp;
}
void UnitAtributes::setArmorPoints(int ap) {
	armorPoints = ap;
}
void UnitAtributes::setDamage(int dmg) {
	damage = dmg;
}
void UnitAtributes::setRange(int r) {
	range = r;
}