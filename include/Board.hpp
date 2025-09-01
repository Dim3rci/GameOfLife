#pragma once

#include <vector>
#include <functional>
#include <string>

#include "Cell.hpp"

class Board {
    public:
        Board(int height = 10, int length = 10) : height(height), length(length), grid(height, std::vector<Cell>(length)) {};

        std::pair<int, int> getGridSize() const;
        void fillRandomly(float aliveProbability = 0.3);
        void fillFromFile(const std::string& filename, char alive = 'X', char dead = '.');

        bool isCellAlive(int x, int y) const;
        void setCellStatus(int x, int y, bool isAlive);
        void forEachCell(std::function<void(int, bool)> callback) const;
        int countAliveNeighbors(int x, int y) const;
        void updateBoard(const std::vector<std::vector<bool>>& nextState);
        void resize(int newheight, int newLength);
    private:
        int height;
        int length;
        std::vector<std::vector<Cell>> grid;
};