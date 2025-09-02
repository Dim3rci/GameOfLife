#include "GameManager.hpp"
#include <iostream>
#include <limits>
#include "Utils.hpp"
#include "Display.hpp"
#include "GameLoop.hpp"

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
    int patternChoice = -1;
    while (!(std::cin >> patternChoice) || patternChoice < 0 || patternChoice > 9) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number between 0 and 9.\n";
    }
    if (patternChoice == 0) {
        std::cout << "Exiting pattern selection.\n";
        return;
    }
    std::string filename = patternFiles[patternChoice - 1];
    auto [width, length] = Utils::getFileDimensions(filename);
    Board board(width, length);
    board.fillFromFile(filename);
    Display display;
    display.render(board);
    launchLoop(board);
}

/**
 * @brief Displays a menu based on the option and gets the user's choice.
 * @param option The menu option to display.
 * @return The user's selected mode.
 */
int GameManager::getMode(int option) {
    const char* menuMessages[] = {
        "1. Manual Mode\n2. Random Mode\n0. Exit\n",
        "1. Default option\n2. Custom option\n0. Exit\n",
        "Default mode selected.\nHow do you want to select the alive cells?\n1. Manually\n2. Choose a predefined pattern\n0. Exit\n"
    };
    int mode;
    if (option >= 0 && option <= 2) {
        std::cout << menuMessages[option];
    } else {
        std::cout << "Invalid option.\n";
    }
    while (!(std::cin >> mode) || (mode != 0 && mode != 1 && mode != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number.\n";
    }
    return mode;
}

/**
 * @brief Handles manual mode selection and logic.
 */
void GameManager::manualMode() {
    int manualMode = getMode(MenuOption::ManualOption);
    if (manualMode == ManualOptions::DefaultOption) {
        int mOptions = getMode(MenuOption::DefaultModeOption);
        if (mOptions == 2) {
            std::cout << "You chose to select a predefined pattern.\n";
            choosePattern();
        }
        // Add logic for manual cell selection if needed
    } else if (manualMode == ManualOptions::CustomOption) {
        // Add logic for custom mode
    }
}

/**
 * @brief Handles random mode selection and launches the game loop with a random board.
 */
void GameManager::randomMode() {
    Board board;
    board.fillRandomly(0.3);
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