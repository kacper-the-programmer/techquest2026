#include <raylib.h>

#include "car.hpp"
#include "layer.hpp"
#include <maps.hpp>
#include "textures_assets.hpp"

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
    layer map(&player, scale, &road_textures, &elements1);
    layer buldings01(&player, scale, &building_textures01, &buildings01);
    // layer buldings23(&player, scale, building_textures23, buildings23);
    layer buldings45(&player, scale, &building_textures45, &buildings45);
    layer buldings6(&player, scale, &building_textures6, &buildings6);
    layer roundabouts(&player, scale, &roundabout_textures, &rdb);
    layer parking_place(&player, scale, &parking_textures, &parking_pos);

    Music music = LoadMusicStream("assets/sfx/song_1.wav");
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        // player.loop();

        BeginDrawing();
        map.input();
        buldings01.input();
        // buldings23.input();
        buldings45.input();
        buldings6.input();
        roundabouts.input();
        parking_place.input();
        player.input();

        ClearBackground(GREEN);
        buldings01.draw();
        // buldings23.draw();
        buldings45.draw();
        buldings6.draw();
        roundabouts.draw();
        parking_place.draw();
        map.draw();
        player.draw();

        DrawFPS(10, 10);

        DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
        // player.draw_gui();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}