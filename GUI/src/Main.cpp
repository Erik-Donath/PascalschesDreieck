#include <cstdlib>
#include <fstream>
#include <iostream>

#include "Defines.hpp"
#include "Triangle.hpp"

i32 main(i32 argc, char* argsv[]) {
	u32 n = 2;
	std::cout << "Gebe die Hochzahl an: ";
	std::cin >> n;
	std::vector<std::vector<u32>> tri = createTriangle(n);

	if (n < 255) {
		std::cout << "Das Pascalsche Dreieck: " << std::endl;
		for (std::vector<u32> row : tri) {
			for (u32 value : row)
				std::cout << value << " ";
			std::cout << std::endl;
		}
	}
	else std::cout << "Das Pascalsche Dreieck wird nicht angezeigt." << std::endl;
	std::system("echo hallo && pause");
}