#include <iostream>
#include <raylib.h>

class Ball
{
public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw()
    {
        DrawCircle(x, y, radius, WHITE);
    }

    void Update()
    {
        x += speed_x;
        y += speed_y;
    }
};

Ball ball;

int main()
{
    std::cout << "Starting the game" << '\n';

    // Constants
    const int screen_width = 1280;
    const int screen_height = 800;

    const int paddle_width = 25;
    const int paddle_height = 120;

    const int paddle_offset = 10;

    InitWindow(screen_width, screen_height, "My Pong Game");

    SetTargetFPS(60);

    // Init the ball object
    ball.radius = 20;
    ball.x = screen_width / 2;
    ball.y = screen_height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating
        ball.Update();

        // Drawing
        ClearBackground(BLACK);

        // Drawing the mid line
        DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, WHITE);

        // Ball
        ball.Draw();

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