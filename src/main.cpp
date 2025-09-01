#include <iostream>
#include <limits>

#include "Utils.hpp"
#include "Display.hpp"
#include "GameLoop.hpp"

void launchLoop(Board& board) {
    GameLoop gameLoop(board, GameRules(), Display());
    gameLoop.loop();
}

void displayAvailablePatterns() {
    std::cout << "Choose a pattern:\n"
              << "1. Glider\n"
              << "2. Gosper Glider Gun\n"
              << "3. Blinker\n"
              << "4. Boat\n"
              << "5. Beacon\n"
              << "6. Pulsar\n"
              << "7. Lightweight Spaceship\n"
              << "8. Loaf\n"
              << "9. Toad\n"
              << "0. Exit\n";
}

void choosePattern() {
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

    const std::string patternFiles[] = {
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

    std::string filename = patternFiles[patternChoice - 1];
    auto [width, length] = Utils::getFileDimensions(filename);
    Board board(width, length);
    board.fillFromFile(filename);
    Display display;
    display.render(board);
    launchLoop(board);
}

int getMode(int option) {
    int mode;
    switch(option) {
        case MenuOption::MainMode:
            std::cout << "1. Manual Mode\n2. Random Mode\n0. Exit\n";
            break;
        case MenuOption::ManualOption:
            std::cout << "1. Default option\n2. Custom option\n0. Exit\n";
            break;
        case MenuOption::DefaultModeOption:
            std::cout << "Default mode selected.\nHow do you want to select the alive cells?\n1. Manually\n2. Choose a predefined pattern\n0. Exit\n";
            break;
        default:
            std::cout << "Invalid option.\n";
            break;
    }
    while (!(std::cin >> mode) || (mode != 0 && mode != 1 && mode != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input! Please enter a number.\n";
    }
    return mode;
}

void manualMode() {
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

void randomMode() {
    Board board;
    board.fillRandomly(0.3);
    launchLoop(board);
}

int main() {
    int mainMode = getMode(MenuOption::MainMode);
    if (mainMode == Mode::ManualMode) {
        manualMode();
    } else if (mainMode == Mode::RandomMode) {
        randomMode();
    }
    return Status::SUCCESS;
}
