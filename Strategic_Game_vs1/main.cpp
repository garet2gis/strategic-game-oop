//#include <SFML/Graphics.hpp>

/* for second

#include "Base.h"
#include "ArmyFactory.h"
#include "Object.h"
#include "landscapeMapExample.h"
*/
/*

//���������� ������ ���������
void example1() {

	PlayingField field1(10, 10); //�� ��������� �������� ���������
	field1.setLandscape(mapExample_10x10); // ������������ �������

	Base* base = new Base(10, &field1, 1,2); // ��������� ���� ������� ����� �������� ����������� 10 ������
	if (!base->isAlive()) {
		delete base;
		return;
	}

	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Landscape 1:\n"; field1.showConsoleLandscape();	std::cout << "\n";
	
	//������� ����� �������� �����
	std::cout << "Create unit with existing flyweight\n";
	base->createUnit("W_t", "red", 1, 1); //�� � ������������ ���� ��� ��� ������ �������� � ���������� �������� �����, �� �� �� ��������� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Create unit with new flyweight\n";
	base->createUnit("B_d", "pink", 2, 2);//� ������ ������ ��������� ����� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	std::cout << "Create unit with previous flyweight\n";
	base->createUnit("S_d", "pink", 2, 5);//� ������ ������ ����� ����������� ���������� ��������
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";

	std::cout << " END\n";
}


//������ ������ ���������� ������ �������� ��������� � ��� ���� ������������ ���������� ������
void example2() {
	PlayingField field(10, 10); //�� ��������� �������� ���������
	field.setLandscape(mapExample_10x10); // ������������ �������

	Base* base = new Base(3, &field, 1, 2); // ��������� ���� ������� ����� ������� �������� 3 �����
	if (!base->isAlive()) {
		delete base;
		return;
	}
	std::cout << "Creating 4 unit, but base has a limit of 4\n";
	Unit* wt0 = base->createUnit("W_t", "red", 1, 1);
	Unit* wt1 = base->createUnit("W_t", "red", 1, 2);
	Unit* wd0 = base->createUnit("W_d", "red", 1, 3);
	std::cout << "Cant create last unit\n";
	Unit* wd1 = base->createUnit("W_d", "yellow", 1, 4); //4 ����� ���� ������� �� �����

	HealBooster* hb = new HealBooster(); //������� ������� � �������� �� ����

	field.addObject(hb, 3, 3);

	std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";


	//������������ ������ �������� ���������

	std::cout << "Use heal boost on tank\n";
	*wt0 += hb; //������ ��������� ���� ������� ���������� 50 �� 
	//std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";
	std::cout << "\n";
	std::cout << "Use heal boost on damager\n";
	*wd0 += hb;//������ ��������� ���� ������� ���������� 30 �� 
}

//������ ������ ���������� ������ �������� ������ � ��� ���� ��������� �� ������ �����
void example3() {
	PlayingField field(10, 10); //�� ��������� �������� ���������
	field.setLandscape(mapExample_10x10); // ������������ �������
	//PlayingField field1(10, 12);
	//field = field1;
	Base* base1 = new Base(3, &field, 1, 100); // ��������� ���� �� ������������ �����������
	if (!base1->isAlive()) {
		delete base1;
	}

	Base* base = new Base(3, &field, 0, 5);
	if (!base->isAlive()) {
		delete base;
		return;
	}
	Unit* wt = base->createUnit("W_t", "red", 3, 6);

	std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";

	std::cout << "Landscape 1:\n"; field.showConsoleLandscape();	std::cout << "\n";
	

	std::cout << "Interaction of the unit with the landscape\n";
	field.checkUnitAndLandscape(wt);

	std::cout << "Field 1:\n"; field.showConsoleField();	std::cout << "\n";
	std::cout << "Landscape 1:\n"; field.showConsoleLandscape();	std::cout << "\n";

}
*/
#include "Handler.h"

int main() {

	//example1();
	//example2();
	//example3();

	GameFacade* facade = new GameFacade();

	StartGame* chain = new StartGame(facade);
	chain->setNext(new AddUnit(facade))->setNext(new MoveUnit(facade))->
		setNext(new Attack(facade))->setNext(new GetInfo(facade));

	ClientInput* input = new ClientInput();
	input->setStart(10,10,20);
	chain->handle(input);

	input->setAddUnit(1, 1, "W_t", "white");
	chain->handle(input);


	input->setAddUnit(7, 7, "W_t", "red");
	chain->handle(input);


	input->setMove(1, 1, 4, 4);
	chain->handle(input);

	input->setGetInfo(4, 4);
	chain->handle(input);

	return 0;
}

