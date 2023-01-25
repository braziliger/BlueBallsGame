
class PlayerCircle
{
    private:
        int circle_r;
        int circle_x;
        int circle_y;
        int speed;

        int l_circle_x;
        int r_circle_x;
        int u_circle_y;
        int b_circle_y;

    public:
        PlayerCircle(int r, int x, int y, int speed);

        void Move(int key);
        void Draw();
};