#pragma once

#include <utility>
#include <string>
#include <streambuf>

/**
 * @enum Status
 * @brief Represents the status of an operation.
 */
enum Status {
    SUCCESS, ///< Operation succeeded.
    ERROR    ///< Operation failed.
};

/**
 * @enum MenuOption
 * @brief Represents the available menu options.
 */
enum MenuOption {
    MainMode,
    ManualOption,
    DefaultModeOption
};

/**
 * @enum Mode
 * @brief Represents the available game modes.
 */
enum Mode {
    ManualMode = 1,
    RandomMode = 2
};

/**
 * @enum ManualOptions
 * @brief Represents the manual configuration options.
 */
enum ManualOptions {
    DefaultOption = 1,
    CustomOption = 2
};

/**
 * @class Utils
 * @brief Utility functions for the Game of Life.
 */
class Utils {
    public:
        /**
         * @brief Gets the dimensions of a file.
         * @param filename The name of the file.
         * @return A pair containing the number of rows and columns.
         */
        static std::pair<int, int> getFileDimensions(const std::string& filename);
        int readInt(const std::string& prompt, int min, int max);
};