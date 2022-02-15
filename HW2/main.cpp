/* EMRE YILMAZ - 1901042606 - Gebze Technical University */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "lib.h"

using namespace std;

int main()
{
    vector <vector<Cell>> board; /* Board vector */

    int boardType; /* User's board type selection */
    int gameType; /* Indicates that game is human-game or computer-game */
    bool isTypeSix = false;

    srand(time(NULL));

    cout << "Please select board type from 1 to 6: "; 
    cin >> boardType; /* Getting board type input */
    if(boardType<1 || boardType>6)
        {
            cerr << "You have entered an invalid number. Please enter again!\n\n";
            main();
            return 1;
        }

    switch(boardType) /* Initiliaze the board according to user's board type selection */
    {
        case 1:
            board = initGameTypeOne();
            print(board);
            break;

        case 2:
            board = initGameTypeTwo();
            print(board);
            break;

        case 3:
            board = initGameTypeThree();
            print(board);
            break;

        case 4:
            board = initGameTypeFour();
            print(board);
            break;

        case 5:
            board = initGameTypeFive();
            print(board);
            break;

        case 6:
            board = initGameTypeSix();
            isTypeSix = true;
            print(board);
            break;          
    }

    cout << "Please select the game type\n1: Human game\n2: Computer game\n\nYour selection: ";
    cin >> gameType;

    switch (gameType) /* Starts the game according to board type */
    {
    case 1:
        humanGame(board,isTypeSix);
        break;
    
    case 2:
        computerGame(board, isTypeSix);
        break;

    default:
        cerr << "You have entered invalid number! Please make your choices again!\n\n";
        main();
        return 1;
    }

    return 1;
}

