#include <iostream>
#include <limits>
#include <fstream>

#include "core/GameLoop.hpp"
#include "utils/Utils.hpp"
#include "ui/GameManager.hpp"
#include "ui/Display.hpp"

/**
 * @brief Launches the main game loop with the given board.
 * @param board The board to use for the game loop.
 */
void GameManager::launchLoop(Board& board) {
    GameLoop gameLoop(board, GameRules(), Display());
    gameLoop.loop();
}

/**
 * @brief Displays the list of available patterns to the user.
 */
void GameManager::displayAvailablePatterns() {
    const char* patternNames[] = {
        "Glider", "Gosper Glider Gun", "Blinker", "Boat", "Beacon",
        "Pulsar", "Lightweight Spaceship", "Loaf", "Toad"
    };
    std::cout << "Choose a pattern:\n";
    for (int i = 0; i < 9; ++i) {
        std::cout << (i + 1) << ". " << patternNames[i] << "\n";
    }
    std::cout << "0. Exit\n";
}

/**
 * @brief Handles pattern selection and launches the game loop with the chosen pattern.
 */
void GameManager::choosePattern() {
    const char* patternFiles[] = {
        "pattern/glider",
        "pattern/gosper_gun",
        "pattern/blinker",
        "pattern/boat",
        "pattern/beacon",
        "pattern/pulsar",
        "pattern/light_spaceship",
        "pattern/loaf",
        "pattern/toad"
    };
    displayAvailablePatterns();
    int patternChoice = this->utils.readInt("Enter your choice (0-9): ", 0, 9);

    if (patternChoice == 0) {
        std::cout << "Exiting pattern selection.\n";
        return;
    }
    std::string filename = patternFiles[patternChoice - 1];
    fromFileMode(filename);
}

/**
 * @brief Displays a menu based on the option and gets the user's choice.
 * @param option The menu option to display.
 * @return The user's selected mode.
 */
int GameManager::getMode(int option) {
    const char* menuMessages[] = {
        "1. Manual Mode\n2. Random Mode\n0. Exit\n",
        "1. Terminal Mode\n2. Graphic Mode\n0. Exit\n",
        "Default mode selected.\nHow do you want to select the alive cells?\n1. Manually\n2. Choose a predefined pattern\n0. Exit\n"
    };
    if (option >= 0 && option <= 2) {
        std::cout << menuMessages[option];
    } else {
        std::cout << "Invalid option.\n";
    }
    return this->utils.readInt("Enter your choice: ", 0, 2);
}

void GameManager::fromFileMode(std::string& filename) {
    auto [width, length] = Utils::getFileDimensions(filename);
    Board board(width, length);
    board.fillFromFile(filename);
    Display display;
    display.render(board);
    launchLoop(board);
}

/**
 * @brief Handles manual mode selection and logic.
 */
void GameManager::manualMode() {
    int displayMode = getMode(MenuOption::ManualOption);
    if (displayMode == ManualOptions::TerminalMode) {
        handleTerminalMode();
    } else if (displayMode == ManualOptions::GraphicMode) {
        handleGraphicMode();
    }
}

void GameManager::handleTerminalMode() {
    int mOptions = getMode(MenuOption::DefaultModeOption);
    if (mOptions == 2) {
        std::cout << "You chose to select a predefined pattern.\n";
        choosePattern();
        return;
    }
    std::string filename = handleFileSelection();
    if (!filename.empty()) {
        fromFileMode(filename);
    }
}

void GameManager::handleGraphicMode() {
    // Add logic for graphic mode
}

std::string GameManager::handleFileSelection() {
    std::string filename;
    while (true) {
        std::cout << "Enter the filename for your pattern (or 'q' to exit): ";
        std::getline(std::cin >> std::ws, filename);
        if (filename == "q") {
            std::cout << "Exiting file selection.\n";
            return "";
        }
        std::ifstream file(filename);
        if (file.good()) {
            file.close();
            break;
        } else {
            std::cout << "File does not exist. Please try again.\n";
        }
    }
    return filename;
}

/**
 * @brief Handles random mode selection and launches the game loop with a random board.
 */
void GameManager::randomMode() {
    int height = this->utils.readInt("Enter board height (positive integer): ", 0, 100);
    int length = this->utils.readInt("Enter board length (positive integer): ", 0, 100);
    constexpr double aliveProbability = 0.3;
    Board board(height, length);

    board.fillRandomly(aliveProbability);
    launchLoop(board);
}

/**
 * @brief Runs the main menu and starts the selected game mode.
 */
void GameManager::run() {
    int mainMode = getMode(MenuOption::MainMode);
    if (mainMode == Mode::ManualMode) {
        manualMode();
    } else if (mainMode == Mode::RandomMode) {
        randomMode();
    }
}