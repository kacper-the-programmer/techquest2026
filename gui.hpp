#pragma once

#include <raylib.h>
#include <string>

class image
{
private:
    std::string path;
    Texture2D texture;
    int x;
    int y;

public:
    image(std::string path, int x, int y)
    {
        change_image(path);
    }
    ~image()
    {
    }
    void change_image(std::string path)
    {
        this->texture = LoadTexture(path.c_str());
    }
    void draw()
    {
        DrawTexture(this->texture, this->x, this->y, WHITE);
    }
};

class button
{
private:
    std::string path;
    Texture2D normal_texture;
    Texture2D click_texture;
    int x;
    int y;
    int width;
    int height;
    float rotation;
    Rectangle hitbox;

    Texture2D texture;

public:
    button(std::string path_normal, std::string path_clicked, int x, int y)
    {
        change_normal_texture(path_normal);
        change_click_texture(path_clicked);
        texture = normal_texture;
        hitbox = {(float)this->x, (float)this->y, (float)this->x + this->texture.width, (float)this->y + this->texture.height};
    }
    ~button()
    {
    }
    void change_normal_texture(std::string path)
    {
        this->normal_texture = LoadTexture(path.c_str());
    }
    void change_click_texture(std::string path)
    {
        this->click_texture = LoadTexture(path.c_str());
    }

    void set_to_normal()
    {
        this->texture = this->normal_texture;
    }

    void set_to_clicked()
    {
        this->texture = this->click_texture;
    }

    void on_click(void *func)
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), this->hitbox))
        {
            set_to_clicked();
        }
    }

    void draw()
    {
        DrawTexture(this->texture, this->x, this->y, WHITE);
    }
};
