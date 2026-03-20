#pragma once

#include <raylib.h>

#include <vector>
#include <string>
#include <iostream>
#include "car.hpp"

class layer
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;
    int scale = 7;

    std::vector<Texture2D> background;
    std::vector<std::vector<int>> structure;

public:
    layer(car *player, int scale, std::vector<Texture2D> background, std::vector<std::vector<int>> structure)
    {

        this->background = background;
        this->player = player;
        this->structure = structure;
        this->scale *= scale;

        for (size_t background_index = 0; background_index < this->background.size(); background_index++)
        {
            this->background[background_index].width *= this->scale;
            this->background[background_index].height *= this->scale;
        }
    };
    ~layer()
    {
        for (size_t background_index = 0; background_index < this->background.size(); background_index++)
        {
            UnloadTexture(this->background[background_index]);
        }
    };

    void go_forward()
    {
        float radians = player->get_rotation() * DEG2RAD;
        this->x -= sinf(radians) * player->get_speed() * GetFrameTime();
        this->y += cosf(radians) * player->get_speed() * GetFrameTime();
    }

    void go_backword()
    {
        float radians = player->get_rotation() * DEG2RAD;
        this->x += sinf(radians) * player->get_speed() * GetFrameTime();
        this->y -= cosf(radians) * player->get_speed() * GetFrameTime();
    }

    void input()
    {
        go_forward();
    }

    void draw()
    {
        for (size_t index_y = 0; index_y < structure.size(); index_y++)
        {
            for (size_t index_x = 0; index_x < structure[index_y].size(); index_x++)
            {
                // <V><RRR>
                int temp = structure[index_y][index_x];
                int rotation = (int)(temp % 1000);
                int flip = 1;
                if (temp < 0)
                {
                    flip = -1;
                    temp *= -1;
                }
                int background_num = (int)((temp / 1000));
                Texture2D background_texture = this->background[background_num - 1];

                DrawTexturePro(
                    background_texture,
                    {0.0f, 0.0f, (float)background_texture.width * flip, (float)background_texture.height},
                    {(float)background_texture.width * index_x + this->x, (float)background_texture.height * index_y + y, (float)background_texture.width, (float)background_texture.height},
                    {(float)background_texture.width / 2.0f, (float)background_texture.height / 2.0f},
                    rotation, WHITE);
            }
        }
    }
};