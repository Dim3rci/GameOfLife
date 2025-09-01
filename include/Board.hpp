#pragma once

#include <vector>
#include <functional>

#include "Cell.hpp"

class Board {
    public:
        Board(int width = 10, int length = 10) : width(width), length(length), grid(width, std::vector<Cell>(length)) {};

        std::pair<int, int> getGridSize() const;
        void fillRandomly(float aliveProbability = 0.3);

        bool isCellAlive(int x, int y) const;
        void setCellStatus(int x, int y, bool isAlive);
        void forEachCell(std::function<void(int, bool)> callback) const;
        int countAliveNeighbors(int x, int y) const;
        void updateBoard(const std::vector<std::vector<bool>>& nextState);
    private:
        int width;
        int length;
        std::vector<std::vector<Cell>> grid;
};