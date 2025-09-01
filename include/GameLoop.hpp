#pragma once

#include "Board.hpp"
#include "GameRules.hpp"

class GameLoop {
    public:
        GameLoop(Board& board, const GameRules& rules) : board(board), rules(rules) {}

        void nextGeneration();
        std::vector<std::vector<bool>> fillNewGeneration(std::vector<std::vector<bool>>& nextEstate) const;

    private:
        Board& board;
        const GameRules& rules;
};

