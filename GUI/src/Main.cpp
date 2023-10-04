#include <raylib.h>
#include <raymath.h>

#include "Defines.hpp"
#include "Triangle.hpp"

static std::vector<std::vector<u32>> triangle;
static std::string equation;

void generate(u32 n) {
	triangle = createTriangle(n);
	equation = createEquation(triangle.back());
}
void maybeResizeWidth(u32 newWidth) {
	if (newWidth > GetScreenWidth())
		SetWindowSize(newWidth, GetScreenHeight());
}

#define EquBaseSize 40
#define EquExpoSize 30

void drawEquation() {
	u32 start = 0, x = 10;
	for(u32 i = 0; i <= equation.length(); i++) {
		const char c = equation[i];
		if (c == '^' || c == '\0') {
			std::string term = equation.substr(start, i - start);
			DrawText(term.c_str(), x, GetRenderHeight() - 40 - EquBaseSize / 2, EquBaseSize, RED);
			start = i + 1, x += MeasureText(term.c_str(), EquBaseSize) + 2;
		}
		if (c == '\'') {
			std::string term = equation.substr(start, i - start);
			DrawText(term.c_str(), x, GetRenderHeight() - 50 - EquExpoSize / 2, EquExpoSize, RED);
			start = i + 1, x += MeasureText(term.c_str(), EquExpoSize) + 2;
		}
	}
	maybeResizeWidth(x + 5);
}

i32 main(i32 argc, char* argsv[]) {
	InitWindow(250, 80, "Pascalsches Dreieck");
	generate(10);
	while(!WindowShouldClose()) {
		BeginDrawing(); {
			ClearBackground(BLACK);
			drawEquation();
		} EndDrawing();
	}

	CloseWindow();
}