#include <raylib.h>

class car
{
private:
    int width = 50;
    int height = 100;
    int x = 0;
    int y = 0;

    float speed = 0;

public:
    car()
    {
    }
    ~car()
    {
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
            this->y++;
        }
        if (IsKeyDown(KEY_S))
        {
            this->y--;
        }
    }

    void draw()
    {
        DrawRectangle(this->x, this->y, this->width, this->height, RED);
    }
};
