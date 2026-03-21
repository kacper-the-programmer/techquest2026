#pragma once

#include <raylib.h>
#include <string>
#include <functional>

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
        change_position(x, y);
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
    void change_position(float x, float y)
    {
        this->position = {x, y};
    }
    void change_y(float value)
    {
        this->position.y = value;
    }
    float get_center_x()
    {
        return this->position.x + (this->texture.width / 2);
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
    float size;
    std::string value;

    Texture2D texture;

public:
    button(std::string value, std::string path_normal, std::string path_clicked, float x, float y, float size)
    {
        change_normal_texture(path_normal);
        change_click_texture(path_clicked);
        texture = normal_texture;
        this->size = size;
        this->value = value;
        hitbox = {this->x, this->y, (float)this->x + this->texture.width * this->size, (float)this->y + this->texture.height * this->size};
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

    void on_click(std::function<void()> func)
    {
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(GetMousePosition(), this->hitbox))
        {
            // set_to_clicked();
            func();
        }
    }

    void draw()
    {
        DrawTextureEx(this->texture, {this->x, this->y}, 0, this->size, WHITE);
        DrawText(this->value.c_str(), this->x, this->y, 50, BLACK);
    }
};

class advance_image_widget
{
private:
    Texture2D texture;
    float scale;
    float rotation;
    float x;
    float y;

public:
    advance_image_widget(std::string path, float x, float y, float scale, float rotation)
    {
        this->texture = LoadTexture(path.c_str());
        change_rotation(rotation);
        this->scale = scale;
        this->x = x;
        this->y = y;
    }
    ~advance_image_widget()
    {
        UnloadTexture(this->texture);
    }

    void change_rotation(float rotation)
    {
        this->rotation = rotation;
    }
    float get_rotation()
    {
        return this->rotation;
    }

    void draw()
    {
        float scaledW = texture.width * this->scale;
        float scaledH = texture.height * this->scale;

        Vector2 origin = {
            scaledW / 2.0f,
            scaledH / 2.0f};

        Vector2 position = {
            GetScreenWidth() / 2.0f,
            GetScreenHeight() / 2.0f};

        DrawTexturePro(
            this->texture,
            {
                0.0f,
                0.0f,
                (float)texture.width,
                (float)texture.height,
            },
            {this->x,
             this->y,
             scaledW,
             scaledH},
            origin,
            this->rotation,
            WHITE);
    }
};
