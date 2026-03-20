#include <raylib.h>

#include "car.hpp"
#include "map.hpp"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int scale = 1;

    InitWindow(screenWidth, screenHeight, "grand theft prawo jazdy");
    InitAudioDevice();

    SetTargetFPS(60);

    ToggleFullscreen();

    car player(0, scale);
    map mapa(&player, scale);

    Music music = LoadMusicStream("assets/soundtrack/song_1.wav");
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        player.loop();

        BeginDrawing();
        mapa.input();
        player.input();

        ClearBackground(RAYWHITE);
        mapa.draw();
        player.draw();

        DrawFPS(10, 10);

        DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
        player.draw_gui();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}