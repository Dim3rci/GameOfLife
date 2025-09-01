#pragma once

/**
 * @brief Represents a cell in the Game of Life, which can be either alive or dead.
 * Each cell maintains its own state and provides methods to query and modify that state.
 * The default state of a cell is dead.
 * @note This class is designed to be used within a grid structure, such as the Board class.
 * 
 */
class Cell {
    public:
        Cell(bool alive = false) : isAlive(alive) {};

        bool getStatus() const ;
        void setStatus(bool alive);

    private:
        bool isAlive;
};