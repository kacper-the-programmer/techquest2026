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
