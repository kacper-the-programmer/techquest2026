#pragma once

#include <raylib.h>
#include <string>

class car
{
private:
    float width;
    float height;
    int rotation = 0;
    int scale = 3;
    float max_speed = 200;
    float speed = 0;

    Texture2D texture;
    Rectangle source;
    Rectangle destination;
    Vector2 origin;

public:
    car(int variant)
    {
        std::string texture_path = "assets/car/" + std::to_string(variant) + ".png";
        texture = LoadTexture(texture_path.c_str());
        this->refresh_scale();
    }
    ~car()
    {
        UnloadTexture(texture);
    }
    void refresh_scale()
    {
        texture.width *= scale;
        texture.height *= scale;

        source = {0.0f, 0.0f, (float)texture.width, (float)texture.height};
        destination = {GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f, (float)texture.width, (float)texture.height};

        origin = {(float)texture.width / 2.0f, (float)texture.height / 2.0f};
    }

    void input()
    {
        if (IsKeyDown(KEY_W) && this->speed <= this->max_speed)
        {
            this->speed += 40 * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && this->speed >= 0)
        {
            this->speed -= 100 * GetFrameTime();
        }

        if (IsKeyDown(KEY_A))
        {
            this->rotation--;
        }
        if (IsKeyDown(KEY_D))
        {
            this->rotation++;
        }

        if (IsKeyDown(KEY_Q))
        {

            if (IsKeyDown(KEY_ONE))
            {
                this->max_speed = 100;
            }
            if (IsKeyDown(KEY_TWO))
            {
                this->max_speed = 200;
            }
            if (IsKeyDown(KEY_THREE))
            {
                this->max_speed = 300;
            }
            if (IsKeyDown(KEY_FOUR))
            {
                this->max_speed = 400;
            }
            if (IsKeyDown(KEY_FIVE))
            {
                this->max_speed = 500;
            }
            if (IsKeyDown(KEY_SIX))
            {
                this->max_speed = 600;
            }
            if (IsKeyDown(KEY_ZERO))
            {
                this->max_speed = 0;
            }
            if (IsKeyDown(KEY_MINUS))
            {
                this->max_speed = -100;
            }
        }
    }

    void draw()
    {
        DrawTexturePro(this->texture, this->source, this->destination, this->origin, (float)this->rotation, WHITE);
    }

    int get_rotation()
    {
        return this->rotation;
    }
    float get_max_speed()
    {
        return this->max_speed;
    }

    float get_speed()
    {
        return this->speed;
    }

    void draw_gui()
    {
        DrawText(std::to_string(this->speed).c_str(), 100, 0, 20, BLACK);
    }
};
