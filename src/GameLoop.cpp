#include <iostream>
#include <thread>
#include <chrono>

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

void GameLoop::loop() {
    int generation = 0;

    while (1) {
        nextGeneration();
        generation++;
        std::cout << "Generation: " << generation << std::endl;
        display.render(board);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}