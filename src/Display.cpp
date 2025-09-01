#include <iostream>

#include "Display.hpp"

/**
 * @brief Renders the current state of the board to the standard output.
 *
 * This function iterates over each cell of the board and prints a character
 * representing whether the cell is alive or dead. It uses the `alive` and `dead`
 * characters defined in the `Display` class.
 *
 * A newline is printed after the last cell in each row to maintain a grid layout.
 *
 * @param board The board to be rendered.
 *
 * @note This function relies on `Board::forEachCell` to access cell states.
 *       Only the y-coordinate is passed to the lambda, assuming a row-wise traversal.
 *
 * @warning This implementation assumes that the board is traversed in row-major order.
 *          If `forEachCell` is modified to change the traversal pattern,
 *          this rendering logic may break the grid formatting.
 */
void Display::render(Board& board) {
    board.forEachCell([this, &board](int y, bool isAlive) {
        std::cout << (isAlive ? this->alive : this->dead);
        if (y == board.getGridSize().second - 1) {
            std::cout << std::endl;
        }
    });
}