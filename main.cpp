#include <raylib.h>

#include "car.hpp"
#include "map.hpp"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "grand theft prawo jazdy");

    SetTargetFPS(60);
    ToggleFullscreen();

    car player;
    map mapa(&player);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        mapa.input();
        player.input();

        ClearBackground(RAYWHITE);
        mapa.draw();
        player.draw();

        DrawText("Grand Theft prawo jazdy", 10, 10, 50, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}