#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h> // For _kbhit() and _getch()

#include "core/GameLoop.hpp"

/**
 * @brief Fill the next generation state for the board.
 * 
 * Determines the status of each cell in the next generation according to the rules.
 * 
 * @param nextEstate 2D vector to be filled with the next generation cell states.
 * @return std::vector<std::vector<bool>> The filled next generation state.
 */
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

/**
 * @brief Advance the board to the next generation.
 * 
 * Computes the next state and updates the board.
 */
void GameLoop::nextGeneration() {
    std::vector<std::vector<bool>> nextState(board.getGridSize().first, std::vector<bool>(board.getGridSize().second, false));
    
    // Update the board with the next generation state
    board.updateBoard(fillNewGeneration(nextState));
}

/**
 * @brief Main loop of the game.
 * 
 * Continuously updates the board, displays it, and waits for a fixed interval.
 * The loop can be exited cleanly by pressing 'q'.
 */
void GameLoop::loop() {
    int generation = 0;

    std::cout << "Starting Game of Life loop. Press 'q' to quit." << std::endl;
    while (1) {
        // Exit loop if user presses 'q'
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 'q' || ch == 'Q') {
                std::cout << "Exiting Game of Life loop." << std::endl;
                break;
            }
        }
        nextGeneration();
        generation++;
        std::cout << "Generation: " << generation << std::endl;
        display.render(board);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
}