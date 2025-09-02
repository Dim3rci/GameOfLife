#pragma once

#include "core/Board.hpp"
#include "utils/Utils.hpp"

/**
 * @brief Manages the main game logic and user interaction.
 */
class GameManager {

    public:
        GameManager(Utils utils) : utils(std::move(utils)) {}
        /**
         * @brief Runs the main menu and starts the selected game mode.
         */
        void run();
        
        
    private:
        Utils utils;
        /**
         * @brief Launches the main game loop with the given board.
         * @param board The board to use for the game loop.
         */
        void launchLoop(Board& board);

        /**
         * @brief Displays the list of available patterns to the user.
         */
        void displayAvailablePatterns();

        /**
         * @brief Handles pattern selection and launches the game loop with the chosen pattern.
         */
        void choosePattern();

        /**
         * @brief Displays a menu based on the option and gets the user's choice.
         * @param option The menu option to display.
         * @return The user's selected mode.
         */
        int getMode(int option);

        void fromFileMode(std::string& filename);

        /**
         * @brief Handles manual mode selection and logic.
         */
        void manualMode();
        void handleTerminalMode();
        void handleGraphicMode();
        std::string handleFileSelection();
        /**
         * @brief Handles random mode selection and launches the game loop with a random board.
         */
        void randomMode();
};