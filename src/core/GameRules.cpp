#include <iostream>

#include "core/GameRules.hpp"

/**
 * @brief Determine if a cell should be alive in the next generation.
 * 
 * Applies the Game of Life rules based on the current status and number of alive neighbors.
 * 
 * @param isCurrentlyAlive True if the cell is currently alive.
 * @param aliveNeighbors Number of alive neighboring cells.
 * @return true if the cell should be alive in the next generation, false otherwise.
 */
bool GameRules::shouldCellLive(bool isCurrentlyAlive, int aliveNeighbors) const {
    if (isCurrentlyAlive) {
        return aliveNeighbors >= surviveMin && aliveNeighbors <= surviveMax;
    } else {
        return aliveNeighbors >= birthMin && aliveNeighbors <= birthMax;
    }
}