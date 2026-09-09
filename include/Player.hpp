namespace ruezo {
    class GameHandler;

    class Player {
    private:
        int x, y, w, h;
        GameHandler* game = nullptr;
    public:
        Player(int width, int height, int x = 0, int y = 0);
        void linkGame(GameHandler* gh);
    };
}