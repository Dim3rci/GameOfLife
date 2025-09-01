#pragma

class Cell {
    public:
        Cell(bool alive) : isAlive(alive) {};

        bool getStatus();
        void setStatus(bool alive);

    private:
        bool isAlive;
};