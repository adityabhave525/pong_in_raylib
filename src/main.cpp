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

        if (y + radius >= GetScreenHeight() || y - radius <= 0)
        {
            speed_y *= -1;
        }

        if (x + radius >= GetScreenWidth() || x - radius <= 0)
        {
            speed_x *= -1;
        }
    }
};

class Paddle
{
public:
    float x, y;
    float width, height;
    int speed;

    void Draw()
    {
        DrawRectangle(x, y, width, height, WHITE);
    }

    void Update()
    {
        if (IsKeyDown(KEY_UP))
        {
            y = y - speed;
        }

        if (IsKeyDown(KEY_DOWN))
        {
            y = y + speed;
        }

        if (y <= 0)
        {
            y = 0;
        }

        if (y + height >= GetScreenHeight())
        {
            y = GetScreenHeight() - height;
        }
    }
};

Ball ball;
Paddle player;

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

    // Player paddle
    player.width = 25;
    player.height = 120;
    player.x = screen_width - player.width - paddle_offset;
    player.y = screen_height / 2 - player.height / 2;
    player.speed = 6;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        // Updating
        ball.Update();
        player.Update();

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
        player.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}