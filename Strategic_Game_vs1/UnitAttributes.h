#pragma once
#include <iostream>
class UnitAttributes
{
private:
	int healPoints;
	int armorPoints;
	int damage;
	int range;
public:
	void setAll(int hp, int ap, int dmg, int r);
	int getHealPoints() const;
	int getArmorPoints() const;
	int getDamage() const;
	int getRange() const;

	void setHealPoints(int hp);
	void setArmorPoints(int ap);
	void setDamage(int dmg);
	void setRange(int r);

	friend std::ostream& operator<<(std::ostream& os, const UnitAttributes& ua) {
		return os << "[" << ua.healPoints << "]";
	}
};
