
# Useful information

This is a console guessing game that I've started writing mainly because I want to make sure that I understand the core programming concepts.
It consists of 3 main components:
- Main menu
- Main game
- Rules section

## How to get the source code

To run the program, first you need to get the contents of the repository. In order to do that, make sure that you have Git installed by writing 
> `git --version`

After you did that, you need to navigate to a directory in which you want to clone the repository
>`cd PATH`
>>Example:
>>* On **Windows** it can either contain backslashes: `cd C:\Users\YOUR_USERNAME`
>>
>>* or regular slashes: `cd C:/Users/YOUR_USERNAME`
>
>>On **macOS** or **Linux** the paths can only have forward slashes:
>>
>>`cd  /YOUR_USERNAME/Desktop`

Clone the repository
>`git clone https://github.com/Alexdragon737/guessingGame`
>
>`cd guessingGame`

Make sure that the code is up to date with the commits from the remote repo
>`git pull`

Use a code editor of your choice(VSCode or Visual Studio Community are my personal choices) to open and edit the source if you feel like modifying some of it in order to make the code look cleaner or such.

### When using VSCode: 
1. Open the cloned repo in VSCode by using the menu bar: **File->Open Folder**
2. Either compile the code separately by using **CTRL+Shift+B**, press **F5** to run the code with debugging, or **CTRL+F5** to run without debugging.
3. Choose the compiler you want to use. I recommend using **g++** but you can use any other compiler as long as it works.
4. At first the code probably won't compile because the linker can't find the other cpp file. You can fix this by changing a piece of code in the **settings.json** file. At first, instead of `*.cpp`, there will be something else. Also, when running on Linux, remove the `.exe` from 
>When compiling on **Windows**, **args** need to contain this:
>```
>"args": [
>            "-fdiagnostics-color=always",
>            "-g",
>           "*.cpp", 
>            "-o",
>           "${fileDirname}/${fileBasenameNoExtension}.exe"
>        ],
>```
>When compiling on **Linux**:
>```
>"args": [
>            "-fdiagnostics-color=always",
>            "-g",
>           "*.cpp", 
>            "-o",
>           "${fileDirname}/${fileBasenameNoExtension}"
>        ],
>```
5. The code needs to compile succesfully after changing this. If you want it to be run in an external terminal and not the tiny, integrated one, you need to open **launch.json**, find the `externalConsole` key and set its value to `true`.


## Core components of the game

### Main menu

The end-user is greeted by a welcome message, and is prompted to introduce a numerical value between 1 and 3, in order to choose from the following options, in this exact order:
1. Start the game
2. See the rules
3. Quit the application


### Rules section

The end-user is greeted by a message in which the "rules" of the game are explained.


### Main game

The end-user is prompted to input a numerical value, representing the difficulty, from 1 to 4. The difficulty level are as they follow:
1. Baby level - the end-user needs to guess a pseudo-generated number ranging from **1** to **10**
2. Intermediate - the end-user needs to guess a pseudo-generated number ranging from **1** to **100**
3. Advanced - the end-user needs to guess a pseudo-generated number ranging from **1** to **1000**
4. Nostradamus or some shit - the end-user needs to guess a pseudo-generated number ranging from **0** to **RAND_MAX**. As per C++ documentation, the RAND_MAX value is library dependent, but with the most basic implementation it should be at least **32767**. In this case I made the rand() function to generate values up to the numeric limit of **unsigned int**, more exactly to 4294967295.

The game also features a hardcore mode, which integrates a lives system. The lives are calculated as an arithmetic progression with **a<sub>1</sub> = 10** and the general term **a<sub>n</sub> = 10-3\*(diff-1)**, so the initial lives for each difficulty would be:
1. Baby level - **10** lives
2. Intermediate - **7** lives
3. Advanced - **4** lives
4. Nostradamus or some shit - **1** life

### Quitting the application

As of now, the "Quit the application" option is just the shortest way to the actual end of the program, but maybe I'll try to implement a dedicated function to completely kill the program in the future.
