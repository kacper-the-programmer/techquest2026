#include <raylib.h>

#include "car.hpp"
#include "layer.hpp"

int main(void)
{
    const int screenWidth = 1920;
    const int screenHeight = 1080;

    int scale = 1;

    InitWindow(screenWidth, screenHeight, "grand theft prawo jazdy");
    InitAudioDevice();

    SetTargetFPS(60);

    ToggleFullscreen();

    std::vector<Texture2D> road_textures = {
        LoadTexture("assets/road/0.png"),
        LoadTexture("assets/road/1.png"),
        LoadTexture("assets/road/2.png"),
        LoadTexture("assets/road/3.png"),
    };

    std::vector<Texture2D> ground_textures = {
        LoadTexture("assets/bulding/0.png"),
        LoadTexture("assets/bulding/1.png"),
        LoadTexture("assets/bulding/2.png"),
        LoadTexture("assets/bulding/3.png"),
    };

    car player(0, scale);
    player.init_gui();
    layer map(&player, scale, road_textures, road_textures);
    layer buldings(&player, scale, ground_textures, ground_textures);

    Music music = LoadMusicStream("assets/soundtrack/song_1.wav");
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        player.loop();

        BeginDrawing();
        map.input();
        buldings.input();
        player.input();

        ClearBackground(RAYWHITE);
        map.draw();
        buldings.draw();
        player.draw();

        DrawFPS(10, 10);

        DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
        player.draw_gui();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}