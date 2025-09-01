#include <iostream>
#include <limits>

// #include "Board.hpp"
#include "Utils.hpp"
#include "Display.hpp"


/**
 * @brief Get the Mode object
 * 
 * @return int 
 */
int getMode() {
    int mode;

    std::cout << "Choose your mode\n";
    std::cout << "1. Choose the size of the board and which cells are alive\n";
    std::cout << "2. Random Mode\n";
    std::cout << "0. Exit\n";

    while (true) {
        if (std::cin >> mode) {
            if (mode == 0 || mode == 1 || mode == 2) {
                return mode;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
        }
    }
}

int main() {
    int mode = getMode();

    if (mode == 1) {
        return Status::SUCCESS;
    } else if (mode == 2) {
        Board board;
        Display test;
        test.render(board);
        
    }
    return Status::SUCCESS;
}