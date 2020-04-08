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
	//Добавляем юнита в первую попавшуюся клетку
	field1.addObject(hw);
	//Добавляем юнита по координатам
	field1.addObject(hs, 2, 2);
	//Добавляем юнита в клетку, которая выходит за границы поля
	field1.addObject(hw,4, 4);
	field1.addObject(hw, -1, 0);

	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";
	//Перемещаем юнита из клетки 0.0 в клетку 1.0
	field1.moveObject(0, 0, 1, 0);
	std::cout << "Field 1:\n"; field1.showConsoleField();	std::cout << "\n";

	//Создаем новое поле
	PlayingField field2(9, 9);

	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	//Присваиваем новому полю старое
	field2 = field1;

	std::cout << "Field 2:\n"; field2.showConsoleField(); std::cout << "\n";
	//Удаляем из предыдущего поля юнита
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



/*using namespace sf;//включаем пространство имен sf, чтобы постоянно не писать sf::
int main()
{
	RenderWindow window(sf::VideoMode(640, 480), "window"); //увеличили для удобства размер окна

	Image heroimage; //создаем объект Image (изображение)
	heroimage.loadFromFile("images/hero.png");//загружаем в него файл

	Texture herotexture;//создаем объект Texture (текстура)
	herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)

	Sprite herosprite;//создаем объект Sprite(спрайт)
	herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
	herosprite.setPosition(0, 0);//задаем начальные координаты появления спрайта
	herosprite.setTextureRect(IntRect(0, 192, 96, 96));//получили нужный нам прямоугольник с котом

	float CurrentFrame = 0;//хранит текущий кадр
	Clock clock; //создаем переменную времени, т.о. привязка ко времени(а не мощности/загруженности процессора). 

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах
		clock.restart(); //перезагружает время
		time = time / 800; //скорость игры

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 96, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
			herosprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 192, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96

			herosprite.move(0.1 * time, 0);//происходит само движение персонажа вправо

		}


		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 288, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
			herosprite.move(0, -0.1 * time);//происходит само движение персонажа вверх
		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) {
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(96 * int(CurrentFrame), 0, 96, 96)); //проходимся по координатам Х. получается 96,96*2,96*3 и опять 96
			herosprite.move(0, 0.1 * time);//происходит само движение персонажа вниз
		}
		window.clear();
		window.draw(herosprite);//выводим спрайт на экран
		window.display();
	}

	return 0;
}*/