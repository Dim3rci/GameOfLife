#include "GameRules.hpp"

bool GameRules::shouldCellLive(bool isCurrentlyAlive, int aliveNeighbors) const {
    if (isCurrentlyAlive) {
        return aliveNeighbors >= surviveMin && aliveNeighbors <= surviveMax;
    } else {
        return aliveNeighbors >= birthMin && aliveNeighbors <= birthMax;
    }
}