#pragma once

    #include "Board.hpp"

    /**
     * @class Display
     * @brief Handles rendering of the Game of Life board.
     */
    class Display {
        public:
            /**
             * @brief Constructs a Display object.
             * @param alive Character used to represent alive cells. Default is 'X'.
             * @param dead Character used to represent dead cells. Default is '.'.
             */
            Display(char alive = 'X', char dead = '.') : alive(alive), dead(dead) {};

            /**
             * @brief Renders the current state of the board.
             * @param board Reference to the Board to render.
             */
            void render(Board& board);
        private:
            char alive; ///< Character representing alive cells.
            char dead;  ///< Character representing dead cells.
    };