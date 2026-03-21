#pragma once

#include "car.hpp"
#include "layer.hpp"
#include "car_ui.hpp"
#include <vector>

void map1(void)
{
    // const int screenWidth = 1920;
    // const int screenHeight = 1080;

    int scale = 1;

    // SetConfigFlags(FLAG_FULLSCREEN_MODE);
    // InitWindow(screenWidth, screenHeight, "grand theft prawo jazdy");
    // InitAudioDevice();

    // SetTargetFPS(60);

    std::vector<std::vector<int>> elements1 = {
        {-3000, 3000, 2090},
        {1000, 2000},
        {1000, 2020},
        {},
        {1000, 1000},
        {4000, 4000},
    };

    std::vector<std::vector<int>> elements2 = {
        {2000, 2000},
        {2000, 1000},
        {2000, 2000},
        {2000, 2020},
        {2000, 2000},
    };

    std::vector<Texture2D> road_textures = {
        LoadTexture("assets/road/0.png"),
        LoadTexture("assets/road/1.png"),
        LoadTexture("assets/road/2.png"),
        LoadTexture("assets/road/3.png"),
        LoadTexture("assets/road/4.png"),
        LoadTexture("assets/road/5.png")
        // LoadTexture("assets/nothing.png"),
    };

    std::vector<Texture2D> ground_textures = {
        LoadTexture("assets/road/background/asphalt.png"),
        LoadTexture("assets/road/background/grass.png"),
    };

    car player(0, scale);
    car_ui ui(&player);
    ui.init();
    layer buldings(&player, scale, &ground_textures, &elements2);
    layer map(&player, scale, &road_textures, &elements1);

    Music music = LoadMusicStream("assets/sfx/song_1.wav");
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        player.logic();
        ui.logic();
        BeginDrawing();
        ui.input();
        map.input();
        buldings.input();

        player.input();

        ClearBackground(WHITE);

        buldings.draw();
        map.draw();
        player.draw();

        DrawFPS(10, 10);

        DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
        ui.draw();
        EndDrawing();
    }

    for (auto &t : road_textures)
    {
        UnloadTexture(t);
    }
    for (auto &t : ground_textures)
        UnloadTexture(t);

    UnloadMusicStream(music);

    CloseAudioDevice();
    CloseWindow();
}