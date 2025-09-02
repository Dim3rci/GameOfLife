#include "Utils.hpp"

#include <fstream>
#include <string>
#include <utility>

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
        return {0, 0}; // Ou gérer l'erreur autrement
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