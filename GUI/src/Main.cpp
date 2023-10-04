#include <raylib.h>
#include <raymath.h>

#include "Defines.hpp"
#include "Triangle.hpp"

i32 main(i32 argc, char* argsv[]) {
	InitWindow(800, 600, "Pascalsches Dreieck");

	while(!WindowShouldClose()) {
		BeginDrawing(); {
			ClearBackground(BLACK);
		} EndDrawing();
	}

	CloseWindow();
}