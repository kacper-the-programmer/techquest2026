#pragma once

#include <raylib.h>
#include <string>

class image_widget
{
private:
    std::string path;
    Texture2D texture;
    Vector2 position;

    float scale;

public:
    image_widget(std::string path, float x, float y, float scale)
    {
        change_image(path);
        this->position = {x, y};
        this->scale = scale;
    }
    ~image_widget()
    {
        UnloadTexture(texture);
    }
    void change_image(std::string path)
    {
        this->texture = LoadTexture(path.c_str());
    }
    void draw()
    {
        DrawTextureEx(this->texture, this->position, 0, this->scale, WHITE);
    }
};

class button
{
private:
    std::string path;
    Texture2D normal_texture;
    Texture2D click_texture;
    float x;
    float y;
    int width;
    int height;
    float rotation;
    Rectangle hitbox;

    Texture2D texture;

public:
    button(std::string path_normal, std::string path_clicked, float x, float y)
    {
        change_normal_texture(path_normal);
        change_click_texture(path_clicked);
        texture = normal_texture;
        hitbox = {this->x, this->y, (float)this->x + this->texture.width, (float)this->y + this->texture.height};
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
