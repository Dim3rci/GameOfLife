#include <fstream>
#include <string>
#include <utility>
#include <iostream>
#include <limits>

#include "utils/Utils.hpp"

/**
 * @brief Get the dimensions of a file representing a grid.
 * 
 * Reads the file and determines the maximum width and the number of lines (height).
 * 
 * @param filename Name of the file to read.
 * @return std::pair<int, int> Pair containing (maxWidth, height).
 */
std::pair<int, int> Utils::getFileDimensions(const std::string& filename) {
     std::ifstream file(filename);
    if (!file.is_open()) {
        return {0, 0};
    }

    int maxWidth = 0;
    int height = 0;
    std::string line;
    while (std::getline(file, line)) {
        if (static_cast<int>(line.size()) > maxWidth) {
            maxWidth = static_cast<int>(line.size());
        }
        ++height;
    }
    return {maxWidth, height};
}

/**
 * @brief Reads an integer from user input within a specified range.
 * 
 * Prompts the user until a valid integer within the range [min, max] is entered.
 * 
 * @param prompt The prompt to display.
 * @param min The minimum acceptable value.
 * @param max The maximum acceptable value.
 * @return The integer entered by the user.
 */
int Utils::readInt(const std::string& prompt, int min, int max) {
    int value;

    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number between " << min << " and " << max << ".\n";
    }
}