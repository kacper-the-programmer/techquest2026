#pragma once

#include <raylib.h>
#include <vector>
#include <cmath>

#include "car.hpp"

class layer
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;
    float scale = 7.0f;
    bool fast;

    std::vector<Texture2D> *background;
    std::vector<std::vector<int>> *structure;

public:
    layer(car *player, float scale, std::vector<Texture2D> *background, std::vector<std::vector<int>> *structure, bool fast = false)
    {
        this->player = player;
        this->background = background;
        this->structure = structure;
        this->scale *= scale;
        this->fast = fast;
    }

    void go_forward()
    {
        float radians = player->get_rotation() * DEG2RAD;
        float speed = player->get_speed();
        if (this->player->get_reverse())
        {
            speed *= -1;
        }

        this->x -= sinf(radians) * speed * GetFrameTime();
        this->y += cosf(radians) * speed * GetFrameTime();
    }

    void input()
    {
        go_forward();
    }

    void draw()
    {
        if (!structure || !background)
            return;

        for (size_t y_i = 0; y_i < structure->size(); y_i++)
        {
            const auto &row = (*structure)[y_i];

            for (size_t x_i = 0; x_i < row.size(); x_i++)
            {
                int temp = row[x_i];
                if (temp == 0)
                    continue;
                if (!fast)
                {
                    int flip = 1;
                    if (temp < 0)
                    {
                        flip = -1;
                        temp *= -1;
                    }

                    int rotation = temp % 1000;
                    int background_num = temp / 1000;

                    if (background_num <= 0 || background_num > (int)background->size())
                        continue;

                    Texture2D &tex = (*background)[background_num - 1];

                    float posX = tex.width * x_i * scale + x;
                    float posY = tex.height * y_i * scale + y;

                    Rectangle src = {
                        (flip == -1 ? (float)tex.width : 0.0f),
                        0.0f,
                        (float)tex.width * flip,
                        (float)tex.height};

                    Rectangle dest = {
                        posX + tex.width * scale / 2.0f,
                        posY + tex.height * scale / 2.0f,
                        tex.width * scale,
                        tex.height * scale};

                    Vector2 origin = {
                        tex.width * scale / 2.0f,
                        tex.height * scale / 2.0f};

                    DrawTexturePro(tex, src, dest, origin, rotation, WHITE);
                }
                else
                {
                    int background_num = temp / 1000;
                    Texture2D &tex = (*background)[background_num - 1];
                    DrawTextureEx(
                        tex,
                        {
                            (float)tex.width * x_i * scale + x,
                            (float)tex.height * y_i * scale + y,
                        },
                        0,
                        scale, WHITE);
                }
            }
        }
    }
};