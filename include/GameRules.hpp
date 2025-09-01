#pragma once

#include "Board.hpp"

class GameRules {
    public:
        GameRules(int birthMin = 3, int birthMax = 3, int surviveMin = 3, int surviveMax = 3)
            : birthMin(birthMin), birthMax(birthMax), surviveMin(surviveMin), surviveMax(surviveMax) {}

        bool shouldCellLive(bool isCurrentlyAlive, int aliveNeighbors) const;

    private:
        int birthMin;
        int birthMax;
        int surviveMin;
        int surviveMax;
};