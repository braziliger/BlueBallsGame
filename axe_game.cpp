#include "raylib.h"
#include "circle.h"

int main() 
{
    // window dimensions
    int width = 800;
    int height = 800;
    InitWindow(width, height, "death to circle");
    
    // circle coords
    int circle_r = 50;
    int circle_x = width/2;
    int circle_y = height/2;
    int circle_speed = 10;

    // circle edges
    int l_circle_x = circle_x - circle_r;
    int r_circle_x = circle_x + circle_r;
    int u_circle_y = circle_y - circle_r;
    int b_circle_y = circle_y - circle_r;

    // axe coords
    int axe_x = width/2;
    int axe_y = 0;
    int axe_len = 30;

    // axe edges
    int l_axe_x = axe_x;
    int r_axe_x = axe_x + axe_len;
    int u_axe_y = axe_y;
    int b_axe_y = axe_y + axe_len;

    int axe_direction = 10;

    bool collision = false;

    SetTargetFPS(60);

    PlayerCircle c = PlayerCircle(25, 100, 100, 25);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision) {
            DrawText("DEAD", 400, 200, 50, RED);
        }
        else
        {
            // game logic begins here

            // update edges
            l_circle_x = circle_x - circle_r;
            r_circle_x = circle_x + circle_r;
            u_circle_y = circle_y - circle_r;
            b_circle_y = circle_y - circle_r;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_len;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_len;

            collision = 
                b_axe_y >= u_circle_y
                && u_axe_y <= b_circle_y
                && l_axe_x <= r_circle_x
                && r_axe_x >= l_circle_x;

            DrawCircle(circle_x, circle_y, circle_r, BLUE);
            DrawRectangle(axe_x, axe_y, axe_len, axe_len, BLACK);

            // move the axe
            axe_y += axe_direction;
            if (axe_y > height || axe_y < 0) {
                axe_direction *= -1;
            }

            if (IsKeyDown(KEY_D) && circle_x < width-circle_r) {
                circle_x += circle_speed;
            }
            else if (IsKeyDown(KEY_A) && circle_x > 0+circle_r) {
                circle_x -= circle_speed;
            }
            else if (IsKeyDown(KEY_W) && circle_y > 0+circle_r) {
                circle_y -= circle_speed;
            }
            else if (IsKeyDown(KEY_S) && circle_y < height-circle_r) {
                circle_y += circle_speed;
            }
            // game logic ends
        }

        EndDrawing();
    }
}