#include "field.h"
#include <iostream>


class Component {
protected:
	Component* parent;
public:
	virtual ~Component(){}
	void setParent(Component* newParent);
	Component* getParentPtr() const;
	virtual void add(Component* component);
	virtual void remove(Component* component);
	virtual void addUnit(FieldObject* unit);
	virtual void removeUnit(FieldObject* unit);
};

class Composite :public Component {
protected:
	std::vector<Component*> children;
public:

};