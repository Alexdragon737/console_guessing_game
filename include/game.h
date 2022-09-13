#include <iostream>
#include <fstream>
#include <string>

/*
    Usually we don't need to use `#pragma once` and the oldschool guards
    at the same time but I did this to avoid problems with older compilers.
*/
#pragma once
#ifndef GAME_H
#define GAME_H

/**
 * @brief Main menu of the game. 
 * 
 * 
 */
void mainMenu();


/**
 * @brief The `about` section of the game. It can be recognized as the 2nd choice in main menu.
 * 
 * 
 */
void aboutGame();

/**
 * @brief Handles the difficulty selection.
 * 
 * @return int - The selected difficulty.
 */
int diffSelect();

/**
 * @brief Handles the game mode selection.
 * 
 * @return string - The selected game mode.
 */
std::string modeSelect();

/**
 * @brief Handles the game after taking the value of `diffSelect` and `modeSelect`
 * 
 */
void actualGame();

/**
 * @brief Outputs the content of a text file.
 * 
 * @param file The text file from which we output the text.
 * @param text The buffer we use to output the text.
 */
void outputTextFileContent(std::ifstream& file, std::string& text);


#endif