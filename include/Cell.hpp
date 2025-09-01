#pragma once

class Cell {
    public:
        Cell(bool alive = false) : isAlive(alive) {};

        bool getStatus() const ;
        void setStatus(bool alive);

    private:
        bool isAlive;
};