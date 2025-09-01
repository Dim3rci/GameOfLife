#include "GameRules.hpp"
#include <iostream>

bool GameRules::shouldCellLive(bool isCurrentlyAlive, int aliveNeighbors) const {
    if (isCurrentlyAlive) {
        return aliveNeighbors >= surviveMin && aliveNeighbors <= surviveMax;
    } else {
        return aliveNeighbors >= birthMin && aliveNeighbors <= birthMax;
    }
}