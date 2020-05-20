#pragma once
#include <string>
#include <iostream>
#include <unordered_map>

//� ��������� �������� ������ � ���� �����
class SharedUnit {   
private:
	std::string color;
	//sf::Sprite sprite;

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
	Flyweight(const SharedUnit* shared_units) : shared_unit(new SharedUnit(*shared_units)){}
	Flyweight(const Flyweight& other) : shared_unit(new SharedUnit(*other.shared_unit)){}
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
	 //���������� ��� ������ ��������� ��� ������� ���������
	std::string GetKey(const SharedUnit& ss) const
	{
		return ss.getColor();
	}
public:
	FlyweightFactory(std::initializer_list<SharedUnit> share_units);//����� ������� ������ ��������� ��� ������������� ����������
	// ���������� ������������ �������� � �������� ���������� ��� ������� �����.
	Flyweight GetFlyweight(const SharedUnit& shared_unit);
	void ListFlyweights() const;
};

