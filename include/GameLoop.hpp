#pragma once

#include "Board.hpp"
#include "GameRules.hpp"
#include "Display.hpp"

class GameLoop {
    public:
        GameLoop(Board& board, const GameRules& rules, Display display) : board(board), rules(rules), display(display) {}

        void nextGeneration();
        std::vector<std::vector<bool>> fillNewGeneration(std::vector<std::vector<bool>>& nextEstate) const;
        void loop();

    private:
        Board& board;
        const GameRules& rules;
        Display display;
};

