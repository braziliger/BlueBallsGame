class BigBallsGame
{
    private:
        typedef enum TitleScreenSteps { WAIT = 0, BIG, BLU, BALLS, TITLE} GameScreen;

    public:
        BigBallsGame();
        void TitleScreen();
        void LoadLevelOne();
};