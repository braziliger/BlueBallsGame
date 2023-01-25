#include "raylib.h"
#include <iostream>
#include <unistd.h>
#include "BigBallsGame.h"

int main() 
{
    BigBallsGame game = BigBallsGame();

    game.TitleScreen();
    game.LoadLevelOne();
}