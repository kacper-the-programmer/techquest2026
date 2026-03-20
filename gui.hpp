#pragma once

#include <raylib.h>
#include <string>

class image
{
private:
    std::string path;
    Texture2D texture;

public:
    image(std::string path, int x, int y)
    {
        change_img(path);
    }
    ~image()
    {
    }
    void change_img(std::string path)
    {
        this->texture = LoadTexture(path.c_str());
    }
    void draw()
    {
        DrawTexture(texture, );
    }
};