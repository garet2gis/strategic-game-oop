#pragma once
#include "Unit.h"

//в легковесе хранятса спрайт и цвет юнита
class SharedUnit {   
private:
	std::string color;
	sf::Sprite sprite;

public:
	SharedUnit(std::string color) {
		this->color = color;
	}
	friend std::ostream& operator<<(std::ostream& os, const SharedUnit& fu) {
		return os << "[" << fu.color << "]";
	}
	std::string getColor() const {
		return color;
	}
};

class Flyweight
{
private:
	SharedUnit* shared_unit;
public:
	Flyweight(const SharedUnit* shared_units) : shared_unit(new SharedUnit(*shared_units))
	{
	}
	Flyweight(const Flyweight& other) : shared_unit(new SharedUnit(*other.shared_unit))
	{
	}
	~Flyweight()
	{
		delete shared_unit;
	}
	SharedUnit* getSharedUnit() const {
		return shared_unit;
	}
};

class FlyweightFactory
{
private:
	std::unordered_map<std::string, Flyweight> flyweights_;

	 //Возвращает хеш строки Легковеса для данного состояния

	std::string GetKey(const SharedUnit& ss) const
	{
		return ss.getColor();
	}

public:
	FlyweightFactory(std::initializer_list<SharedUnit> share_units) //чтобы заранее задать легковесы при инициализации приложения
	{
		for (const SharedUnit& ss : share_units)
		{
			this->flyweights_.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
		}
	}


	// Возвращает существующий Легковес с заданным состоянием или создает новый.
	Flyweight GetFlyweight(const SharedUnit& shared_unit)
	{
		std::string key = this->GetKey(shared_unit);
		if (this->flyweights_.find(key) == this->flyweights_.end())
		{
			std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
			this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_unit)));
		}
		else
		{
			std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
		}
		return this->flyweights_.at(key);
	}
	void ListFlyweights() const
	{
		size_t count = this->flyweights_.size();
		std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
		for (std::pair<std::string, Flyweight> pair : this->flyweights_)
		{
			std::cout << pair.first << "\n";
		}
	}
};


class FullUnit //контекстный класс для связи легковеса с уникальными юнитами
{
private:
	Unit* uniqueUnit;
	Flyweight* sharedUnit;

public:
	FullUnit(Unit* uniqueUnit, Flyweight* sharedUnit) {
		this->uniqueUnit = uniqueUnit;
		this->sharedUnit = sharedUnit;
	}
	Unit* getUniqueUnit() const{
		return uniqueUnit;
	}
	Flyweight* getSharedUnit() const {
		return sharedUnit;
	}
};