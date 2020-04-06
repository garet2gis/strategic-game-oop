#pragma once
#include <iostream>
#include "Unit.h"
#include <SFML/Graphics.hpp>

class PlayingField
{
private:
	int width;
	int length;
	int maxNumberOfElements;
	int currentNumberOfElements;
	bool checkCoordinate(int x, int y) const;

	class Cell
	{
	private:

		FieldObject* fieldObject_;
		//Landscape* landscape_;
	public:
		Cell();
		Cell(const Cell& copyCell);
		Cell& operator=(const Cell& copyCell);

		Cell(Cell&& copyCell);
		Cell& operator=(Cell&& copyCell);

		FieldObject* getObjectPtr();
		bool isOccupied();
		void setObjectPtr(FieldObject* newObjectPtr);
		//void setLandscape(int newLandscape);
	};

	Cell** field;
public:
	PlayingField(int width_ = 20, int length_ = 20);
	PlayingField(const PlayingField& copyField);
	PlayingField(PlayingField&& copyField);
	PlayingField& operator=(const PlayingField& playingField);
	PlayingField& operator=(PlayingField&& playingField);

	~PlayingField();

	void addObject(FieldObject* newObject, int X = -1, int Y = -1);

	void moveObject(int X_old, int Y_old, int X_new, int Y_new);

	void deleteObject(int X, int Y);

	void showConsoleField();
	int getCurrentElements();
	void setMaxNumberOfElements(int newValue);

};