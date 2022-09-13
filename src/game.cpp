#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include "..\include\game.h"


using namespace std;

void mainMenu()
{
    ifstream content("..\\assets\\game_mainMenuContent.txt");
    string buff;
    int choice;
    outputTextFileContent(content, buff);
    
    // Check if choice is valid.
    try
    {
        cin >> choice;
        switch(choice)
        {
            case 1:
                actualGame();
                break;
            case 2:
                aboutGame();
                break;
            case 3:
                cout << "See you next time!\n";
            default:
                if(choice < 1 || choice > 3)
                    throw choice;
        }
    }
    catch(int& x)
    {
        cout << "Invalid input, the choice " << x << " does not exist. Please try again. \n";
        mainMenu();
    }
}

void aboutGame()
{
    ifstream content("..\\assets\\game_AboutContent.txt");
    string buff, returnChoice;

    outputTextFileContent(content,buff);
    cout << "Do you want to return to the menu? \n";
    while(returnChoice != "yes" && returnChoice != "y")
        cin >> returnChoice;
    if(returnChoice == "yes" || returnChoice == "y")
        mainMenu(); 
}

void actualGame()
{
    // Variable declaration
    int diff = diffSelect(), guessedNumber = 0;
    string gameMode = modeSelect(), playAgainChoice;
    const unsigned int uintLim = 4294967295;
    unsigned short int lives;
    unsigned long int randomNumber;

    // To generate random values we need to first generate a seed.
    srand(time(NULL));

    // Check the range of the difficulty for calculations
    if(diff >= 1 && diff < 4)
        randomNumber = rand() % (int)pow(10,diff)+1;
    else randomNumber = rand() % uintLim;

    // Check the gamemode and give the proper ruleset.

    //Hardcore ruleset
    if(gameMode == "hardcore")
    {
        lives = 10-3*(diff-1);
        cout << "Initial lives: " << lives << "\n";
        while(lives != 0)
        {
            cin >> guessedNumber;
            if(guessedNumber == randomNumber)
                cout << "Congratulations, the number you had to guess was " << guessedNumber << "\n";
            else
            {
                lives--;
                if(lives != 0)
                {
                    cout << "Wrong guess, please try again." << "\n";
					cout << "Current lives: " << lives << "\n";
                }
                else
                {
                    cout << "Out of lives, you lost!" << "\n";
					cout << "The number you had to guess was " << randomNumber << "\n";
                }
            }
        }
    }
    // Casual ruleset
    else 
    {
        cout << "Lives: Unlimited \n";
        while(guessedNumber != randomNumber)
        {
            cin >> guessedNumber;
            if(guessedNumber == randomNumber)
                cout << "Congratulations, the number you had to guess was " << guessedNumber << "\n";
            else cout << "Wrong guess, please try again. \n";
        }
    }

    // Check if the user wants to play again.
    cout << "Do you want to play again? Input one of the valid options below: \n";
    cout << "Affirmative: yes, y \n";
    cout << "Negative: no, n \n";
    cin  >> playAgainChoice;
    if(playAgainChoice == "yes" || playAgainChoice == "y")
        mainMenu();
    else if(playAgainChoice == "no" || playAgainChoice == "n")
        cout << "Thank you for playing. See you next time! \n"; 
}

int diffSelect()
{
    // Take diff as a number in [1,4] range
    int diff;
    cout << "Please input a difficulty number from 1 to 4 \n";

    // Check to see if number is in range
    while(diff < 1 || diff > 4)
    {
        cin >> diff;
        if(diff < 1 || diff > 4)
            cout << "Invalid value, please try again. \n";
    }
    return diff;
}

string modeSelect()
{
    // Take number as string. Valid choices: {"casual", "hardcore"}.
    string choice;
    cout << "Do you want to have unlimited tries?\nIf you're up for a challenge, then write \"hardcore\", otherwise write \"casual\"." << endl;
    while(choice != "hardcore" && choice != "casual")
    {
        cin >> choice;
        if(choice != "hardcore" && choice != "casual")
            cout << "Invalid choice, please try again.";
    }
    return choice;
}

void outputTextFileContent(std::ifstream& file, std::string& buff)
{
    // Check if file is open
    if(file.is_open())
    {
        // Output contents of file using buff.
        while(getline(file,buff))
            std::cout << buff << "\n";
    }

    // Close file after output.
    file.close();
}