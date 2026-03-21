#pragma once

#include "car.hpp"
#include "layer.hpp"
#include "car_ui.hpp"
#include <vector>

void map1(void)
{

    int scale = 1;

    
    
    std::vector<std::vector<int>> elements2 = {
        {2000, 2000, 14000},
        {2000, 1000},
        {2000, 2000},
        {2000, 2020},
        {2000, 2000},
    };

     std::vector<std::vector<int>> elements1 = {
        {0000, 6000, 0000, 0000, 0000, 3000, 0000, 0000, 3270, 2090, 1090, 1090, 3000},
        {0000, 1000, 0000, 0000, 0000, 1000, 0000, 0000, 1000, 0000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 3180, 1090, 2090, 4000, 3000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 0000, 6180, 1000, 0000, 0000, 1000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 6270, 2090, 5090, 0000, 0000, 1000},
        {0000, 0000, 0000, 8090, 7090, 1090, 1090, 1090, 2090, 4000, 1090, 1090, 3090},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 1000, 0000, 0000, 0000},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 1000, 0000, 0000, 0000},
        {0000, 3180, 1090, 1090, 1090, 1090, 1090, 1090, 1090, 5180, 1090, 1090, 6090},
    };

        std::vector<std::vector<int>> rdb = {
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {3000, 2000, 1000},
        {4000, 0000, 8000},
        {5000, 6000, 7000}};
        
        std::vector<Texture2D> road_textures = {
        LoadTexture("assets/road/0.png"),
        LoadTexture("assets/road/1.png"),
        LoadTexture("assets/road/2.png"),
        LoadTexture("assets/road/3.png"),
        LoadTexture("assets/road/4.png"),
        LoadTexture("assets/road/5.png"),
        LoadTexture("assets/road/6.png"),
        LoadTexture("assets/road/7.png"),
    };

    std::vector<Texture2D> ground_textures = {
        LoadTexture("assets/road/background/sand.png"),
        LoadTexture("assets/nothing.png"),
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
        
        std::vector<Texture2D> parking_textures = {
        LoadTexture("assets/road/parking_asphalt.png"),
        LoadTexture("assets/road/parking_asphalt_2.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected1.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected2.png"),
        LoadTexture("assets/road/asphalt_parking_exit1.png"),
        LoadTexture("assets/road/asphalt_parking_exit2.png")};

        Texture2D sand = LoadTexture("assets/road/background/sand.png");
        std::vector<std::vector<int>> parking_pos = {
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 4180, 3180},
        {0000, 0000, 0000, 6180, 5180}};

    car player(0, scale);
    car_ui ui(&player);
    ui.init();
    layer buldings(&player, scale, &ground_textures, &ground_textures, &elements2);
    layer map(&player, scale, &road_textures, &road_textures, &elements1);
    layer roundabouts(&player, scale, &roundabout_textures, &roundabout_textures, &rdb);
    layer parking_place(&player, scale, &parking_textures, &parking_textures, &parking_pos);

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
        roundabouts.input(); //D
        player.input();
        parking_place.input();

        // ClearBackground(WHITE);
        

    int tileSize = sand.width; // albo np. 64

    for (int y = 0; y < 10000; y += tileSize)
    {
    for (int x = 0; x < 10000; x += tileSize)
    {
        DrawTexture(sand, x, y, WHITE);
    }
}
        
        // buldings.draw(); //to jedno tło 
        map.draw(); //drogi
        roundabouts.draw();
        parking_place.draw();
        player.draw();
        
        DrawFPS(10, 10);

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