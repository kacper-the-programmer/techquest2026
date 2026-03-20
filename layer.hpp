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
    std::vector<Texture2D> foreground;

    std::vector<std::vector<int>> elements = {
        {400, 400},
        {100, 211},
        {100, 100},
        {100, 100},
    };

public:
    layer(car *player, int scale, std::vector<Texture2D> background, std::vector<Texture2D> foreground)
    {

        this->background = background;
        this->foreground = foreground;
        this->player = player;
        this->scale *= scale;

        for (size_t foreground_index = 0; foreground_index < this->foreground.size(); foreground_index++)
        {
            this->foreground[foreground_index].width *= this->scale;
            this->foreground[foreground_index].height *= this->scale;
        }

        for (size_t background_index = 0; background_index < this->background.size(); background_index++)
        {
            this->background[background_index].width *= this->scale;
            this->background[background_index].height *= this->scale;
        }
    };
    ~layer()
    {
        for (size_t foreground_index = 0; foreground_index < this->foreground.size(); foreground_index++)
        {
            UnloadTexture(this->foreground[foreground_index]);
        }

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
        for (size_t index_y = 0; index_y < elements.size(); index_y++)
        {
            for (size_t index_x = 0; index_x < elements[index_y].size(); index_x++)
            {
                int rotation_num = (int)(elements[index_y][index_x] % 10);
                int background_num = (int)((elements[index_y][index_x] / 10) % 10);
                int foreground_num = (int)(elements[index_y][index_x] / 100);

                int rotation = rotation_num * 90;
                Texture2D background_texture = this->background[background_num - 1];
                Texture2D foreground_texture = this->foreground[foreground_num - 1];

                Vector2 position = {
                    foreground_texture.width * index_x + x,
                    foreground_texture.height * index_y + y,
                };

                DrawTextureEx(background_texture, position, 0, 1, WHITE);
                DrawTextureEx(foreground_texture, position, rotation, 1, WHITE);
            }
        }
    }
};