#pragma once

#include <raylib.h>
#include <vector>
#include "car.hpp"
#include "layer.hpp"

void map2(void)
{

    int scale = 1;
    // aaaaaa
    std::vector<std::vector<int>> ground = {};
    // Roads
    std::vector<std::vector<int>> elements1 = {
        {0000, 3270, 1090, 1090, 1090, 3000, 0000, 0000, 3270, 2090, 1090, 1090, 3000},
        {0000, 1000, 0000, 0000, 0000, 1000, 0000, 0000, 1000, 0000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 3180, 1090, 2090, 4000, 3000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 0000, 6180, 1000, 0000, 0000, 1000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 6270, 2090, 5090, 0000, 0000, 1000},
        {0000, 0000, 0000, 8090, 7090, 1090, 1090, 1090, 2090, 4000, 1090, 1090, 3090},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 6180, 0000, 0000, 0000}};

    // Buildings
    std::vector<std::vector<int>> buildings01 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 15000, 16000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 17000, 18000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 12270, 14270, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 11270, 13270, 0000}};
    std::vector<std::vector<int>> buildings23 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000}};
    std::vector<std::vector<int>> buildings45 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 11000, 12000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 13000, 14000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 15000, 16000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 17000, 18000}};
    std::vector<std::vector<int>> buildings6 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 11000, 12000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 13000, 14000, 0000}};

    // Roundabouts
    std::vector<std::vector<int>> rdb = {
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {3000, 2000, 1000},
        {4000, 0000, 8000},
        {5000, 6000, 7000}};

    // Parking
    std::vector<std::vector<int>> parking_pos = {
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 4180, 3180},
        {0000, 0000, 0000, 6180, 5180}};

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
        LoadTexture("assets/road/background/asphalt.png"),
        LoadTexture("assets/road/background/grass.png")};

    std::vector<Texture2D> building_textures01 = {
        LoadTexture("assets/building/0_1.png"),
        LoadTexture("assets/building/0_2.png"),
        LoadTexture("assets/building/0_3.png"),
        LoadTexture("assets/building/0_4.png"),
        LoadTexture("assets/building/1_1.png"),
        LoadTexture("assets/building/1_2.png"),
        LoadTexture("assets/building/1_3.png"),
        LoadTexture("assets/building/1_4.png")};

    std::vector<Texture2D> building_textures23 = {
        LoadTexture("assets/building/2_1.png"),
        LoadTexture("assets/building/2_2.png"),
        LoadTexture("assets/building/2_3.png"),
        LoadTexture("assets/building/2_4.png"),
        LoadTexture("assets/building/3_1.png"),
        LoadTexture("assets/building/3_2.png"),
        LoadTexture("assets/building/3_3.png"),
        LoadTexture("assets/building/3_4.png")};

    std::vector<Texture2D> building_textures45 = {
        LoadTexture("assets/building/4_1.png"),
        LoadTexture("assets/building/4_2.png"),
        LoadTexture("assets/building/4_3.png"),
        LoadTexture("assets/building/4_4.png"),
        LoadTexture("assets/building/5_1.png"),
        LoadTexture("assets/building/5_2.png"),
        LoadTexture("assets/building/5_3.png"),
        LoadTexture("assets/building/5_4.png")};

    std::vector<Texture2D> building_textures6 = {
        LoadTexture("assets/building/6_1.png"),
        LoadTexture("assets/building/6_2.png"),
        LoadTexture("assets/building/6_3.png"),
        LoadTexture("assets/building/6_4.png")};

    // Rondo
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

    // Materiały
    std::vector<Texture2D> materials_textures = {
        LoadTexture("assets/road/background/asphalt.png"),
        LoadTexture("assets/road/background/grass.png")};

    // Parking
    std::vector<Texture2D> parking_textures = {
        LoadTexture("assets/road/parking_asphalt.png"),
        LoadTexture("assets/road/parking_asphalt_2.png"),
        // LoadTexture("assets/road/parking.png"),
        // LoadTexture("assets/road/parking_empty.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected1.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected2.png"),
        LoadTexture("assets/road/asphalt_parking_exit1.png"),
        LoadTexture("assets/road/asphalt_parking_exit2.png")};

    for (size_t i = 0; i < elements1.size(); i++)
    {
        for (size_t x = 0; x < elements1[i].size(); x++)
        {
            ground[x][i] = 02000;
        }
    }

    car player(0, scale);
    layer maaaaap(&player, scale, &ground_textures, &ground);
    layer map(&player, scale, &road_textures, &elements1);
    layer buldings01(&player, scale, &building_textures01, &buildings01);
    // layer buldings23(&player, scale, building_textures23, buildings23);
    layer buldings45(&player, scale, &building_textures45, &buildings45);
    layer buldings6(&player, scale, &building_textures6, &buildings6);
    layer roundabouts(&player, scale, &roundabout_textures, &rdb);
    layer parking_place(&player, scale, &parking_textures, &parking_pos);
    car_ui ui(&player);
    ui.init();
    Music music = LoadMusicStream("assets/sfx/song_1.wav");
    PlayMusicStream(music);

    // while (!WindowShouldClose())
    // {
    //     UpdateMusicStream(music);
    //     // player.loop();

    //     BeginDrawing();
    //     map.input();
    //     buldings01.input();
    //     // buldings23.input();
    //     buldings45.input();
    //     buldings6.input();
    //     roundabouts.input();
    //     parking_place.input();
    //     player.input();

    //     ClearBackground(GREEN);
    //     buldings01.draw();
    //     // buldings23.draw();
    //     buldings45.draw();
    //     buldings6.draw();
    //     roundabouts.draw();
    //     parking_place.draw();
    //     map.draw();
    //     player.draw();

    //     DrawFPS(10, 10);

    //     DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
    //     // player.draw_gui();
    //     EndDrawing();
    // }

    std::vector<layer *> all_layers = {&maaaaap, &map, &buldings01, &buldings45, &buldings6, &roundabouts, &parking_place};

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);

        // 1. Obliczamy pożądany ruch na podstawie prędkości auta
        float radians = player.get_rotation() * DEG2RAD;
        float speed = player.get_speed();
        float frameSpeed = speed * GetFrameTime();

        float moveX = 0, moveY = 0;
        if (speed != 0)
        {
            // Odwracamy wektor ruchu (bo to mapa się przesuwa, nie auto)
            moveX = -sinf(radians) * frameSpeed;
            moveY = cosf(radians) * frameSpeed;
        }

        // 2. Sprawdzamy kolizję we WSZYSTKICH warstwach
        bool collision_detected = false;
        for (auto l : all_layers)
        {
            // Sprawdzamy, czy JEGO warstwa po przesunięciu o moveX/moveY dotknie auta
            if (l->has_collision_at(l->get_x() + moveX, l->get_y() + moveY))
            {
                collision_detected = true;
                break;
            }
        }

        // 3. Aplikujemy ruch tylko jeśli nie ma kolizji
        if (!collision_detected)
        {
            for (auto l : all_layers)
            {
                l->move(moveX, moveY);
            }
        }
        else
        {
            // Opcjonalnie: wyzeruj prędkość auta przy hicie
            // player.set_speed(0);
        }

        // 4. Reszta logiki i rysowanie
        player.input();
        player.logic();
        ui.input();
        ui.logic();

        BeginDrawing();
        ClearBackground(GREEN);
        for (auto l : all_layers)
            l->draw();
        player.draw();
        ui.draw();
        EndDrawing();
    }

    CloseWindow();
}