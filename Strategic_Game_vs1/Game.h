#pragma once

#include "Field.h"
#include "Base.h"

//#include "landscapeMapExample.h"

class Game
{
private:
	PlayingField* field;
	std::map<bool, Base*> bases;

public:
	Game(unsigned width, unsigned length, unsigned maxFieldObjects) {
		field = new PlayingField(width,length);
		field->setMaxNumberOfElements(maxFieldObjects);
		std::vector<char> mapExample_10x10 = {
'G', 'G', 'G', 'M', 'M', 'M','M', 'M', 'G','G',
'G', 'G', 'G', 'G', 'M', 'M','M', 'G', 'G','G',
'G', 'G', 'G', 'G', 'M', 'M','G', 'G', 'G','G',
'G', 'G', 'G', 'G', 'G', 'M','G', 'G', 'G','G',
'G', 'G', 'G', 'G', 'G', 'G','G', 'G', 'G','G',
'G', 'G', 'G', 'W', 'W', 'G','G', 'G', 'G','G',
'G', 'G', 'G', 'W', 'W', 'G','G', 'G', 'G','G',
'G', 'G', 'W', 'W', 'W', 'G','G', 'G', 'G','G',
'G', 'G', 'W', 'W', 'G', 'G','G', 'G', 'G','G',
'G', 'G', 'G', 'G', 'G', 'G','G', 'G', 'G','G',
		};

		field->setLandscape(mapExample_10x10);
	}

	void addBase(int row, int col,int maxUnits,bool curPlayer) {
		Base* base = new Base(maxUnits, field,row, col);
		if (!base->isAlive()) {
			delete base;
			return;
		}
		bases[curPlayer] = base;
	}

	void addUnit(int row, int col, std::string unitType,std::string color, bool curPlayer) {
		if (bases[curPlayer]) {
			bases[curPlayer]->createUnit(unitType, color, row, col);
		}
	}

	void moveUnit(int X_old, int Y_old, int X_new, int Y_new,bool curPlayer) {
		bases[curPlayer]->moveUnit(X_old, Y_old,  X_new, Y_new);
	}

	void attack(){}//in process
		std::string getBaseInfo(int curPlayer) {
		
	}

	bool isPlayerAlive(int curPlayer) {
		return bases[curPlayer]->isAlive();
	}

	void showField() {
		std::cout << "Field:\n"; field->showConsoleField(); std::cout << "\n";
		std::cout << "Landscape:\n"; field->showConsoleLandscape(); std::cout << "\n";
	}

	std::string getInfoAboutCell(unsigned row,unsigned col) { //in process
		std::string out = field->getInfoCell(row,col);
		return out;
	}


};

