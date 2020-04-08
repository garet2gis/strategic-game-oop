//#include <SFML/Graphics.hpp>
#include "Field.h"
#include "ArmyFactory.h"
//#include "Base.h"

void example1() {

	PlayingField field1(3, 3);
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";

	ArmyFactory* humanFactory = new HumanArmyFactory();
	Warrior* hw = humanFactory->createWarriorTank();

	Shooter* hs = humanFactory->createShooterSniper();
	//��������� ����� � ������ ���������� ������
	field1.addObject(hw);
	//��������� ����� �� �����������
	field1.addObject(hs, 2, 2);
	//��������� ����� � ������, ������� ������� �� ������� ����
	field1.addObject(hw,4, 4);
	field1.addObject(hw, -1, 0);

	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	//���������� ����� �� ������ 0.0 � ������ 1.0
	field1.moveObject(0, 0, 1, 0);
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";

	//������� ����� ����
	PlayingField field2(9, 9);

	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	//����������� ������ ���� ������
	field2 = field1;

	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	//������� �� ����������� ���� �����
	field1.deleteObject(2,2);
	std::cout << "Field 1:\n"; field1.showConsoleField(); std::cout << "\n";
	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	std::cout << " END\n";
}



int main() {
	example1();
	//example2();
	//example3();
	return 0;
}



/*using namespace sf;//�������� ������������ ���� sf, ����� ��������� �� ������ sf::
int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "window"); //��������� ��� �������� ������ ����

	Image heroimage; //������� ������ Image (�����������)
	heroimage.loadFromFile("images/hero.png");//��������� � ���� ����

	Texture herotexture;//������� ������ Texture (��������)
	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)

	Sprite herosprite;//������� ������ Sprite(������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setPosition(0, 0);//������ ��������� ���������� ��������� �������
	herosprite.setTextureRect(IntRect(0, 192, 96, 96));//�������� ������ ��� ������������� � �����

	float CurrentFrame = 0;//������ ������� ����
	Clock clock; //������� ���������� �������, �.�. �������� �� �������(� �� ��������/������������� ����������). 

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds(); //���� ��������� ����� � �������������
		clock.restart(); //������������� �����
		time = time / 800; //�������� ����

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96
			herosprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96

			herosprite.move(0.1 * time, 0);//���������� ���� �������� ��������� ������

		}


		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96
			herosprite.move(0, -0.1 * time);//���������� ���� �������� ��������� �����
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
			if (CurrentFrame > 3) CurrentFrame -= 3; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); //���������� �� ����������� �. ���������� 96,96*2,96*3 � ����� 96
			herosprite.move(0, 0.1 * time);//���������� ���� �������� ��������� ����
		}
		window.clear();
		window.draw(herosprite);//������� ������ �� �����
		window.display();
	}

	return 0;
}*/