#include <raylib.h>
#include <iostream>

// Tryby gry
enum GameState
{
    MENU,
    GAME,
    EXIT_ANIM
};

Rectangle buttons[3] = {
    {340.0f, 200.0f, 120.0f, 30.0f},
    {340.0f, 240.0f, 120.0f, 30.0f},
    {340.0f, 280.0f, 120.0f, 30.0f}};

// Funkcja menu: rysuje i obsługuje input (myszka + klawiatura)
int UpdateDrawMenu()
{
    static int selected = 0;
    Vector2 mouse = GetMousePosition();

    const char *labels[3] = {"Start", "Options", "Exit"};

    // --- RYSUJ PRZYCISKI ---
    DrawText("MENU", 350, 100, 40, BLACK);
    for (int i = 0; i < 3; i++)
    {
        Color bg = (i == selected) ? RED : LIGHTGRAY;
        DrawRectangleRec(buttons[i], bg);
        DrawText(labels[i], buttons[i].x + 10, buttons[i].y + 5, 20, BLACK);
    }

    // --- OBSŁUGA MYSZKI ---
    for (int i = 0; i < 3; i++)
    {
        if (CheckCollisionPointRec(mouse, buttons[i]))
        {
            selected = i; // hover
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                return i; // kliknięcie
        }
    }

    // --- OBSŁUGA KLAWIATURY ---
    if (IsKeyPressed(KEY_DOWN))
        selected++;
    if (IsKeyPressed(KEY_UP))
        selected--;

    if (selected < 0)
        selected = 2;
    if (selected > 2)
        selected = 0;

    if (IsKeyPressed(KEY_ENTER))
        return selected;

    return -1;
}

// Placeholder gry
void UpdateDrawGame()
{
    DrawText("GAME - ESC aby wrocic", 250, 200, 20, Color{0, 100, 0, 255});
}

void SplashScreen()
{
    Texture2D splash = LoadTexture("sponsor.jpg");

    // --- Pobranie rozdzielczości monitora ---
    int screenWidth = GetMonitorWidth(0);
    int screenHeight = GetMonitorHeight(0);

    // --- Skala, żeby zmieścić obraz w połowie ekranu ---
    float maxWidth = screenWidth / 2.0f;
    float maxHeight = screenHeight / 2.0f;

    float scaleX = maxWidth / splash.width;
    float scaleY = maxHeight / splash.height;
    float scale = (scaleX < scaleY) ? scaleX : scaleY; // zachowanie proporcji

    int windowWidth = (int)(splash.width * scale);
    int windowHeight = (int)(splash.height * scale);

    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    SetWindowSize(windowWidth, windowHeight);

    SetTargetFPS(60);

    float alpha = 0.0f;   // fade in
    bool fadeOut = false;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        float posX = 0;
        float posY = 0;

        if (!fadeOut)
        {
            alpha += 0.01f;
            if (alpha >= 1.0f)
            {
                alpha = 1.0f;
                fadeOut = true;
            }
        }
        else
        {
            alpha -= 0.01f;
            if (alpha <= 0.0f)
            {
                alpha = 0.0f;
                break;
            }
        }

        DrawTextureEx(splash, Vector2{posX, posY}, 0.0f, scale, Fade(WHITE, alpha));

        EndDrawing();
    }

    UnloadTexture(splash);
}

