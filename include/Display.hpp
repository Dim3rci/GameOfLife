    #pragma once

    #include "Board.hpp"

    class Display {
        public:
            Display(char alive = 'X', char dead = '.') : alive(alive), dead(dead) {};

            void render(Board& board);
        private:
            char alive;
            char dead;
    };