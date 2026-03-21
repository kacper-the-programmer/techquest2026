#pragma once
#include <raylib.h>
#include <vector>

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
        LoadTexture("assets/road/background/grass.png")
    };

    std::vector<Texture2D> building_textures01 = {
        LoadTexture("assets/building/0_1.png"),
        LoadTexture("assets/building/0_2.png"),
        LoadTexture("assets/building/0_3.png"),
        LoadTexture("assets/building/0_4.png"),
        LoadTexture("assets/building/1_1.png"),
        LoadTexture("assets/building/1_2.png"),
        LoadTexture("assets/building/1_3.png"),
        LoadTexture("assets/building/1_4.png")
    };

    std::vector<Texture2D> building_textures23 = {
        LoadTexture("assets/building/2_1.png"),
        LoadTexture("assets/building/2_2.png"),
        LoadTexture("assets/building/2_3.png"),
        LoadTexture("assets/building/2_4.png"),
        LoadTexture("assets/building/3_1.png"),
        LoadTexture("assets/building/3_2.png"),
        LoadTexture("assets/building/3_3.png"),
        LoadTexture("assets/building/3_4.png")
    };

    std::vector<Texture2D> building_textures45 = {
        LoadTexture("assets/building/4_1.png"),
        LoadTexture("assets/building/4_2.png"),
        LoadTexture("assets/building/4_3.png"),
        LoadTexture("assets/building/4_4.png"),
        LoadTexture("assets/building/5_1.png"),
        LoadTexture("assets/building/5_2.png"),
        LoadTexture("assets/building/5_3.png"),
        LoadTexture("assets/building/5_4.png")
    };

    std::vector<Texture2D> building_textures6 = {
        LoadTexture("assets/building/6_1.png"),
        LoadTexture("assets/building/6_2.png"),
        LoadTexture("assets/building/6_3.png"),
        LoadTexture("assets/building/6_4.png")
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

    //Materiały
    std::vector<Texture2D> materials_textures = {
        LoadTexture("assets/road/background/asphalt.png"),
        LoadTexture("assets/road/background/grass.png")
    };

    // Parking
    std::vector<Texture2D> parking_textures = {
        LoadTexture("assets/road/parking_asphalt.png"),
        LoadTexture("assets/road/parking_asphalt_2.png"),
        // LoadTexture("assets/road/parking.png"),
        // LoadTexture("assets/road/parking_empty.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected1.png"),
        LoadTexture("assets/road/parking_asphalt_triple_connected2.png"),
        LoadTexture("assets/road/asphalt_parking_exit1.png"),
        LoadTexture("assets/road/asphalt_parking_exit2.png")
    };
