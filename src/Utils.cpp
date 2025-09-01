#include "Utils.hpp"

#include <fstream>
#include <string>
#include <utility>

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