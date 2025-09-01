#pragma once

#include <vector>
#include <functional>

#include "Cell.hpp"

class Board {
    public:
        Board(int width = 10, int length = 10) : width(width), length(length), grid(width, std::vector<Cell>(length)) {};

        std::pair<int, int> getGridSize() const;

        void forEachCell(std::function<void(int, bool)> callback) const;
    private:
        int width;
        int length;
        std::vector<std::vector<Cell>> grid;
};