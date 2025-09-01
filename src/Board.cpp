#include "Board.hpp"

/**
 * @brief Return dimension of the grid
 * getGridSize.first = width
 * getGridSize.second = length
 * @return std::pair<int, int> 
 */
std::pair<int, int> Board::getGridSize() const {
    return {this->width, this->length};
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
 * @warning The iteration order is from x = 0 to width-1 and y = 0 to length-1.
 */
void Board::forEachCell(std::function<void(int, bool)> callback) const {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < length; ++y) {
            callback(y, grid[x][y].getStatus());
        }
    }
}