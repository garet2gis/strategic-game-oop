#include "Unit.h"
#include <iostream>


class Component {
protected:
	Component* parent;
public:
	virtual ~Component(){}
	void setParent(Component* newParent) {
		parent = newParent;
	}
	Component* getParent() const {
		return parent;
	}
	virtual void add(Component* component)=0;
	virtual void remove(Component* component)=0;
	virtual void addUnit(FieldObject* unit)=0;
	virtual void removeUnit(FieldObject* unit)=0;
	virtual Component* getChild(int index) = 0;
	virtual std::string treeView()=0;
};

class Composite :public Component {
protected:
	std::vector<Component*> children;
public:
	std::string treeView() {
		std::string out = "";
		out += "<";
		for (std::vector<Component*>::iterator iter = children.begin(); iter != children.end(); iter++) {
			out += (*iter)->treeView();
		}
		out += ">\n";
		return out;
	}
	Component* getChild(int index) {
		if (index > children.size())
			return nullptr; //size error
		return children[index];
	}
	void Add(Component* component) {
		children.push_back(component);
		component->setParent(this);
	}
	void Remove(Component* component) {
		for (unsigned i = 0; i < children.size(); i++) {
			if (children[i] == component)
				children.erase(children.begin() + i);
		}
		component->setParent(nullptr);
	}
	void addUnit(FieldObject* unit) {}
	void removeUnit(FieldObject* unit) {}
};
class Leaf : public Component
{
protected:
	std::vector<FieldObject*> units;
public:
	std::string treeView() {
		std::string out = "";
		out += "<";
		for (auto i : units) {
			out += i->getName() + " ";
		}
		out += ">";
		return out;
	}
	void Add(Component* component) {}
	void Remove(Component* component) {}
	void addUnit(FieldObject* unit) {
		units.push_back(unit);
	}
	Component* getChildren(unsigned int index) {
		return this;
	}
	void removeUnit(FieldObject* unit) {
		int c = 0;
		for (auto i : units) {
			c++;
			if (i == unit) {
				units.erase(units.begin() + c);
			}
		}
	}
	std::vector<FieldObject*> getUnits() {
		return units;
	}
};
