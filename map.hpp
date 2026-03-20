#pragma once

#include <raylib.h>

#include <vector>
#include <string>
#include <iostream>
#include "car.hpp"

class map
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;

    int element_width = 300;
    int element_height = 300;

    std::vector<Texture2D> textures = {
        LoadTexture("assets/road/0.png"),
        LoadTexture("assets/road/1.png"),
        LoadTexture("assets/road/2.png"),
        LoadTexture("assets/road/3.png"),
    };

    std::vector<std::vector<int>> elements = {
        {40, 40},
        {10, 20},
        {10, 10},
        {10, 10}};

public:
    map(car *player)
    {
        this->player = player;
    };
    ~map()
    {
        for (size_t i = 0; i < textures.size(); i++)
        {
            UnloadTexture(textures[i]);
        }
    };

    void go_forward()
    {
        float radians = player->get_rotation() * DEG2RAD;
        this->x -= sinf(radians) * player->get_max_speed() * GetFrameTime();
        this->y += cosf(radians) * player->get_max_speed() * GetFrameTime();
    }

    void go_backword()
    {
        float radians = player->get_rotation() * DEG2RAD;
        this->x += sinf(radians) * player->get_max_speed() * GetFrameTime();
        this->y -= cosf(radians) * player->get_max_speed() * GetFrameTime();
    }

    void input()
    {
        if (IsKeyDown(KEY_W))
        {
            go_forward();
        }
        // if (IsKeyDown(KEY_S))
        // {
        //     go_backword();
        // }
    }
    void draw()
    {
        for (size_t index_x = 0; index_x < elements.size(); index_x++)
        {
            for (size_t index_y = 0; index_y < elements[index_x].size(); index_y++)
            {
                Texture2D texture = (Texture2D)this->textures[(int)(elements[index_y][index_x] / 10) - 1];
                texture.width *= 7;
                texture.height *= 7;
                int rotation = (int)(elements[index_y][index_x] % 10) * 90;
                Vector2 position = {texture.width * index_x + x, texture.height * index_y + y};
                DrawTextureEx(texture, position, rotation, 1, WHITE);
            }
        }
    }
};