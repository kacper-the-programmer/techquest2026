#include <raylib.h>

#include "car.hpp"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "grand theft prawo jazdy");

    SetTargetFPS(60);

    car player;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        player.input();

        ClearBackground(RAYWHITE);
        player.draw();

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}