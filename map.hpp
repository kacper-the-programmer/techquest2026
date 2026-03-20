#pragma once

#include <raylib.h>

#include <vector>
#include <iostream>
#include "car.hpp"

class map
{
private:
    car *player;
    float x = 0.0f;
    float y = 0.0f;
    float speed = 10;

    int element_width = 300;
    int element_height = 300;
    std::vector<std::vector<int>> elements = {
        {1, 1},
        {0, 0},
    };

public:
    map(car *player)
    {
        this->player = player;
    };
    ~map() {

    };
    void input()
    {
        if (IsKeyDown(KEY_A))
        {
            // this->x += speed;
        }
        if (IsKeyDown(KEY_D))
        {
            // this->x -= speed;
        }
        if (IsKeyDown(KEY_W))
        {
            // this->rota
            this->y += speed;
        }
        if (IsKeyDown(KEY_S))
        {
            this->y -= speed;
        }
    }
    void draw()
    {
        for (size_t index_x = 0; index_x < elements.size(); index_x++)
        {
            for (size_t index_y = 0; index_y < elements[index_x].size(); index_y++)
            {
                switch (elements[index_y][index_x])
                {
                case 0:
                    DrawRectangle(element_width * index_x + x, element_height * index_y + y, element_width, element_height, PURPLE);
                    break;
                case 1:
                    DrawRectangle(element_width * index_x + x, element_height * index_y + y, element_width, element_height, GREEN);
                default:
                    break;
                }
                // std::cout << elements[x][y];
            }
        }
        // std::cout << "\n";
        std::cout << this->player->get_rotation() << "\n";

        // DrawRectangle(this->x, this->y, 100, 100, BLUE);
    }
};