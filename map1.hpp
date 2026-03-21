#pragma once

#include "car.hpp"
#include "layer.hpp"
#include "car_ui.hpp"
#include <vector>

void map1(void)
{
    float scale = 1;

    std::vector<std::vector<int>> elements1 = {
        {0000, 0000},
        {0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 3270, 3000},
        {0000, 1000, 0000, 0000, 0000, 3270, 1090, 4000, 3090},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 1000},
        {3270, 4000, 1090, 1090, 0000, 0000, 0000, 3090},
        {1000, 1000, },
        {1000, 1000, 0000, 0000, 0000, 1000},
        {3180, 5180, 1090, 1090, 1090, 3090},
    };
    std::vector<std::vector<int>> rdb = {
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 3000,2000,1000},
        {0000, 0000, 0000, 0000, 4000,0000,8000},
        {0000, 0000, 0000, 0000,5000,6000,7000},
    };
    std::vector<std::vector<int>> elements2;

    for (size_t i = 0; i < 100; i++)
    {
        std::vector<int> row;

        for (size_t y = 0; y < 100; y++)
        {
            row.push_back(2000);
        }

        elements2.push_back(row);
    }

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
    std::vector<Texture2D> roundabout_textures = {
        LoadTexture("assets/road/roundabout/0.png"),
        LoadTexture("assets/road/roundabout/1.png"),
        LoadTexture("assets/road/roundabout/2.png"),
        LoadTexture("assets/road/roundabout/3.png"),
        LoadTexture("assets/road/roundabout/4.png"),
        LoadTexture("assets/road/roundabout/5.png"),
        LoadTexture("assets/road/roundabout/6.png"),
        LoadTexture("assets/road/roundabout/7.png"),
        LoadTexture("assets/road/roundabout/8.png")};

    car player(0, scale);
    car_ui ui(&player);
    ui.init();
    layer buldings(&player, scale, &ground_textures, &elements2, true);
    layer map(&player, scale, &road_textures, &elements1);
    layer roundabouts(&player, scale, &roundabout_textures, &rdb);

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
        roundabouts.input();

        player.input();

        ClearBackground(WHITE);

        buldings.draw();
        map.draw();
        roundabouts.draw();
        player.draw();
        DrawFPS(10, 10);

        // DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
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