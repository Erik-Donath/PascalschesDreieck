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
	std::stringstream ss;
	u32 n = v.size() - 1;
	ss << "(a+b)^" << n << "'=";

	for (u32 i = 0; i <= n; i++) {
		if (v[i] > 1) ss << v[i];

		u32 aExponent = n - i;
		if (aExponent == 1) ss << "a";
		if (aExponent >  1) ss << "a^" << aExponent << "'";

		u32 bExponent = i;
		if (bExponent == 1) ss << "b";
		if (bExponent >  1) ss << "b^" << bExponent << "'";

		if (i != n) ss << "+";
	}

	ss << '.'; // End
	return ss.str();
}
