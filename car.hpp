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
    float speed = 200;

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
        if (IsKeyDown(KEY_A))
        {
            int current_rotation = this->rotation;
            if (this->rotation > current_rotation - 40 && this->rotation < current_rotation + 40)
            {
                this->rotation--;
            }
        }
        if (IsKeyDown(KEY_D))
        {
            int current_rotation = this->rotation;
            if (current_rotation)
            {
                this->rotation++;
            }
        }

        if (IsKeyDown(KEY_Q))
            if (IsKeyDown(KEY_ONE))
            {
                this->speed = 100;
            }
        if (IsKeyDown(KEY_TWO))
        {
            this->speed = 200;
        }
        if (IsKeyDown(KEY_THREE))
        {
            this->speed = 300;
        }
        if (IsKeyDown(KEY_FOUR))
        {
            this->speed = 400;
        }
        if (IsKeyDown(KEY_FIVE))
        {
            this->speed = 500;
        }
        if (IsKeyDown(KEY_SIX))
        {
            this->speed = 600;
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
    float get_speed()
    {
        return this->speed;
    }

    void draw_gui()
    {
    }
};
