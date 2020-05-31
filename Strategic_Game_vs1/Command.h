#pragma once

#include "GameFacade.h"
#include "ClientInput.h"

class Command
{
protected:
	GameFacade* facade;
	ClientInput* input;
public:
	virtual ~Command() = default;
	virtual void execute() = 0;
};


class MoveCommand : public Command {

public:
	MoveCommand(GameFacade* facade, ClientInput* move) {
		this->facade = facade;
		this->input = move;
	}
	void execute() {
		this->facade->moveUnit(input);
	}


};



/*class AttackCommand : public Command {
protected:
	AttackClientData* data;
public:
	AttackCommand(GameFacade* receiverGameFacade, AttackClientData* data) {
		this->receiverGameFacade = receiverGameFacade;
		this->data = data;
	}

	void execute() override {
		this->receiverGameFacade->attack(data);
	}
};*/

class AddUnitCommand : public Command {
public:
	AddUnitCommand(GameFacade* receiverGameFacade, ClientInput* input) {
		this->facade = receiverGameFacade;
		this->input = input;
	}

	void execute() override {
		this->facade->addUnit(input);
	}
};

class StartNewGameCommand : public Command
{
public:
	StartNewGameCommand(GameFacade* receiverGameFacade, ClientInput* input)
	{
		this->facade = receiverGameFacade;
		this->input = input;
	}

	void execute() override {
		this->facade->startNewGame(input);
	}
};

class GetInfoCommand : public Command
{
public:
	GetInfoCommand(GameFacade* receiverGameFacade, ClientInput* input)
	{
		this->facade = receiverGameFacade;
		this->input = input;
	}
	void execute() override {
		this->facade->getInfo(input);
	}
};
