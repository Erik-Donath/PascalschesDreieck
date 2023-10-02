#include "Triangle.hpp"

std::vector<std::vector<u32>> createTriangle(u32 n) {
	std::vector<std::vector<u32>> tri;

	std::vector<u32> firstRow;
	firstRow.push_back(1);
	tri.push_back(firstRow);

	for (u32 row = 1; row <= n; row++) {
		std::vector<u32> current;

		for (u32 i = 0; i <= row; i++) {
			u32 v1 = ((i32)i - 1 >= 0) ? tri[row - 1][i - 1] : 0;
			u32 v2 = ((i32)i < row)    ? tri[row - 1][i + 0] : 0;
			current.push_back(v1 + v2);
		}

		tri.push_back(current);
	}
	return tri;
}
std::string createEquation(std::vector<u32> v) {

}