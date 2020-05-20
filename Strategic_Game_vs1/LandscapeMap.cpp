/*#include "LandscapeMap.h"
void LandscapeMap::fillMap(std::string stringMap) {

	if (stringMap.size() < width * length) {
		std::cout << "String landscape map is smaller, than field size\n";
		return;
	}
	for (unsigned int i = 0; i < width; i++) {
		for (unsigned int j = 0; j < length; j++) {
			if (stringMap[i + j] == 'G') {
				map[i][j] = LandscapeProxy(new Ground);
				break;
			}
			else if (stringMap[i + j] == 'W') {
				map[i][j] = LandscapeProxy(new Water);
				break;
			}
			else if (stringMap[i + j] == 'M') {
				map[i][j] = LandscapeProxy(new Mountains);
				break;
			}
		}
	}
}

void  LandscapeMap::fillMapRandomly() {
	for (unsigned int i = 0; i < width; i++) {

		for (unsigned int j = 0; j < length; j++) {
			srand(12);
			int random_land = rand() % 2;
			switch (1) {
			case(ground): {
				map[i][j] = LandscapeProxy(new Ground);
				break;
			}
			case(water): {
				map[i][j] = LandscapeProxy(new Water);
				break;
			}
			case(mountain): {
				map[i][j] = LandscapeProxy(new Mountains);
				break;
			}
			}
		}
	}
}*/