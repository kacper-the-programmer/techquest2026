#include <raylib.h>

#include "car.hpp"
#include "layer.hpp"
#include "car_ui.hpp"
#include <vector>

#include "map1.hpp"

int main(void)
{
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(1920, 1080, "Autoskill");
    InitAudioDevice();
    SetTargetFPS(60);

    button a("start", "assets/gui/button_0.png", "assets/gui/button_1.png", 30, 300, 5);
    while (!WindowShouldClose())
    {
        a.on_click(map1);

        ClearBackground(WHITE);

        DrawText("Autoskill", 30, 30, 200, RED);
        a.draw();

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();

    return 0;
}