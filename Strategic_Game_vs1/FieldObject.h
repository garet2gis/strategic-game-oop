#pragma once
# include <string>

class FieldObject
{
protected:
	std::string name;
	std::string shortName;
	bool canMove = false;
public:
	virtual bool isMovable() = 0;
	virtual std::string getName() = 0;
	virtual std::string info() = 0;
	virtual FieldObject* copy() = 0;
	virtual std::string getShortName() = 0;
};