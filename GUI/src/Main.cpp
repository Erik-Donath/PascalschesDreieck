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
void maybeResizeHeight(u32 newHeight) {
	if (newHeight > GetScreenHeight())
		SetWindowSize(GetScreenWidth(), newHeight);
}

#define EquBaseSize 40
#define EquExpoSize 30
#define TriangleCircleSize 40

void drawTriangle() {
	for (u32 i = 0; i < triangle.size(); i++) {
		for (u32 j = 0; j <= i; j++) {
			u32 x = 2 * TriangleCircleSize * j - TriangleCircleSize * i + GetScreenWidth() / 2;
			u32 y = 2 * TriangleCircleSize * i + TriangleCircleSize + 5;
			DrawCircle(x, y, TriangleCircleSize, (i != triangle.size() - 1) ? BLUE : GREEN);

			const char* t = TextFormat("%u", triangle[i][j]);
			DrawText(t, x - (MeasureText(t, TriangleCircleSize) / 2), y - TriangleCircleSize / 2, TriangleCircleSize, RED);
		}
	}

	maybeResizeWidth(triangle.back().size() * TriangleCircleSize * 3);
	maybeResizeHeight(triangle.size() * TriangleCircleSize * 2 + 80);
}

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
	generate(13);
	while(!WindowShouldClose()) {
		BeginDrawing(); {
			ClearBackground(BLACK);
			drawTriangle();
			drawEquation();
		} EndDrawing();
	}

	CloseWindow();
}