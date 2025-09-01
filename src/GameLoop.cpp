#include "GameLoop.hpp"

std::vector<std::vector<bool>> GameLoop::fillNewGeneration(std::vector<std::vector<bool>>& nextEstate) const {
    std::pair<int, int> size = board.getGridSize();

    for (int x = 0; x < size.first; ++x) {
        for (int y = 0; y < size.second; ++y) {
            bool isCurrentlyAlive = board.isCellAlive(x, y);
            int aliveNeighbors = board.countAliveNeighbors(x, y);
            nextEstate[x][y] = rules.shouldCellLive(isCurrentlyAlive, aliveNeighbors);
        }
    }
    return nextEstate;
}

void GameLoop::nextGeneration() {
    std::vector<std::vector<bool>> nextState(board.getGridSize().first, std::vector<bool>(board.getGridSize().second, false));
    
    // Update the board with the next generation state
    board.updateBoard(fillNewGeneration(nextState));
}