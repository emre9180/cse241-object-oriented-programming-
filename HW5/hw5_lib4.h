/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#ifndef HW5_LIB4_H
#define HW5_LIB4_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread> /* To pause while printing the games */
#include <chrono> /* To pause while printing the games */
#include "hw5_lib.h"

namespace GTU
{
    class Klotski : public BoardGame2D
    {
        public:
            fstream *file;
            virtual void playAuto();
            virtual void initiliaze();
            virtual void print() const;
            virtual bool endGame() const;
            virtual int boardScore() const;
            virtual void playUser(string input);
            virtual void information() const;/* Prints the information about the related game */


            Klotski();
            void closefile();
            void makeMove(char selection, string directionChoice); /* This function makes move. Updates the board according to valid move */
            bool moveValid(char selection, string directionChoice) const; /* This function checks that the move is valid or not; if the move is valid, returns true */
            string getRandomMove() const; /* Makes randomly direction selection*/

            vector<vector<char>> getBoard() const;


        private:
            vector<vector<char>> board;
    };
}







#endif
