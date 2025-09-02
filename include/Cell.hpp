#pragma once

/**
 * @class Cell
 * @brief Represents a cell in the Game of Life, which can be either alive or dead.
 * 
 * Each cell maintains its own state and provides methods to query and modify that state.
 * The default state of a cell is dead.
 * This class is designed to be used within a grid structure, such as the Board class.
 */
class Cell {
    public:
        /**
         * @brief Constructs a Cell object.
         * @param alive Initial state of the cell (true for alive, false for dead). Default is false.
         */
        Cell(bool alive = false) : isAlive(alive) {};

        /**
         * @brief Gets the current status of the cell.
         * @return True if the cell is alive, false otherwise.
         */
        bool getStatus() const ;

        /**
         * @brief Sets the status of the cell.
         * @param alive True to set the cell as alive, false to set as dead.
         */
        void setStatus(bool alive);

    private:
        bool isAlive; ///< Indicates whether the cell is alive.
};