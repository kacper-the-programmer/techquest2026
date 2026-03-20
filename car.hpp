#pragma once

#include <raylib.h>

class car
{
private:
    float width;
    float height;
    int rotation = 0;
    int scale = 3;

    Texture2D texture;
    Rectangle source;
    Rectangle destination;
    Vector2 origin;

public:
    car()
    {
        texture = LoadTexture("assets/auto1.png");
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
            this->rotation--;
        }
        if (IsKeyDown(KEY_D))
        {
            this->rotation++;
        }
        if (IsKeyDown(KEY_W))
        {
        }
        if (IsKeyDown(KEY_S))
        {
        }
    }

    void draw()
    {
        DrawTexturePro(texture, source, destination, origin, (float)rotation, WHITE);
    }
    int get_rotation()
    {
        return this->rotation;
    }
};
