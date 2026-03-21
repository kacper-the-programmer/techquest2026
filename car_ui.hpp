#pragma once

#include <raylib.h>

#include "car.hpp"
#include "gui.hpp"

class car_ui
{
private:
    car *player;
    float blinker_timer = 0.0f;
    bool blinker_state = false;

    image_widget *dashbord;
    image_widget *meter_holder;

    image_widget *speedmeter;
    image_widget *grademeter;

    button *key_in;

    image_widget *pedal_clutch;
    image_widget *pedal_break;
    image_widget *pedal_gas;

    advance_image_widget *speed_pointer;
    advance_image_widget *grade_pointer;

    image_widget *blinker_left;
    image_widget *blinker_right;

    image_widget *gears;

public:
    car_ui(car *player)
    {
        this->player = player;
    }

    void engine(void)
    {
        if (!this->player->get_engine_value())
        {
            this->key_in->set_to_clicked();
            this->player->set_engine_value(true);
        }
        else
        {
            this->key_in->set_to_normal();
            this->player->set_engine_value(false);
        }
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

        this->key_in = new button(
            "",
            "assets/gui/key/in_0.png",
            "assets/gui/key/in_1.png",
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
            0);

        this->grade_pointer = new advance_image_widget(
            "assets/gui/meters/pointer.png",
            static_cast<float>(GetScreenWidth() / 3.20),
            static_cast<float>(GetScreenHeight() / 1.18),
            3,
            270);

        this->blinker_left = new image_widget(
            "assets/gui/blinkers/left_0.png",
            static_cast<float>(GetScreenWidth() / 6),
            static_cast<float>(GetScreenHeight() / 1.5),
            2.5);

        this->blinker_right = new image_widget(
            "assets/gui/blinkers/right_0.png",
            static_cast<float>(GetScreenWidth() / 4.5),
            static_cast<float>(GetScreenHeight() / 1.5),
            2.5);

        this->gears = new image_widget(
            "assets/gui/gears.png",
            static_cast<float>(GetScreenWidth() / 1.45),
            static_cast<float>(GetScreenHeight() / 1.29),
            2);
    }

    void logic()
    {
        this->key_in->on_click([this]()
                               { engine(); });
        this->speed_pointer->change_rotation(this->player->get_speed() / 2.21);

        switch (this->player->get_gear())
        {
        case 0:
            this->gears->change_image("assets/gui/gears_0.png");
            break;
        case 1:
            if (this->player->get_reverse())
            {
                this->gears->change_image("assets/gui/gears_R.png");
            }
            else
            {
                this->gears->change_image("assets/gui/gears_0.png");
            }
            break;
        case 2:
            this->gears->change_image("assets/gui/gears_2.png");
            break;
        case 3:
            this->gears->change_image("assets/gui/gears_3.png");
            break;
        case 4:
            this->gears->change_image("assets/gui/gears_4.png");
            break;
        case 5:
            this->gears->change_image("assets/gui/gears_5.png");
            break;
        case 6:
            this->gears->change_image("assets/gui/gears_6.png");
            break;
        default:
            break;
        }
    }
    void input()
    {
        if (IsKeyDown(KEY_W) && !IsKeyDown(KEY_Q))
        {
            this->pedal_gas->change_image("assets/gui/pedals/gas_1.png");
            this->pedal_gas->change_y(-50);
        }
        else
        {
            this->pedal_gas->change_image("assets/gui/pedals/gas_0.png");
            this->pedal_gas->change_y(0);
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

        if (IsKeyDown(KEY_Q) && !IsKeyDown(KEY_W))
        {
            this->pedal_clutch->change_image("assets/gui/pedals/clutch_1.png");
            this->pedal_clutch->change_y(-50);
        }
        else
        {
            this->pedal_clutch->change_image("assets/gui/pedals/clutch_0.png");
            this->pedal_clutch->change_y(0);
        }

        if (IsKeyDown(KEY_E))
        {
            blinker_timer += GetFrameTime();

            if (blinker_timer >= 0.4f)
            {
                blinker_state = !blinker_state;
                blinker_timer = 0.0f;
            }

            if (blinker_state)
                blinker_left->change_image("assets/gui/blinkers/left_1.png");
            else
                blinker_left->change_image("assets/gui/blinkers/left_0.png");
        }
        if (IsKeyDown(KEY_R))
        {
            blinker_timer += GetFrameTime();

            if (blinker_timer >= 0.4f)
            {
                blinker_state = !blinker_state;
                blinker_timer = 0.0f;
            }

            if (blinker_state)
                blinker_right->change_image("assets/gui/blinkers/right_1.png");
            else
                blinker_right->change_image("assets/gui/blinkers/right_0.png");
        }
        if (!IsKeyDown(KEY_E) && !IsKeyDown(KEY_R))
        {

            blinker_left->change_image("assets/gui/blinkers/left_0.png");
            blinker_right->change_image("assets/gui/blinkers/right_0.png");

            blinker_timer = 0.0f;
            blinker_state = false;
        }
    }

    void draw()
    {
        this->dashbord->draw();
        this->meter_holder->draw();
        this->speedmeter->draw();
        this->grademeter->draw();
        this->key_in->draw();
        this->pedal_clutch->draw();
        this->pedal_break->draw();
        this->pedal_gas->draw();
        this->speed_pointer->draw();
        this->grade_pointer->draw();
        this->blinker_left->draw();
        this->blinker_right->draw();
        this->gears->draw();
    }
};
