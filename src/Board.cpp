#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

#include "Board.hpp"

/**
 * @brief Return dimension of the grid
 * getGridSize.first = height
 * getGridSize.second = length
 * @return std::pair<int, int> 
 */
std::pair<int, int> Board::getGridSize() const {
    return {this->height, this->length};
}

/**
 * @brief Applies a callback function to every cell in the board.
 *
 * This function iterates over all cells in the board and calls the given
 * callback with the coordinates and the alive/dead status of each cell.
 *
 * @param callback A function that takes two parameters:
 *        - int y: The y-coordinate of the cell.
 *        - bool isAlive: The status of the cell (true if alive, false if dead).
 *
 * @note The x-coordinate is not passed to the callback. If you need both
 *       x and y coordinates, consider modifying the callback signature.
 *
 * @warning The iteration order is from x = 0 to height-1 and y = 0 to length-1.
 */
void Board::forEachCell(std::function<void(int, bool)> callback) const {
    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < length; ++y) {
            callback(y, grid[x][y].getStatus());
        }
    }
}

void Board::fillRandomly(float aliveProbability) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int x = 0; x < height; ++x) {
        for (int y = 0; y < length; ++y) {
            float randValue = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
            grid[x][y].setStatus(randValue < aliveProbability);
        }
    }
}

void Board::fillFromFile(const std::string& filename, char alive, char dead) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::string line;
    int x = 0;
    
    std::cout << "Length : " << length << " height : " << height << std::endl;
    while (std::getline(file, line) && x < height) {
        for (int y = 0; y < static_cast<int>(line.size()) && y < length; ++y) {
            if (line[y] == alive) {
                grid[x][y].setStatus(true);
            } else if (line[y] == dead) {
                grid[x][y].setStatus(false);
            }
        }
        ++x;
    }
}

int Board::countAliveNeighbors(int x, int y) const {
    int aliveCount = 0;

    for (int deltaX = -1; deltaX <= 1; ++deltaX) {
        for (int deltaY = -1; deltaY <= 1; ++deltaY) {
            if (deltaX == 0 && deltaY == 0) continue; // Skip the cell itself
            int neighborX = x + deltaX;
            int neighborY = y + deltaY;
            if (neighborX >= 0 && neighborX < height && neighborY >= 0 && neighborY < length) {
                if (grid[neighborX][neighborY].getStatus()) {
                    ++aliveCount;
                }
            }
        }
    }
    return aliveCount;
}

bool Board::isCellAlive(int x, int y) const {
    if (x >= 0 && x < height && y >= 0 && y < length) {
        return grid[x][y].getStatus();
    }
    return false;
}

void Board::setCellStatus(int x, int y, bool isAlive) {
    if (x >= 0 && x < height && y >= 0 && y < length) {
        grid[x][y].setStatus(isAlive);
    }
}

void Board::updateBoard(const std::vector<std::vector<bool>>& nextState) {
    for (int x = 0; x < this->height; ++x) {
        for (int y = 0; y < this->length; ++y) {
            setCellStatus(x, y, nextState[x][y]);
        }
    }
}

void Board::resize(int newheight, int newLength) {
    height = newheight;
    length = newLength;
    grid = std::vector<std::vector<Cell>>(height, std::vector<Cell>(length));
}