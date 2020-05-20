#pragma once
#include "FieldObject.h"

class Landscape : public FieldObject
{

public:
	virtual ~Landscape() = default;
	virtual bool canHoldCreature() const = 0;
	virtual FieldObject* copy() = 0;
	virtual std::string info() = 0;
	bool isMovable() {
		return canMove;
	}
	virtual std::string getName() {
		return name;
	}
	virtual std::string getShortName() {
		return shortName;
	}
};


class LandscapeProxy : public Landscape
{
private:
	Landscape* landscape;
public:
	LandscapeProxy(Landscape* landscape)
	{
		this->landscape = landscape;
		canMove = false;
	}
	virtual std::string getName() {
		return landscape->getName();
	}
	virtual std::string getShortName() {
		return landscape->getShortName();
	}
	virtual std::string info() {
		return landscape->info();
	}
	bool canHoldCreature() const override
	{
		return landscape->canHoldCreature();
	}
	FieldObject* copy()
	{
		return new LandscapeProxy(landscape);
	}
};

class Mountains : public Landscape
{
public:
	Mountains();
	bool canHoldCreature() const;
	FieldObject* copy();
	virtual std::string info();
};


class Ground : public Landscape
{
public:
	Ground();
	bool canHoldCreature() const;
	FieldObject* copy();
	virtual std::string info();
};


class Water : public Landscape
{
public:
	Water();
	bool canHoldCreature() const;
	FieldObject* copy();
	virtual std::string info();
};

