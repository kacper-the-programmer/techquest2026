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

    // Roads
    std::vector<std::vector<int>> elements1 = {
        {0000, 3270, 1090, 1090, 1090, 3000, 0000, 0000, 3270, 2090, 1090, 1090, 3000},
        {0000, 1000, 0000, 0000, 0000, 1000, 0000, 0000, 1000, 0000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 3180, 1090, 2090, 4000, 3000, 0000, 0000, 1000},
        {0000, 1000, 0000, 0000, 0000, 0000, 0000, 0000, 6180, 1000, 0000, 0000, 1000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 6270, 2090, 5090, 0000, 0000, 1000},
        {0000, 0000, 0000, 1090, 1090, 1090, 1090, 1090, 2090, 4000, 1090, 1090, 3090},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 6180, 0000, 0000, 0000}
    };

    // Buildings
    std::vector<std::vector<int>> buildings01 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 5000, 6000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 7000, 8000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 2270, 4270, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 1270, 3270, 0000}
    };
    std::vector<std::vector<int>> buildings23 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000}
    };
        std::vector<std::vector<int>> buildings45 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 1000, 2000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 3000, 4000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 5000, 6000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 7000, 8000}
    };
    std::vector<std::vector<int>> buildings6 = {
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 1000, 2000, 0000},
        {0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 0000, 3000, 4000, 0000}
    };

    // Roundabouts
    std::vector<std::vector<int>> rdb = {
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {0000, 0000, 0000},
        {3000, 2000, 1000},
        {4000, 0000, 8000},
        {5000, 6000, 7000}
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
        LoadTexture("assets/road/asfalt.png"),
        LoadTexture("assets/road/trawa.png")
    };

    std::vector<Texture2D> building_textures01 = {
        LoadTexture("assets/bulding/0_1.png"),
        LoadTexture("assets/bulding/0_2.png"),
        LoadTexture("assets/bulding/0_3.png"),
        LoadTexture("assets/bulding/0_4.png"),
        LoadTexture("assets/bulding/1_1.png"),
        LoadTexture("assets/bulding/1_2.png"),
        LoadTexture("assets/bulding/1_3.png"),
        LoadTexture("assets/bulding/1_4.png")
    };

    std::vector<Texture2D> building_textures23 = {
        LoadTexture("assets/bulding/2_1.png"),
        LoadTexture("assets/bulding/2_2.png"),
        LoadTexture("assets/bulding/2_3.png"),
        LoadTexture("assets/bulding/2_4.png"),
        LoadTexture("assets/bulding/3_1.png"),
        LoadTexture("assets/bulding/3_2.png"),
        LoadTexture("assets/bulding/3_3.png"),
        LoadTexture("assets/bulding/3_4.png")
    };

    std::vector<Texture2D> building_textures45 = {
        LoadTexture("assets/bulding/4_1.png"),
        LoadTexture("assets/bulding/4_2.png"),
        LoadTexture("assets/bulding/4_3.png"),
        LoadTexture("assets/bulding/4_4.png"),
        LoadTexture("assets/bulding/5_1.png"),
        LoadTexture("assets/bulding/5_2.png"),
        LoadTexture("assets/bulding/5_3.png"),
        LoadTexture("assets/bulding/5_4.png")
    };

    std::vector<Texture2D> building_textures6 = {
        LoadTexture("assets/bulding/6_1.png"),
        LoadTexture("assets/bulding/6_2.png"),
        LoadTexture("assets/bulding/6_3.png"),
        LoadTexture("assets/bulding/6_4.png")
    };

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
        LoadTexture("assets/road/roundabout/8.png")
    };

    car player(0, scale);
    player.init_gui();
    layer map(&player, scale, road_textures, elements1);
    layer buldings01(&player, scale, building_textures01, buildings01);
    // layer buldings23(&player, scale, building_textures23, buildings23);
    layer buldings45(&player, scale, building_textures45, buildings45);
    layer buldings6(&player, scale, building_textures6, buildings6);
    layer roundabouts(&player, scale, roundabout_textures, rdb);

    Music music = LoadMusicStream("assets/sfx/song_1.wav");
    PlayMusicStream(music);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(music);
        player.loop();

        BeginDrawing();
        map.input();
        buldings01.input();
        // buldings23.input();
        buldings45.input();
        buldings6.input();
        roundabouts.input();
        player.input();

        ClearBackground(GREEN);
        buldings01.draw();
        // buldings23.draw();
        buldings45.draw();
        buldings6.draw();
        roundabouts.draw();
        map.draw();
        player.draw();

        DrawFPS(10, 10);

        DrawText("Grand Theft prawo jazdy", 30, 30, 40, BLACK);
        player.draw_gui();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}