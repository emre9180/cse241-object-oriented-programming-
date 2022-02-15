/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#ifndef HW5_LIB2_H
#define HW5_LIB2_H

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
    enum class cellType {none, empty, peg}; /* For PegSoliataire */

    class PegSolitaire : public BoardGame2D
    {
        public:
            class Cell
            {
                public:
                    Cell(int _row, char _column, cellType _cell);
                    Cell();
                    void setRow(int row);
                    void setColumn(char column);
                    void setCell(cellType _cell);
                    inline int getRow() const{return row;};
                    inline char getColumn() const {return column;};
                    inline cellType getCell() const {return cell;};

                private:
                    int row;
                    char column;
                    cellType cell;
        };

        PegSolitaire();
        
        inline vector <vector<Cell>> getBoard() const{return board;};
        void setIsTypeSix(bool newB);
        void setBoard(int x, int y, cellType cell);
        
        virtual void playAuto();
        virtual void initiliaze();
        virtual void print() const;
        virtual void playUser(string input);
        virtual bool endGame() const;
        virtual int boardScore() const;
        virtual void information() const; /* Prints the information about the related game */
        bool moveValid(int xChoice, int yChoice, string directionChoice) const; /* This function checks that the move is valid or not; if the move is valid, returns true */
        void makeMove(int xChoice, int yChoice, string directionChoice); /* This function makes move. Updates the board according to valid move */
        string getRandomMove() const; /* Makes randomly direction selection for board 2*/
        vector <vector<Cell>> initGameTypeTwo(); /* Initiliaze the game as the 'second' table that is showed in PDF */

        fstream *file;

        private:
            vector <vector<Cell>> board;
            
    };
}


#endif
