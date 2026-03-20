#pragma once

#include <raylib.h>
#include <string>
#include <vector>

#include "gui.hpp"

class car
{
private:
    float width;
    float height;
    int rotation = 0;
    float scale = 3;
    float max_speed = 0;
    float speed = 0;
    int speed_constant = 40;
    int gear = 0;

    Texture2D texture;
    Rectangle source;
    Rectangle destination;
    Vector2 origin;

    image_widget dashbord{"assets/gui/dashboard.png", 0, (GetScreenHeight() - (GetScreenHeight() / 4)), 1};
    image_widget meter_holder{"assets/gui/meter_holder.png", GetScreenWidth() / 12, (GetScreenHeight() - (GetScreenHeight() / 2.5)), 9};

    image_widget speedmeter{"assets/gui/meters/speed.png", 0, 0, 3};
    // image x = new image("assets/meters/speed.png", 0, 0);

    std::vector<Sound> sfx = {
        LoadSound("assets/sfx/working_eng.wav"),
    };

public:
    car(int variant, float scale)
    {
        std::string texture_path = "assets/car/" + std::to_string(variant) + ".png";
        texture = LoadTexture(texture_path.c_str());
        this->scale *= scale;

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

    void loop()
    {
        if (!IsSoundPlaying(sfx[0]))
        {
            PlaySound(sfx[0]);
        }
        if (this->gear > 0 && this->speed <= 0.0f)
        {
            this->speed = 0;
        }
    }

    void input()
    {
        if (IsKeyDown(KEY_W) && (this->speed <= this->max_speed && this->gear > 0 || this->speed >= this->max_speed && this->gear == -1))
        {
            this->speed += this->speed_constant * GetFrameTime();
        }
        if (IsKeyDown(KEY_S) && (this->speed >= 0 && this->gear > 0 || this->speed <= 0 && this->gear == -1))
        {
            this->speed -= this->speed_constant * 3 * GetFrameTime();
        }
        if (!IsKeyDown(KEY_W) && this->speed > 0)
        {
            this->speed -= this->speed_constant * 0.5 * GetFrameTime();
        }

        if (IsKeyDown(KEY_A) && (this->speed > 1 || this->speed < -1))
        {
            this->rotation -= 20 * speed_constant / 10 * GetFrameTime();
        }
        if (IsKeyDown(KEY_D) && (this->speed > 1 || this->speed < -1))
        {
            this->rotation += 20 * speed_constant / 10 * GetFrameTime();
        }

        if (IsKeyDown(KEY_Q) && !IsKeyDown(KEY_W))
        {

            if (IsKeyDown(KEY_ONE))
            {
                this->max_speed = 100;
                this->speed_constant = 30;
            }
            if (IsKeyDown(KEY_TWO))
            {
                this->max_speed = 200;
                this->speed_constant = 40;
            }
            if (IsKeyDown(KEY_THREE))
            {
                this->max_speed = 300;
                this->speed_constant = 50;
            }
            if (IsKeyDown(KEY_FOUR))
            {
                this->max_speed = 400;
                this->speed_constant = 60;
            }
            if (IsKeyDown(KEY_FIVE))
            {
                this->max_speed = 500;
                this->speed_constant = 70;
            }
            if (IsKeyDown(KEY_SIX))
            {
                this->max_speed = 600;
                this->speed_constant = 80;
            }
            if (IsKeyDown(KEY_ZERO))
            {
                this->max_speed = 0;
                this->speed_constant = 0;
            }
            if (IsKeyDown(KEY_MINUS))
            {
                this->max_speed = -100;
                this->speed_constant = -30;
            }
            this->gear = this->max_speed / 100;
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

    void init_gui()
    {
        // this->speedmeter = new image_widget();
    }

    void draw_gui()
    {
        DrawText(std::to_string(this->speed).c_str(), 100, 0, 20, BLACK);
        DrawText(std::to_string(this->max_speed / 100).c_str(), 400, 0, 20, BLACK);

        // this.speedmeter.draw();
        // this->speedmeter->draw();
        this->dashbord.draw();
        this->meter_holder.draw();
    }
};
