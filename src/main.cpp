#include <iostream>
#include <raylib.h>

int main()
{
    std::cout << "Starting the game" << '\n';

    const int screen_width = 1280;
    const int screen_height = 800;

    const int paddle_width = 25;
    const int paddle_height = 120;

    const int paddle_offset = 10;

    InitWindow(screen_width, screen_height, "My Pong Game");

    SetTargetFPS(60);

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Drawing

        // Drawing the mid line
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);
        
        // Ball
        DrawCircle(screen_width / 2, screen_height / 2, 20, WHITE);
        
        // Paddle 1
        // 60 being half of 120 which is the paddles height
        DrawRectangle(paddle_offset, screen_height / 2 - 60, paddle_width, paddle_height, WHITE);

        // Paddle 2
        // yPos = screen_width - 25 (Paddle width) - 10 (pixels from right border)
        DrawRectangle(screen_width - paddle_width - paddle_offset, screen_height / 2 - 60, paddle_width, paddle_height, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}