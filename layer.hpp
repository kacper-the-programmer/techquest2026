#pragma once

#include <raylib.h>
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include "car.hpp"

class layer
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;
    float scale = 7.0f;

    std::vector<Texture2D> *background;
    std::vector<std::vector<int>> *structure;

public:
    layer(car *player, float scale, std::vector<Texture2D> *background, std::vector<std::vector<int>> *structure)
    {
        this->background = background;
        this->player = player;
        this->structure = structure;
        this->scale = scale;
    }

    void go_forward()
    {
        float radians = player->get_rotation() * DEG2RAD;

        this->x -= sinf(radians) * player->get_speed() * GetFrameTime();
        this->y += cosf(radians) * player->get_speed() * GetFrameTime();
    }

    void input()
    {
        go_forward();
    }

    void draw()
    {
        if (!structure || !background)
            return;

        for (size_t index_y = 0; index_y < structure->size(); index_y++)
        {
            for (size_t index_x = 0; index_x < (*structure)[index_y].size(); index_x++)
            {

                int temp = (*structure)[index_y][index_x];
                if (temp == 0)
                    continue;

                int rotation = std::abs(temp) % 1000;
                int flip = (temp < 0) ? -1 : 1;

                int background_idx = (std::abs(temp) / 1000) - 1;

                if (background_idx < 0 || background_idx >= (int)background->size())
                    continue;

                Texture2D &tex = (*background)[background_idx];

                Rectangle sourceRec = {
                    0.0f,
                    0.0f,
                    (float)tex.width * flip,
                    (float)tex.height};

                float tileWidth = (float)tex.width * this->scale;
                float tileHeight = (float)tex.height * this->scale;

                Rectangle destRec = {
                    (float)index_x * tileWidth + x,
                    (float)index_y * tileHeight + y,
                    tileWidth,
                    tileHeight};

                Vector2 origin = {0.0f, 0.0f};

                DrawTexturePro(
                    tex,
                    {
                        0.0f,
                        0.0f,
                        (float)tex.width * flip,
                        (float)tex.height,
                    },
                    {
                        (float)tex.width * index_x * this->scale + this->x,
                        (float)tex.height * index_y * this->scale + this->y,
                        (float)tex.width * this->scale,
                        (float)tex.height * this->scale,
                    },
                    {(0, 0)},
                    (float)rotation, WHITE);
            }
        }
    }
};

#pragma once

#include <raylib.h>
#include <vector>
#include <cmath>
#include <iostream>

#include "car.hpp"

class layer
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;
    float scale = 7.0f;

    std::vector<Texture2D> *background;
    std::vector<std::vector<int>> *structure;

    bool check_collision_at(float nextX, float nextY)
    {
        if (!structure || !background)
            return false;

        for (size_t y_i = 0; y_i < structure->size(); y_i++)
        {
            const auto &row = (*structure)[y_i];
            for (size_t x_i = 0; x_i < row.size(); x_i++)
            {
                int tileData = row[x_i];
                if (tileData == 0)
                    continue;

                int collisionFlag = std::abs(tileData) / 10000;

                if (collisionFlag == 1)
                {
                    int background_num = (std::abs(tileData) % 10000) / 1000;
                    if (background_num <= 0 || background_num > (int)background->size())
                        continue;

                    Texture2D &tex = (*background)[background_num - 1];

                    float tileW = tex.width * scale;
                    float tileH = tex.height * scale;
                    float tilePosX = tileW * x_i + nextX;
                    float tilePosY = tileH * y_i + nextY;

                    Rectangle tileRect = {tilePosX, tilePosY, tileW, tileH};

                    Vector2 carPos = {(float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f};

                    if (CheckCollisionPointRec(carPos, tileRect))
                    {
                        return true; // Wykryto kolizję
                    }
                }
            }
        }
        return false;
    }

public:
    layer(car *player, float scale,
          std::vector<Texture2D> *background,
          std::vector<std::vector<int>> *structure)
    {
        this->player = player;
        this->background = background;
        this->structure = structure;
        this->scale *= scale;
    }

    void input()
    {
        float speed = player->get_speed();
        if (speed == 0)
            return;

        float radians = player->get_rotation() * DEG2RAD;
        float frameSpeed = speed * GetFrameTime();

        float nextX = this->x;
        float nextY = this->y;

        if (speed > 0)
        {
            nextX -= sinf(radians) * frameSpeed;
            nextY += cosf(radians) * frameSpeed;
        }
        else
        {
            nextX += sinf(radians) * std::abs(frameSpeed);
            nextY -= cosf(radians) * std::abs(frameSpeed);
        }

        if (!check_collision_at(nextX, nextY))
        {
            this->x = nextX;
            this->y = nextY;
        }
        else
        {
        }
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
                int val = std::abs(row[x_i]);
                if (val == 0)
                    continue;

                int flip = (row[x_i] < 0) ? -1 : 1;

                int rotation = val % 1000;
                int background_num = (val % 10000) / 1000;

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

                DrawTexturePro(tex, src, dest, origin, (float)rotation, WHITE);
            }
        }
    }
};