#pragma

#include "Cell.hpp"
#include <vector>

class Board {
    public:
        Board(int width = 10, int length = 10) : width(width), length(length), grid(width, std::vector<Cell>(length)) {};

    private:
        int width;
        int length;
        std::vector<std::vector<Cell>> grid;
};