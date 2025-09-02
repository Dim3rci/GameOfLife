#pragma once

#include "Board.hpp"

/**
 * @class GameRules
 * @brief Encapsulates the rules for cell birth and survival in the Game of Life.
 */
class GameRules {
    public:
        /**
         * @brief Constructs a GameRules object with specified birth and survival ranges.
         * @param birthMin Minimum number of neighbors for a cell to be born.
         * @param birthMax Maximum number of neighbors for a cell to be born.
         * @param surviveMin Minimum number of neighbors for a cell to survive.
         * @param surviveMax Maximum number of neighbors for a cell to survive.
         */
        GameRules(int birthMin = 3, int birthMax = 3, int surviveMin = 2, int surviveMax = 3)
            : birthMin(birthMin), birthMax(birthMax), surviveMin(surviveMin), surviveMax(surviveMax) {}

        /**
         * @brief Determines if a cell should live in the next generation.
         * @param isCurrentlyAlive Current status of the cell.
         * @param aliveNeighbors Number of alive neighboring cells.
         * @return True if the cell should be alive in the next generation, false otherwise.
         */
        bool shouldCellLive(bool isCurrentlyAlive, int aliveNeighbors) const;

    private:
        int birthMin;    ///< Minimum neighbors for birth.
        int birthMax;    ///< Maximum neighbors for birth.
        int surviveMin;  ///< Minimum neighbors for survival.
        int surviveMax;  ///< Maximum neighbors for survival.
};