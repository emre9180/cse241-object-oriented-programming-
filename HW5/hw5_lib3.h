/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#ifndef HW5_LIB3_H
#define HW5_LIB3_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread> /* To pause while printing the games */
#include <chrono> /* To pause while printing the games */
#include "hw5_lib.h"

using namespace std;

namespace GTU
{
    class EightPuzzle : public BoardGame2D
    {
        public:
            fstream *file;
            virtual void playAuto();
            virtual void initiliaze();
            virtual void print() const;
            virtual bool endGame() const;
            virtual int boardScore() const;
            virtual void playUser(string input);
            virtual void information() const; /* Prints the information about the related game */

            EightPuzzle();
            vector<vector<int>> init(); /* Initiliazes the board */
            vector<vector<int>> getBoard() const; /* Getter function for board */
            void setBoard(int x, int y, int newNumber); /* Setter Function for board */
            void makeMove(int xChoice, int yChoice, string directionChoice); /* This function makes move. Updates the board according to valid move */
            bool moveValid(int xChoice, int yChoice, string directionChoice) const; /* This function checks that the move is valid or not; if the move is valid, returns true */
            string getRandomMove() const; /* Makes randomly direction selection*/
            void shuffle(); /* Shuffles the board */
            

        private:
            vector<vector<int>> board;

    };
}



#endif
