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

    // Pomocnicza funkcja sprawdzająca kolizję z talami w tej warstwie
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

                // Wyciągamy X z formatu XPRRR (np. 12090 / 10000 = 1)
                int collisionFlag = std::abs(tileData) / 10000;

                if (collisionFlag == 1)
                {
                    int background_num = (std::abs(tileData) % 10000) / 1000;
                    if (background_num <= 0 || background_num > (int)background->size())
                        continue;

                    Texture2D &tex = (*background)[background_num - 1];

                    // Obliczamy obszar kafelka na ekranie przy nowych współrzędnych
                    float tileW = tex.width * scale;
                    float tileH = tex.height * scale;
                    float tilePosX = tileW * x_i + nextX;
                    float tilePosY = tileH * y_i + nextY;

                    Rectangle tileRect = {tilePosX, tilePosY, tileW, tileH};

                    // Sprawdzamy czy środek ekranu (pozycja auta) jest wewnątrz kafelka
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

        // Obliczamy potencjalne nowe przesunięcie mapy
        float nextX = this->x;
        float nextY = this->y;

        if (speed > 0)
        { // Forward
            nextX -= sinf(radians) * frameSpeed;
            nextY += cosf(radians) * frameSpeed;
        }
        else
        { // Backward
            nextX += sinf(radians) * std::abs(frameSpeed);
            nextY -= cosf(radians) * std::abs(frameSpeed);
        }

        // Jeśli nowa pozycja nie powoduje kolizji, aktualizujemy
        if (!check_collision_at(nextX, nextY))
        {
            this->x = nextX;
            this->y = nextY;
        }
        else
        {
            // Opcjonalnie: zatrzymaj samochód przy uderzeniu
            // player->stop(); // Wymagałoby dodania metody w car.hpp
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

                // Dekodowanie formatu XPRRR
                // RRR = ostatnie 3 cyfry
                // P = cyfra tysięcy
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