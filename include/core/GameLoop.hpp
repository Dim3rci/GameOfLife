#pragma once

#include "core/Board.hpp"
#include "core/GameRules.hpp"
#include "ui/Display.hpp"

/**
 * @class GameLoop
 * @brief Manages the main loop and generation updates for the Game of Life.
 */
class GameLoop {
    public:
        /**
         * @brief Constructs a GameLoop object.
         * @param board Reference to the game board.
         * @param rules The rules for cell birth and survival.
         * @param display The display handler for rendering the board.
         */
        GameLoop(Board& board, const GameRules& rules, Display display) : board(board), rules(rules), display(display) {}

        /**
         * @brief Advances the board to the next generation.
         */
        void nextGeneration();

        /**
         * @brief Fills the next generation's cell states.
         * @param nextEstate Reference to the next generation's state vector.
         * @return A 2D vector of boolean values representing the new cell states.
         */
        std::vector<std::vector<bool>> fillNewGeneration(std::vector<std::vector<bool>>& nextEstate) const;

        /**
         * @brief Runs the main game loop.
         */
        void loop();

    private:
        Board& board;             ///< Reference to the game board.
        const GameRules& rules;   ///< Reference to the game rules.
        Display display;          ///< Display handler for rendering.
};

