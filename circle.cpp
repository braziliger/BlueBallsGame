#include "circle.h"
#include "raylib.h"

PlayerCircle::PlayerCircle(int r, int x, int y, int speed)
{
    circle_r = r;
    circle_x = x;
    circle_y = y;
    speed = speed;

    l_circle_x = circle_x - circle_r;
    r_circle_x = circle_x + circle_r;
    u_circle_y = circle_y - circle_r;
    b_circle_y = circle_y - circle_r;
}

void PlayerCircle::Draw()
{
    DrawCircle(circle_x, circle_y, circle_r, BLUE);
}

void PlayerCircle::Move(int key)
{
    switch(key)
    {
        case KEY_A:
            circle_x -= speed;
            break;
        case KEY_W:
            circle_y -= speed;
            break;
        case KEY_S:
            circle_y += speed;
            break;
        case KEY_D:
            circle_x += speed;
            break;
        default:
            // do nothing
            break;
    }
}