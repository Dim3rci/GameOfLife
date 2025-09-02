#pragma once

#include <vector>
#include <functional>
#include <string>

#include "Cell.hpp"

/**
 * @brief Represents the game board for Game of Life.
 */
class Board {
    public:
        /**
         * @brief Constructs a Board with given dimensions.
         * @param height Number of rows.
         * @param length Number of columns.
         */
        Board(int height = 10, int length = 10) : height(height), length(length), grid(height, std::vector<Cell>(length)) {};

        /**
         * @brief Gets the size of the grid.
         * @return Pair of (height, length).
         */
        std::pair<int, int> getGridSize() const;

        /**
         * @brief Fills the board randomly with alive cells based on probability.
         * @param aliveProbability Probability that a cell is alive.
         */
        void fillRandomly(float aliveProbability = 0.3);

        /**
         * @brief Fills the board from a file.
         * @param filename Path to the file.
         * @param alive Character representing alive cells.
         * @param dead Character representing dead cells.
         */
        void fillFromFile(const std::string& filename, char alive = 'X', char dead = '.');

        /**
         * @brief Checks if a cell is alive.
         * @param x Row index.
         * @param y Column index.
         * @return True if cell is alive, false otherwise.
         */
        bool isCellAlive(int x, int y) const;

        /**
         * @brief Sets the status of a cell.
         * @param x Row index.
         * @param y Column index.
         * @param isAlive True to set cell alive, false for dead.
         */
        void setCellStatus(int x, int y, bool isAlive);

        /**
         * @brief Applies a callback to each cell in the board.
         * @param callback Function to call for each cell.
         */
        void forEachCell(std::function<void(int, bool)> callback) const;

        /**
         * @brief Counts the number of alive neighbors for a cell.
         * @param x Row index.
         * @param y Column index.
         * @return Number of alive neighbors.
         */
        int countAliveNeighbors(int x, int y) const;

        /**
         * @brief Updates the board to the next state.
         * @param nextState 2D vector of bools representing the next state.
         */
        void updateBoard(const std::vector<std::vector<bool>>& nextState);
    private:
        int height; ///< Number of rows.
        int length; ///< Number of columns.
        std::vector<std::vector<Cell>> grid; ///< 2D grid of cells.
};