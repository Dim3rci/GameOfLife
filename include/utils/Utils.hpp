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
    MainMode,           ///< Main menu mode
    ManualOption,       ///< Manual configuration option
    DefaultModeOption   ///< Default mode selection
};

/**
 * @enum Mode
 * @brief Represents the available game modes.
 */
enum Mode {
    ManualMode = 1, ///< Manual mode
    RandomMode = 2  ///< Random mode
};

/**
 * @enum ManualOptions
 * @brief Represents the manual configuration options.
 */
enum ManualOptions {
    TerminalMode = 1, ///< Terminal mode
    GraphicMode = 2   ///< Graphic mode
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

        /**
         * @brief Reads an integer from user input within a specified range.
         * @param prompt The prompt to display to the user.
         * @param min The minimum acceptable value.
         * @param max The maximum acceptable value.
         * @return The integer entered by the user.
         */
        int readInt(const std::string& prompt, int min, int max);
};