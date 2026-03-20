#include <raylib.h>

class car
{
private:
    int width = 50;
    int height = 100;
    float x = 0;
    float y = 0;
    int rotation;
    float speed = 0;

    Texture2D texture;

public:
    car()
    {
        texture = LoadTexture("assets/car.png");
    }
    ~car()
    {
        UnloadTexture(texture);
    }
    void input()
    {
        if (IsKeyDown(KEY_A))
        {
            this->x--;
        }
        if (IsKeyDown(KEY_D))
        {
            this->x++;
        }
        if (IsKeyDown(KEY_W))
        {
            this->y--;
        }
        if (IsKeyDown(KEY_S))
        {
            this->y++;
        }
    }

    void draw()
    {
        // DrawRectangle(this->x, this->y, this->width, this->height, RED);
        // DrawTexture(texture, x, y, WHITE);
        Vector2 position = {this->x, this->y};
        DrawTextureEx(texture, position, 0, 1, WHITE);
    }
};
