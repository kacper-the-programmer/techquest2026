#pragma once

#include <raylib.h>

#include "car.hpp"
#include "gui.hpp"

class car_ui
{
private:
    car *player;

    image_widget *dashbord;
    image_widget *meter_holder;

    image_widget *speedmeter;
    image_widget *grademeter;

    image_widget *key_in;

    image_widget *pedal_clutch;
    image_widget *pedal_break;
    image_widget *pedal_gas;

    advance_image_widget *speed_pointer;

public:
    car_ui(car *player)
    {
        this->player = player;
    }

    void init()
    {
        this->dashbord = new image_widget(
            "assets/gui/dashboard.png",
            0,
            static_cast<float>(GetScreenHeight() / 1.35),
            15);

        this->meter_holder = new image_widget(
            "assets/gui/meter_holder.png",
            static_cast<float>(GetScreenWidth() / 11.8),
            static_cast<float>(GetScreenHeight() / 1.8),
            9);

        this->speedmeter = new image_widget(
            "assets/gui/meters/speed.png",
            static_cast<float>(GetScreenWidth() / 10),
            static_cast<float>(GetScreenHeight() / 1.35),
            3);

        this->grademeter = new image_widget(
            "assets/gui/meters/grade.png",
            static_cast<float>(GetScreenWidth() / 3.9),
            static_cast<float>(GetScreenHeight() / 1.35),
            3);

        this->key_in = new image_widget(
            "assets/gui/key/in_0.png",
            static_cast<float>(GetScreenWidth() / 2.65),
            static_cast<float>(GetScreenHeight() - (GetScreenHeight() / 9.7)),
            4);

        this->pedal_clutch = new image_widget(
            "assets/gui/pedals/clutch_0.png",
            50,
            0,
            3);

        this->pedal_break = new image_widget(
            "assets/gui/pedals/break_0.png",
            200,
            0,
            3);

        this->pedal_gas = new image_widget(
            "assets/gui/pedals/gas_0.png",
            350,
            0,
            3);

        this->speed_pointer = new advance_image_widget(
            "assets/gui/meters/pointer.png",
            static_cast<float>(GetScreenWidth() / 6.35),
            static_cast<float>(GetScreenHeight() / 1.2),
            3,
            -150);
    }

    void logic()
    {
        this->speed_pointer->change_rotation(this->player->get_speed() - 150);
    }
    void input()
    {
        if (IsKeyDown(KEY_W))
        {
            this->pedal_gas->change_image("assets/gui/pedals/gas_1.png");
            this->pedal_break->change_y(-50);
        }
        else
        {
            this->pedal_gas->change_image("assets/gui/pedals/gas_0.png");
            this->pedal_break->change_y(0);
        }

        if (IsKeyDown(KEY_S))
        {
            this->pedal_break->change_image("assets/gui/pedals/break_1.png");
            this->pedal_break->change_y(-50);
        }
        else
        {
            this->pedal_break->change_image("assets/gui/pedals/break_0.png");
            this->pedal_break->change_y(0);
        }

        if (IsKeyDown(KEY_Q))
        {
            this->pedal_clutch->change_image("assets/gui/pedals/clutch_1.png");
            this->pedal_clutch->change_y(-50);
        }
        else
        {
            this->pedal_clutch->change_image("assets/gui/pedals/clutch_0.png");
            this->pedal_clutch->change_y(0);
        }
    }

    void draw()
    {
        DrawText(std::to_string(this->player->get_speed()).c_str(), 100, 0, 20, BLACK);
        DrawText(std::to_string(this->player->get_max_speed() / 100).c_str(), 400, 0, 20, BLACK);

        // this->speedmeter->draw();
        this->dashbord->draw();
        this->meter_holder->draw();
        this->speedmeter->draw();
        this->grademeter->draw();
        this->key_in->draw();
        this->pedal_clutch->draw();
        this->pedal_break->draw();
        this->pedal_gas->draw();
        this->speed_pointer->draw();
    }
};