void Menu()
{
    float menuAlpha = 0.0f;
    const char* labels[3] = {"Start", "Options", "Exit"};
    int selected = 0;
    int buttonCount = 3;
    float buttonWidth = 200.0f;
    float buttonHeight = 50.0f;
    float buttonSpacing = 20.0f;

    Rectangle dynamicButtons[3];
    float currentScale[3] = {1.0f, 1.0f, 1.0f};

    float titleScale = 1.0f;
    float titleDir = 1.0f;

    bool exitClicked = false;

    while (!WindowShouldClose())
    {
        int winW = GetScreenWidth();
        int winH = GetScreenHeight();
        float startY = winH / 2.0f - (buttonCount * (buttonHeight + buttonSpacing) - buttonSpacing) / 2.0f;

        for (int i = 0; i < buttonCount; i++)
        {
            dynamicButtons[i].width = buttonWidth;
            dynamicButtons[i].height = buttonHeight;
            dynamicButtons[i].x = winW / 2.0f - buttonWidth / 2.0f;
            dynamicButtons[i].y = startY + i * (buttonHeight + buttonSpacing);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (menuAlpha < 1.0f) menuAlpha += 0.02f;

        // pulsujący tytuł
        titleScale += titleDir * 0.002f;
        if (titleScale > 1.1f) titleDir = -1.0f;
        if (titleScale < 0.9f) titleDir = 1.0f;

        int fontSize = 50;
        int textW = MeasureText("MENU", fontSize);
        int textH = fontSize;

        DrawTextPro(GetFontDefault(), "MENU",
                    Vector2{winW / 2.0f, 100 + textH / 2.0f},
                    Vector2{textW / 2.0f, textH / 2.0f},
                    0.0f, fontSize * titleScale, 1.0f, Fade(BLACK, menuAlpha));

        Vector2 mouse = GetMousePosition();

        for (int i = 0; i < buttonCount; i++)
        {
            bool isHover = CheckCollisionPointRec(mouse, dynamicButtons[i]);
            if (isHover) selected = i;

            if (!(exitClicked && i == 2)) // tylko jeśli nie animujemy Exit
            {
                float targetScale = isHover ? 1.1f : 1.0f;
                currentScale[i] += (targetScale - currentScale[i]) * 0.1f;
            }

            // cień
            Rectangle shadow = dynamicButtons[i];
            shadow.x += 4;
            shadow.y += 4;
            shadow.width *= currentScale[i];
            shadow.height *= currentScale[i];
            shadow.x -= (shadow.width - dynamicButtons[i].width) / 2;
            shadow.y -= (shadow.height - dynamicButtons[i].height) / 2;
            DrawRectangleRec(shadow, Fade(DARKGRAY, menuAlpha * 0.5f));

            Rectangle scaledBtn = dynamicButtons[i];
            scaledBtn.width *= currentScale[i];
            scaledBtn.height *= currentScale[i];
            scaledBtn.x -= (scaledBtn.width - dynamicButtons[i].width) / 2;
            scaledBtn.y -= (scaledBtn.height - dynamicButtons[i].height) / 2;

            Color bg = isHover ? RED : LIGHTGRAY;
            DrawRectangleRec(scaledBtn, Fade(bg, menuAlpha));
            DrawText(labels[i],
                     scaledBtn.x + scaledBtn.width / 2 - MeasureText(labels[i], 20) / 2,
                     scaledBtn.y + scaledBtn.height / 2 - 10,
                     20,
                     Fade(BLACK, menuAlpha));
        }

        // Kliknięcie myszy
        if (!exitClicked && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            if (selected == 2) exitClicked = true; // Exit → animacja, potem zamkniecie
        }

        // Klawiatura
        if (!exitClicked)
        {
            if (IsKeyPressed(KEY_DOWN)) selected++;
            if (IsKeyPressed(KEY_UP)) selected--;
            if (selected < 0) selected = buttonCount - 1;
            if (selected >= buttonCount) selected = 0;

            if (IsKeyPressed(KEY_ENTER) && selected == 2)
            {
                exitClicked = true; // Enter na Exit
            }

            if (IsKeyPressed(KEY_ESCAPE))
            {
                CloseWindow();
                exit(0); // kończymy program
            }
        }

        EndDrawing();

        // animacja Exit
        if (exitClicked)
        {
            currentScale[2] -= 0.05f;
            if (currentScale[2] <= 0.05f)
            {
                CloseWindow();   // zamknięcie okna
                exit(0);         // natychmiastowe zakończenie programu
            }
        }
    }
}

int main()
{
    InitWindow(800, 450, "Splash Screen"); // tymczasowe
    SetTargetFPS(60);

    SplashScreen();

    SetWindowSize(1920, 1080);
    ToggleFullscreen();
    
    Menu();
    
    CloseWindow();
}