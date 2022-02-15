/* Emre Yilmaz - Gebze Technical University - 1901042606 -*/
/* NOTE FOR T.A. -> The rest of pegs in a finished game is subtracted from total pegs */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "lib.h"

using namespace std;

/* Cell Class functions */

PegSolitaire::Cell::Cell(int _row, char _column, cellType _cell): row(_row), column(_column), cell(_cell)
{}
PegSolitaire::Cell::Cell()
{}

void PegSolitaire::Cell::setCell(cellType newCell)
{
    cell = newCell;
}
void PegSolitaire::Cell::setRow(int newRow)
{
    row = newRow;
}
void PegSolitaire::Cell::setColumn(char newColumn)
{
    column = newColumn;
}


/* PEG SOLİTARE Class functions */

PegSolitaire::PegSolitaire(){ /* Asks for input and initiliazes the board */
    int boardType;
    cout << "\nPlease select the board type (1-6): ";
    cin >> boardType;

    switch(boardType)
    {
        case 1:
            board = initGameTypeOne();
            break;
        case 2:
            board = initGameTypeTwo();
            break;
        case 3:
            board = initGameTypeThree();
            break;
        case 4:
            board = initGameTypeFour();
            break;
        case 5:
            board = initGameTypeFive();
            break;
        case 6:
            board = initGameTypeSix();
            break;
    }

    playGame(boardType);
}

PegSolitaire::PegSolitaire(int boardType){ /* Initiliaze the board according to input */
    switch(boardType)
    {
        case 1:
            board = initGameTypeOne();
            break;
        case 2:
            board = initGameTypeTwo();
            break;
        case 3:
            board = initGameTypeThree();
            break;
        case 4:
            board = initGameTypeFour();
            break;
        case 5:
            board = initGameTypeFive();
            break;
        case 6:
            board = initGameTypeSix();
            break;
    }
    setTotalPegNumber(getNumberOfPegs());
}

PegSolitaire::PegSolitaire(string nameFile) /* Initiliaze the board loading from text */
{
    board = load(nameFile);
}



int PegSolitaire::getNumberOfPegs() const
{
    int num = 0;
    int numberOfRows = board.size();
    int numberOfColumns = board.at(0).size();

    for(int i=0;i<numberOfRows;i++)
    {
        for(int k=0;k<numberOfColumns;k++)
        {
            if(board.at(i).at(k).getCell()==cellType::peg)
                ++num;
        }
    }
    return num;
}

int PegSolitaire::getNumberOfEmpties() const
{
    int num = 0;
    int numberOfRows = getBoard().size();
    int numberOfColumns = getBoard().at(0).size();

    for(int i=0;i<numberOfRows;i++)
    {
        for(int k=0;k<numberOfColumns;k++)
        {
            if(getBoard().at(i).at(k).getCell()==cellType::empty)
                ++num;
        }
    }
    return num;
}

string PegSolitaire::getRandomMove() const/* Makes randomly direction selection for board 6*/
{
    string directionChoice;

    if(isTypeSix)
    {
        int directionRandom = rand() % 6;
        switch(directionRandom)
        {
            case 0:
                directionChoice = "R";
                break;
            case 1:
                directionChoice = "L";
                break;
            case 2:
                directionChoice = "UR";
                break;
            case 3:
                directionChoice = "UL";
                break;
            case 4:
                directionChoice = "DR";
                break;
            case 5:
                directionChoice = "DL";
                break;
        }
    }

    else
    {
        int directionRandom = rand() % 4;
        switch(directionRandom)
        {
            case 0:
                directionChoice = "R";
                break;
            case 1:
                directionChoice = "L";
                break;
            case 2:
                directionChoice = "U";
                break;
            case 3:
                directionChoice = "D";
                break;
        }
    }
    

    return directionChoice;
}




void PegSolitaire::setIsTypeSix(bool newB)
{
    isTypeSix = newB;
}

void PegSolitaire::setBoard(int x, int y, cellType newCell)
{
    board[x][y].setCell(newCell);
}



vector <vector<PegSolitaire::Cell>> PegSolitaire::initGameTypeFour() /* Initiliaze the game as the 'fourth' table that is showed in PDF */
{
    vector <vector<PegSolitaire::Cell>> Board = {
            {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::peg),PegSolitaire::Cell(1,'D',cellType::peg),PegSolitaire::Cell(1,'E',cellType::peg),PegSolitaire::Cell(1,'F',cellType::none),PegSolitaire::Cell(1,'G',cellType::none)}, 
            {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::none), PegSolitaire::Cell(2,'C',cellType::peg),PegSolitaire::Cell(2,'D',cellType::peg),PegSolitaire::Cell(2,'E',cellType::peg),PegSolitaire::Cell(2,'F',cellType::none),PegSolitaire::Cell(2,'G',cellType::none)}, 
            {PegSolitaire::Cell(3,'A',cellType::peg), PegSolitaire::Cell(3,'B',cellType::peg), PegSolitaire::Cell(3,'C',cellType::peg),PegSolitaire::Cell(3,'D',cellType::peg),PegSolitaire::Cell(3,'E',cellType::peg),PegSolitaire::Cell(3,'F',cellType::peg),PegSolitaire::Cell(3,'G',cellType::peg)}, 
            {PegSolitaire::Cell(4,'A',cellType::peg), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::peg),PegSolitaire::Cell(4,'D',cellType::empty),PegSolitaire::Cell(4,'E',cellType::peg),PegSolitaire::Cell(4,'F',cellType::peg),PegSolitaire::Cell(4,'G',cellType::peg)},
            {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::peg), PegSolitaire::Cell(5,'C',cellType::peg),PegSolitaire::Cell(5,'D',cellType::peg),PegSolitaire::Cell(5,'E',cellType::peg),PegSolitaire::Cell(5,'F',cellType::peg),PegSolitaire::Cell(5,'G',cellType::peg)}, 
            {PegSolitaire::Cell(6,'A',cellType::none), PegSolitaire::Cell(6,'B',cellType::none), PegSolitaire::Cell(6,'C',cellType::peg),PegSolitaire::Cell(6,'D',cellType::peg),PegSolitaire::Cell(6,'E',cellType::peg),PegSolitaire::Cell(6,'F',cellType::none),PegSolitaire::Cell(6,'G',cellType::none)}, 
            {PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'B',cellType::none), PegSolitaire::Cell(7,'C',cellType::peg),PegSolitaire::Cell(7,'D',cellType::peg),PegSolitaire::Cell(7,'E',cellType::peg),PegSolitaire::Cell(7,'F',cellType::none),PegSolitaire::Cell(7,'G',cellType::none)}
            };

    isTypeSix = false;  
   return Board;
}

vector <vector<PegSolitaire::Cell>>  PegSolitaire::initGameTypeTwo() /* Initiliaze the game as the 'second' table that is showed in PDF */
{
    vector <vector<PegSolitaire::Cell>> Board = {
            {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::none), PegSolitaire::Cell(1,'D',cellType::peg),PegSolitaire::Cell(1,'E',cellType::peg),PegSolitaire::Cell(1,'F',cellType::peg),PegSolitaire::Cell(1,'G',cellType::none),PegSolitaire::Cell(1,'H',cellType::none), PegSolitaire::Cell(1,'I',cellType::none)}, 
            {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::none), PegSolitaire::Cell(2,'C',cellType::none), PegSolitaire::Cell(2,'D',cellType::peg),PegSolitaire::Cell(2,'E',cellType::peg),PegSolitaire::Cell(2,'F',cellType::peg),PegSolitaire::Cell(2,'G',cellType::none),PegSolitaire::Cell(2,'H',cellType::none), PegSolitaire::Cell(2,'I',cellType::none)}, 
            {PegSolitaire::Cell(3,'A',cellType::none), PegSolitaire::Cell(3,'B',cellType::none), PegSolitaire::Cell(3,'C',cellType::none), PegSolitaire::Cell(3,'D',cellType::peg),PegSolitaire::Cell(3,'E',cellType::peg),PegSolitaire::Cell(3,'F',cellType::peg),PegSolitaire::Cell(3,'G',cellType::none),PegSolitaire::Cell(3,'H',cellType::none), PegSolitaire::Cell(3,'I',cellType::none)},
            {PegSolitaire::Cell(4,'A',cellType::peg), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::peg),PegSolitaire::Cell(4,'D',cellType::peg),PegSolitaire::Cell(4,'E',cellType::peg),PegSolitaire::Cell(4,'F',cellType::peg),PegSolitaire::Cell(4,'G',cellType::peg), PegSolitaire::Cell(4,'H',cellType::peg), PegSolitaire::Cell(4,'I',cellType::peg)}, 
            {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::peg), PegSolitaire::Cell(5,'C',cellType::peg),PegSolitaire::Cell(5,'D',cellType::peg),PegSolitaire::Cell(5,'E',cellType::empty),PegSolitaire::Cell(5,'F',cellType::peg),PegSolitaire::Cell(5,'G',cellType::peg), PegSolitaire::Cell(5,'H',cellType::peg), PegSolitaire::Cell(5,'I',cellType::peg)}, 
            {PegSolitaire::Cell(6,'A',cellType::peg), PegSolitaire::Cell(6,'B',cellType::peg), PegSolitaire::Cell(6,'C',cellType::peg),PegSolitaire::Cell(6,'D',cellType::peg),PegSolitaire::Cell(6,'E',cellType::peg),PegSolitaire::Cell(6,'F',cellType::peg),PegSolitaire::Cell(6,'G',cellType::peg), PegSolitaire::Cell(6,'H',cellType::peg), PegSolitaire::Cell(6,'I',cellType::peg)}, 
            {PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'B',cellType::none), PegSolitaire::Cell(7,'C',cellType::none), PegSolitaire::Cell(7,'D',cellType::peg),PegSolitaire::Cell(7,'E',cellType::peg),PegSolitaire::Cell(7,'F',cellType::peg),PegSolitaire::Cell(7,'G',cellType::none),PegSolitaire::Cell(7,'H',cellType::none), PegSolitaire::Cell(7,'I',cellType::none)}, 
            {PegSolitaire::Cell(8,'A',cellType::none), PegSolitaire::Cell(8,'B',cellType::none), PegSolitaire::Cell(8,'C',cellType::none) ,PegSolitaire::Cell(8,'D',cellType::peg),PegSolitaire::Cell(8,'E',cellType::peg),PegSolitaire::Cell(8,'F',cellType::peg),PegSolitaire::Cell(8,'G',cellType::none),PegSolitaire::Cell(8,'H',cellType::none), PegSolitaire::Cell(8,'I',cellType::none)}, 
            {PegSolitaire::Cell(9,'A',cellType::none), PegSolitaire::Cell(9,'B',cellType::none), PegSolitaire::Cell(9,'C',cellType::none), PegSolitaire::Cell(9,'D',cellType::peg),PegSolitaire::Cell(9,'E',cellType::peg),PegSolitaire::Cell(9,'F',cellType::peg),PegSolitaire::Cell(9,'G',cellType::none),PegSolitaire::Cell(9,'H',cellType::none), PegSolitaire::Cell(9,'I',cellType::none)}
            };
    isTypeSix=false;
    return Board;
}

vector <vector<PegSolitaire::Cell>> PegSolitaire::initGameTypeOne() /* Initiliaze the game as the 'first' table that is showed in PDF */
{
    vector <vector<PegSolitaire::Cell>> Board = {
            {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::peg),PegSolitaire::Cell(1,'D',cellType::peg),PegSolitaire::Cell(1,'E',cellType::peg),PegSolitaire::Cell(1,'F',cellType::none),PegSolitaire::Cell(1,'G',cellType::none)}, 
            {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::peg), PegSolitaire::Cell(2,'C',cellType::peg),PegSolitaire::Cell(2,'D',cellType::peg),PegSolitaire::Cell(2,'E',cellType::peg),PegSolitaire::Cell(2,'F',cellType::peg),PegSolitaire::Cell(2,'G',cellType::none)}, 
            {PegSolitaire::Cell(3,'A',cellType::peg), PegSolitaire::Cell(3,'B',cellType::peg), PegSolitaire::Cell(3,'C',cellType::peg),PegSolitaire::Cell(3,'D',cellType::empty),PegSolitaire::Cell(3,'E',cellType::peg),PegSolitaire::Cell(3,'F',cellType::peg),PegSolitaire::Cell(3,'G',cellType::peg)}, 
            {PegSolitaire::Cell(4,'A',cellType::peg), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::peg),PegSolitaire::Cell(4,'D',cellType::peg),PegSolitaire::Cell(4,'E',cellType::peg),PegSolitaire::Cell(4,'F',cellType::peg),PegSolitaire::Cell(4,'G',cellType::peg)}, 
            {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::peg), PegSolitaire::Cell(5,'C',cellType::peg),PegSolitaire::Cell(5,'D',cellType::peg),PegSolitaire::Cell(5,'E',cellType::peg),PegSolitaire::Cell(5,'F',cellType::peg),PegSolitaire::Cell(5,'G',cellType::peg)}, 
            {PegSolitaire::Cell(6,'A',cellType::none), PegSolitaire::Cell(6,'B',cellType::peg), PegSolitaire::Cell(6,'C',cellType::peg),PegSolitaire::Cell(6,'D',cellType::peg),PegSolitaire::Cell(6,'E',cellType::peg),PegSolitaire::Cell(6,'F',cellType::peg),PegSolitaire::Cell(6,'G',cellType::none)}, 
            {PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'B',cellType::none), PegSolitaire::Cell(7,'C',cellType::peg),PegSolitaire::Cell(7,'D',cellType::peg),PegSolitaire::Cell(7,'E',cellType::peg),PegSolitaire::Cell(7,'F',cellType::none),PegSolitaire::Cell(7,'G',cellType::none)}
            };
    isTypeSix = false;
    return Board;
}

vector <vector<PegSolitaire::Cell>> PegSolitaire::initGameTypeThree() /* Initiliaze the game as the 'third' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::peg),PegSolitaire::Cell(1,'D',cellType::peg),PegSolitaire::Cell(1,'E',cellType::peg),PegSolitaire::Cell(1,'F',cellType::none),PegSolitaire::Cell(1,'G',cellType::none), PegSolitaire::Cell(1,'H',cellType::none)}, 
            {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::none), PegSolitaire::Cell(2,'C',cellType::peg),PegSolitaire::Cell(2,'D',cellType::peg),PegSolitaire::Cell(2,'E',cellType::peg),PegSolitaire::Cell(2,'F',cellType::none),PegSolitaire::Cell(2,'G',cellType::none), PegSolitaire::Cell(2,'H',cellType::none)}, 
            {PegSolitaire::Cell(3,'A',cellType::none), PegSolitaire::Cell(3,'B',cellType::none), PegSolitaire::Cell(3,'C',cellType::peg),PegSolitaire::Cell(3,'D',cellType::peg),PegSolitaire::Cell(3,'E',cellType::peg),PegSolitaire::Cell(3,'F',cellType::none),PegSolitaire::Cell(3,'G',cellType::none), PegSolitaire::Cell(3,'H',cellType::none)},
            {PegSolitaire::Cell(4,'A',cellType::peg), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::peg),PegSolitaire::Cell(4,'D',cellType::peg),PegSolitaire::Cell(4,'E',cellType::peg),PegSolitaire::Cell(4,'F',cellType::peg),PegSolitaire::Cell(4,'G',cellType::peg), PegSolitaire::Cell(4,'H',cellType::peg)}, 
            {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::peg), PegSolitaire::Cell(5,'C',cellType::peg),PegSolitaire::Cell(5,'D',cellType::empty),PegSolitaire::Cell(5,'E',cellType::peg),PegSolitaire::Cell(5,'F',cellType::peg),PegSolitaire::Cell(5,'G',cellType::peg), PegSolitaire::Cell(5,'H',cellType::peg)}, 
            {PegSolitaire::Cell(6,'A',cellType::peg), PegSolitaire::Cell(6,'B',cellType::peg), PegSolitaire::Cell(6,'C',cellType::peg),PegSolitaire::Cell(6,'D',cellType::peg),PegSolitaire::Cell(6,'E',cellType::peg),PegSolitaire::Cell(6,'F',cellType::peg),PegSolitaire::Cell(6,'G',cellType::peg), PegSolitaire::Cell(6,'H',cellType::peg)}, 
            {PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'B',cellType::none), PegSolitaire::Cell(7,'C',cellType::peg),PegSolitaire::Cell(7,'D',cellType::peg),PegSolitaire::Cell(7,'E',cellType::peg),PegSolitaire::Cell(7,'F',cellType::none),PegSolitaire::Cell(7,'G',cellType::none), PegSolitaire::Cell(7,'H',cellType::none)}, 
            {PegSolitaire::Cell(8,'A',cellType::none), PegSolitaire::Cell(8,'B',cellType::none), PegSolitaire::Cell(8,'C',cellType::peg),PegSolitaire::Cell(8,'D',cellType::peg),PegSolitaire::Cell(8,'E',cellType::peg),PegSolitaire::Cell(8,'F',cellType::none),PegSolitaire::Cell(8,'G',cellType::none), PegSolitaire::Cell(8,'H',cellType::none)}
            };
    isTypeSix = false;
    return Board;
}

vector <vector<PegSolitaire::Cell>> PegSolitaire::initGameTypeFive() /* Initiliaze the game as the 'fifth' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::none),PegSolitaire::Cell(1,'D',cellType::none), PegSolitaire::Cell(1,'E',cellType::peg), PegSolitaire::Cell(1,'F',cellType::none), PegSolitaire::Cell(1,'G',cellType::none), PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'A',cellType::none)}, 
            {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::none), PegSolitaire::Cell(2,'C',cellType::none),PegSolitaire::Cell(2,'D',cellType::peg), PegSolitaire::Cell(2,'E',cellType::peg), PegSolitaire::Cell(2,'F',cellType::peg), PegSolitaire::Cell(2,'G',cellType::none), PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'A',cellType::none)}, 
            {PegSolitaire::Cell(3,'A',cellType::none), PegSolitaire::Cell(3,'B',cellType::none), PegSolitaire::Cell(3,'C',cellType::peg),PegSolitaire::Cell(3,'D',cellType::peg), PegSolitaire::Cell(3,'E',cellType::peg), PegSolitaire::Cell(3,'F',cellType::peg), PegSolitaire::Cell(3,'G',cellType::peg), PegSolitaire::Cell(3,'A',cellType::none), PegSolitaire::Cell(3,'A',cellType::none)}, 
            {PegSolitaire::Cell(4,'A',cellType::none), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::peg),PegSolitaire::Cell(4,'D',cellType::peg), PegSolitaire::Cell(4,'E',cellType::peg), PegSolitaire::Cell(4,'F',cellType::peg), PegSolitaire::Cell(4,'G',cellType::peg), PegSolitaire::Cell(4,'A',cellType::peg), PegSolitaire::Cell(1,'A',cellType::none)}, 
            {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::peg), PegSolitaire::Cell(5,'C',cellType::peg),PegSolitaire::Cell(5,'D',cellType::peg), PegSolitaire::Cell(5,'E',cellType::empty), PegSolitaire::Cell(5,'F',cellType::peg), PegSolitaire::Cell(5,'G',cellType::peg), PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'A',cellType::peg)},
            {PegSolitaire::Cell(6,'A',cellType::none), PegSolitaire::Cell(6,'B',cellType::peg), PegSolitaire::Cell(6,'C',cellType::peg),PegSolitaire::Cell(6,'D',cellType::peg), PegSolitaire::Cell(6,'E',cellType::peg), PegSolitaire::Cell(6,'F',cellType::peg), PegSolitaire::Cell(6,'G',cellType::peg), PegSolitaire::Cell(6,'A',cellType::peg), PegSolitaire::Cell(6,'A',cellType::none)}, 
            {PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'B',cellType::none), PegSolitaire::Cell(7,'C',cellType::peg),PegSolitaire::Cell(7,'D',cellType::peg), PegSolitaire::Cell(7,'E',cellType::peg), PegSolitaire::Cell(7,'F',cellType::peg), PegSolitaire::Cell(7,'G',cellType::peg), PegSolitaire::Cell(7,'A',cellType::none), PegSolitaire::Cell(7,'A',cellType::none)}, 
            {PegSolitaire::Cell(8,'A',cellType::none), PegSolitaire::Cell(8,'B',cellType::none), PegSolitaire::Cell(8,'C',cellType::none),PegSolitaire::Cell(8,'D',cellType::peg), PegSolitaire::Cell(8,'E',cellType::peg), PegSolitaire::Cell(8,'F',cellType::peg), PegSolitaire::Cell(8,'G',cellType::none), PegSolitaire::Cell(8,'A',cellType::none), PegSolitaire::Cell(8,'A',cellType::none)}, 
            {PegSolitaire::Cell(9,'A',cellType::none), PegSolitaire::Cell(9,'B',cellType::none), PegSolitaire::Cell(9,'C',cellType::none),PegSolitaire::Cell(9,'D',cellType::none), PegSolitaire::Cell(5,'D',cellType::peg), PegSolitaire::Cell(9,'F',cellType::none), PegSolitaire::Cell(9,'G',cellType::none), PegSolitaire::Cell(9,'A',cellType::none), PegSolitaire::Cell(9,'A',cellType::none)}
            };
    isTypeSix=false;
    return Board;
}

vector <vector<PegSolitaire::Cell>> PegSolitaire::initGameTypeSix() /* Initiliaze the game as the 'sixth' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
                {PegSolitaire::Cell(1,'A',cellType::none), PegSolitaire::Cell(1,'B',cellType::none), PegSolitaire::Cell(1,'C',cellType::none), PegSolitaire::Cell(1,'D',cellType::none), PegSolitaire::Cell(1,'E',cellType::empty), PegSolitaire::Cell(1,'F',cellType::none), PegSolitaire::Cell(1,'G',cellType::none), PegSolitaire::Cell(1,'H',cellType::none), PegSolitaire::Cell(1,'I',cellType::none)},
                {PegSolitaire::Cell(2,'A',cellType::none), PegSolitaire::Cell(2,'B',cellType::none), PegSolitaire::Cell(2,'C',cellType::none), PegSolitaire::Cell(2,'D',cellType::peg), PegSolitaire::Cell(2,'E',cellType::none), PegSolitaire::Cell(2,'F',cellType::peg), PegSolitaire::Cell(2,'G',cellType::none), PegSolitaire::Cell(2,'H',cellType::none), PegSolitaire::Cell(2,'I',cellType::none)},
                {PegSolitaire::Cell(3,'A',cellType::none), PegSolitaire::Cell(3,'B',cellType::none), PegSolitaire::Cell(3,'C',cellType::peg), PegSolitaire::Cell(3,'D',cellType::none), PegSolitaire::Cell(3,'E',cellType::peg), PegSolitaire::Cell(3,'F',cellType::none), PegSolitaire::Cell(3,'G',cellType::peg), PegSolitaire::Cell(3,'H',cellType::none), PegSolitaire::Cell(3,'I',cellType::none)},
                {PegSolitaire::Cell(4,'A',cellType::none), PegSolitaire::Cell(4,'B',cellType::peg), PegSolitaire::Cell(4,'C',cellType::none), PegSolitaire::Cell(4,'D',cellType::peg), PegSolitaire::Cell(4,'E',cellType::none), PegSolitaire::Cell(4,'F',cellType::peg), PegSolitaire::Cell(4,'G',cellType::none), PegSolitaire::Cell(4,'H',cellType::peg), PegSolitaire::Cell(4,'I',cellType::none)},
                {PegSolitaire::Cell(5,'A',cellType::peg), PegSolitaire::Cell(5,'B',cellType::none), PegSolitaire::Cell(5,'C',cellType::peg), PegSolitaire::Cell(5,'D',cellType::none), PegSolitaire::Cell(5,'E',cellType::peg), PegSolitaire::Cell(5,'F',cellType::none), PegSolitaire::Cell(5,'G',cellType::peg), PegSolitaire::Cell(5,'H',cellType::none), PegSolitaire::Cell(5,'I',cellType::peg)},
            };
    isTypeSix = true;
    return Board;
}



int PegSolitaire::gameScore() const/*Calculates the game score. COunts the pegs in the current board */
{
    int counterPeg = 0;
    int size_row = getBoard().size(); /* Find the row size of board */
    int size_column = getBoard().at(0).size(); /* Find the column size of board */

    for(int i=0;i<size_row;i++)
        for(int k=0;k<size_column;k++)
            if(getBoard().at(i).at(k).getCell()==cellType::peg) ++counterPeg;

    return counterPeg;
}

bool PegSolitaire::moveValid(int xChoice, int yChoice, string directionChoice) const/* This function checks that the move is valid or not; if the move is valid, returns true */
{ 
    bool result = false;
    int size_row =  board.size(); /* Find the row size of board */
    int size_column = board.at(0).size(); /* Find the column size of board */

    if(xChoice>=size_row || xChoice<0 || yChoice>=size_column || yChoice<0) /* If the entered row and column are out of board's size, it means that the move is invalid. */
        return false;

    if(isTypeSix) /* If the board type is 'Type-6'... *//* This if-else block is written for only right and left moves */
    {
        if(directionChoice=="R")
        {
            if(!(yChoice+4<size_column)) /* If the cell that will be moved to 'right' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice][(yChoice)+2].getCell()==cellType::peg && board[xChoice][(yChoice)+4].getCell()==cellType::empty))
                result = true;
            else
                result = false;
        }
    

        else if(directionChoice=="L") 
        {
            if(!(yChoice-4>=0)) /* If the cell that will be moved to 'left' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice][(yChoice)-2].getCell()==cellType::peg && board[xChoice][(yChoice)-4].getCell()==cellType::empty))
                result = true;
            else
                result = false;
        }
    }

    else /* If the board type is NOT 'Type-6' *//* This if-else block is written for only 'right' and 'left' moves */
    {
        if(directionChoice=="R")
        {
            if(!(yChoice+2<size_column)) /* If the cell that will be moved to 'right' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice][(yChoice)+1].getCell()==cellType::peg && board[xChoice][(yChoice)+2].getCell()==cellType::empty))
                result = true;
            else
                result = false;
        }
    

        else if(directionChoice=="L")
        {
            if(!(yChoice-2>=0)) /* If the cell that will be moved to 'left' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice][(yChoice)-1].getCell()==cellType::peg && board[xChoice][(yChoice)-2].getCell()==cellType::empty))
                result = true;
            else
                result = false;
        }
    }


    if(directionChoice=="U")
    {
        if(!(xChoice-2>=0)) /* If the cell that will be moved to 'up' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice-1][yChoice].getCell()==cellType::peg && board[xChoice-2][yChoice].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }
    

    else if(directionChoice=="D")
    {
        if(!(xChoice+2<size_row)) /* If the cell that will be moved to 'down' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice+1][yChoice].getCell()==cellType::peg && board[xChoice+2][yChoice].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="UR")
    {
        if(!(xChoice-2>=0) && yChoice+2<size_column) /* If the cell that will be moved to 'up-right' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice-1][yChoice+1].getCell()==cellType::peg && board[xChoice-2][yChoice+2].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="UL")
    {
        if(!(xChoice-2>=0 && yChoice-2>=0)) /* If the cell that will be moved to 'up-left' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice-1][yChoice-1].getCell()==cellType::peg && board[xChoice-2][yChoice-2].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="DR")
    {
        if(!(xChoice+2<size_row && yChoice+2<size_column)) /* If the cell that will be moved to 'down-right' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move starts must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice+1][yChoice+1].getCell()==cellType::peg && board[xChoice+2][yChoice+2].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="DL")
    {
        if(!(xChoice+2<size_row && yChoice-2>=0)) /* If the cell that will be moved to 'down-left' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move starts must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)].getCell()==cellType::peg && board[xChoice+1][yChoice-1].getCell()==cellType::peg && board[xChoice+2][yChoice-2].getCell()==cellType::empty)
            result = true;
        else
            result = false;
    }
    return result;
}

bool PegSolitaire::checkFinish() const/* This function checks whether the game is over */
{
    bool result = true;
    if(isTypeSix)
    {
        /* This loop tries to make move from all the cells, if there are no valid move then returns TRUE that means the game is finished */
        for(int i = 0;i<board.size();i++)
        {
            for(int k=0;k<board.at(0).size();k++)
            {
                if(moveValid(i,(k),"UR") ||  moveValid(i,(k),"DL") || 
                    moveValid(i,(k),"UL") || moveValid(i,(k),"DR") || 
                    moveValid(i,(k),"R") || moveValid(i,(k),"L"))
                    {
                        result=false;
                        return result;
                    }
            }
        }
    }

    else
    {
         /* This loop tries to make move from all the cells, if there are no valid move then returns TRUE that means the game is finished */
        for(int i = 0;i<board.size();i++)
        {
            for(int k=0;k<board[0].size();k++)
            {
                if(moveValid(i,(k),"R") ||  moveValid(i,(k),"L") || 
                    moveValid(i,(k),"U") || moveValid(i,(k),"D"))
                    {
                        result=false;
                        return result;
                    }
            }
        }
    }

    return result;
}

void PegSolitaire::makeMove(int xChoice, int yChoice, string directionChoice) /* This function makes move. Updates the board according to valid move */
{
    if(isTypeSix)
    {
        if(directionChoice=="R")
        {
            setBoard(xChoice, yChoice, cellType::empty);
            setBoard(xChoice, yChoice+4, cellType::peg);
            setBoard(xChoice,yChoice+2, cellType::empty);
        }
            
        
        else if(directionChoice=="L")
        {
            setBoard(xChoice, yChoice, cellType::empty);
            setBoard(xChoice, yChoice-4, cellType::peg);
            setBoard(xChoice,yChoice-2, cellType::empty);
        }
    }

    else
    {
        if(directionChoice=="R")
        {
            setBoard(xChoice, yChoice, cellType::empty);
            setBoard(xChoice, yChoice+2, cellType::peg);
            setBoard(xChoice,yChoice+1, cellType::empty);
        }
            
        
        else if(directionChoice=="L")
        {
            setBoard(xChoice, yChoice, cellType::empty);
            setBoard(xChoice, yChoice-2, cellType::peg);
            setBoard(xChoice,yChoice-1, cellType::empty);
        }
    }
    
    if(directionChoice=="U")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice-2, yChoice, cellType::peg);
        setBoard(xChoice-1,yChoice, cellType::empty);
    }

    else if(directionChoice=="D")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice+2, yChoice, cellType::peg);
        setBoard(xChoice+1,yChoice, cellType::empty);
    }

    else if(directionChoice=="UL")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice-2, yChoice-2, cellType::peg);
        setBoard(xChoice-1,yChoice-1, cellType::empty);
    }

    else if(directionChoice=="DL")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice+2, yChoice-2, cellType::peg);
        setBoard(xChoice+1,yChoice-1, cellType::empty);
    }

    else if(directionChoice=="DR")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice+2, yChoice, cellType::peg);
        setBoard(xChoice+1,yChoice, cellType::empty);
    }

    else if(directionChoice=="UR")
    {
        setBoard(xChoice, yChoice, cellType::empty);
        setBoard(xChoice-2, yChoice+2, cellType::peg);
        setBoard(xChoice-1,yChoice+1, cellType::empty);
    }
           
    //return board;
}

void PegSolitaire::printBoard() const/* Prints the curent board */
{
    int size_row = getBoard().size(); /* Find the row size of board */
    int size_column = getBoard().at(0).size(); /* Find the column size of board */
    for(int i=0;i<size_row;i++)
    {
        for(int k=0;k<size_column;k++)
        {
            if(i==0 && k==0) /* Printing row coordinates "a b c d ..." */
            {
                cout << "\n    ";
                for(int j=0;j<size_column;j++) cout << static_cast<char>('A' + j) << ' '; 
                cout << "\n\n";
            }

            if(k==0) /* Printing column coordinates "1 2 3 4 5..." */
            {
                cout << (i+1) << "   "; 
            }
           switch(getBoard().at(i).at(k).getCell()) /* Printing the cell according to cell type, in this switch case */
           {
                case cellType::none:
                    cout << ' ' << ' ';
                    break;

                case cellType::empty:
                    cout << '.' << ' ';
                    break;

                case cellType::peg:
                    cout << 'P' << ' ';
                    break;
           }
        }            
       cout << "\n";
    }
}



void PegSolitaire::playGame(int boardType) /* Plays the game  automatically until it ends. */
{
    do
    {   
        /* Getting random movements */
        int xChoice = ((rand() % getBoard().size())+1);
        char yChoice = static_cast<char>((rand() % getBoard().at(0).size())+ 'A');
        string directionChoice;

        /* Get random direction for move according to board type*/
        directionChoice = getRandomMove();
       
        /* If the move is valid then move.*/
        if(moveValid(xChoice-1, yChoice-'A',directionChoice))
        {
            //string goOn;
            makeMove(xChoice-1, yChoice-'A',directionChoice);
            ++numOfTakenPegs;
            cout << "\n\nMove entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
            "\nU: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right\nUL: Up-Left\nDR: Down-Right\nDL: Down-Left\n";
            printBoard();
            cout << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";           
        }
        else
            continue;

    }while (!checkFinish());

    if(checkFinish())
        cout << "GAME OVER! Your score is: " << gameScore() << endl;
    return;
}

void PegSolitaire::play() /* Plays the game  automatically until it ends. */
{
do
    {  
        /* Getting random movements */
        int xChoice = ((rand() % getBoard().size())+1);
        char yChoice = static_cast<char>((rand() % getBoard().at(0).size())+ 'A');
        string directionChoice;

        /* Get random direction for move according to board type*/
        directionChoice = getRandomMove();
       
        /* If the move is valid then move.*/
        if(moveValid(xChoice-1, yChoice-'A',directionChoice))
        {
            string goOn;
            makeMove(xChoice-1, yChoice-'A',directionChoice);
            ++numOfTakenPegs;
            printBoard();
            setTotalPegNumber(-1);
            cout << "\nOne single step is done by automatically!";
            cout << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";
            break;
        }
        else
            continue;

    }while (1);
}

void PegSolitaire::play(Cell moveCell) /* Makes only one movement randomly */
{
    printBoard();
    cout << "\n\nThe current board is above. Please enter your direction choice\n\n" << 
            "U: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right (For only board-6)\nUL: Up-Left (For only board-6)\nDR: Down-Right (For only board-6)\nDL: Down-Left (For only board-6)\n\n";

    
        string choices; /* Row and column selections */
        string directionChoice; /* dircection selection of user */
        char garbage;
        
        /* Ask for move */
        cout << "Make your move for cell "  << moveCell.getColumn() << moveCell.getRow()<< " :";
        string part2;
        
        //getline(cin >> ws,choices);
        cin >> directionChoice;
  
        /* If the move is valid then move.*/
        if(moveValid(moveCell.getRow()-1, moveCell.getColumn()-'A',directionChoice))
            {
                ++numOfTakenPegs;
                makeMove(moveCell.getRow()-1, moveCell.getColumn()-'A',directionChoice);
                printBoard();
                setTotalPegNumber(-1);
                cout << "\nYour move " << moveCell.getColumn() << moveCell.getRow() <<  '-' << directionChoice << " is OK! New board is above. Go on!\n";
                return;
            }
            
        else
        {
            cerr << "\nYour move was not OK! Please enter a valid move!\n";
            return;
        }
    
    cout << "You have made one successful movement!";

}



void PegSolitaire::save(string fileName) /* Saves the game to txt file */
{
    /* Open file in write mode */
    fstream file;
    file.open(fileName, ios::out);

    /* Write the number of moves to the text file */
    file << "NUMBER OF MOVES:\n";
    file << getNumOfTakenPegs() << endl;

    /* Write the type-6 status of game to the text file */
    file << "IS TYPE SIX:\n";
    if(isTypeSix)
        file << "true\n";
    else
        file << "false\n";
    
    /* Write the board's cells to the text file*/
    file << "BOARD:\n";
    for(int i=0;i<board.size();i++)
    {
        file << "L ";
        for(int k=0;k<board.at(0).size();k++)
        {
            if(k==board.at(0).size()-1)
            {
                if(board.at(i).at(k).getCell()==cellType::none)
                    file << '0' << '\n';
                else if(board.at(i).at(k).getCell()==cellType::empty)
                    file << '1' << '\n';
                else if(board.at(i).at(k).getCell()==cellType::peg)
                    file << '2' << '\n';
            }

            else
            {
                if(board.at(i).at(k).getCell()==cellType::none)
                    file << '0' << ' ';
                else if(board.at(i).at(k).getCell()==cellType::empty)
                    file << '1' << ' ';
                else if(board.at(i).at(k).getCell()==cellType::peg)
                    file << '2' << ' ';
            }
        }
    }
    file << 'e'; /* Indicates that the end of the file */
    file.close();
}

vector <vector<PegSolitaire::Cell>> PegSolitaire::load(string nameFile) /* Loads a game from text file */
{
    int eofFlag = 0; /* Indicates whether we reach the end of the file */
    int numOfMoves = 0; /* Number of moves made in the loaded game */
    string gameType; /* Loaded game type, (computer game or human game) */
    vector <vector<PegSolitaire::Cell>> newBoard; /* New board that will be loaded */

    /* Open file in write mode */
    fstream file;
    file.open(nameFile, ios::in);


    if(!file.is_open())
    {
        cerr << "Your file can not be found!\nProgram is terminating... Please start the game again.";
        exit(0);
    }
    while(eofFlag==0)
    {
        string readLine; /* Readed line from text file */
        getline(file,readLine);

        /* We are getting number of moves made from the text file */
        if(readLine=="NUMBER OF MOVES:")
        {
            file >> numOfTakenPegs;
            getline(file,readLine);
            getline(file,readLine);
        }

        /* We are getting board type-6 status of the loaded game from the text file */
        if(readLine=="IS TYPE SIX:")
        {
            getline(file,readLine);
            if(readLine=="false")
                isTypeSix = false;
            else
                isTypeSix = true;
            getline(file,readLine);
        }

        /* We are getting the board from text file to 2D vector board */

        int ctRow = 0; /* Indicates first dimension of the 2D board vector */
        int ctColumn = 0; /* Indicates second dimension of the 2D board vector */
        char readChar; /* Readed character from text file */
        file >> readChar;
        file >> readChar;
        newBoard.resize(ctRow+1); /* Resize the 2D vector board */
        newBoard.at(ctRow).resize(ctColumn+1); /* Resize the 2D vector board */
        while(1)
        {
            file >> readChar;
            if(readChar=='L')
            {
                ctColumn = 0;
                ++ctRow;
                newBoard.resize(ctRow+1);
            }
            else if(readChar=='\n' || readChar==' ')
                continue;

            else if(readChar=='e') /* Indicates that we reach the end of the file */
            {
                eofFlag = 1;
                break;
            }
                
            else
            {
                             
                switch(readChar)
                {
                    case '0':
                    {
                        newBoard.at(ctRow).push_back(PegSolitaire::Cell(ctRow+1,static_cast<char>(ctColumn+'A'),cellType::none));
                        break;
                    }
                        
                    case '1':
                    {
                        newBoard.at(ctRow).push_back(PegSolitaire::Cell(ctRow+1,static_cast<char>(ctColumn+'A'),cellType::empty));
                        break;
                    }
                        
                    case '2':
                    {
                        newBoard.at(ctRow).push_back(PegSolitaire::Cell(ctRow+1,static_cast<char>(ctColumn+'A'),cellType::peg));
                        break;
                    }
                }
                ++ctColumn;
            }
        }
    }
    file.close();

    /* Inform the user */
    cout << "\n*******************************************************************************************\n";
    cout << "The game is loaded successfuly. New game is starting... New board and the game information will be belove.\nThe move number that had been done in the game that is loaded is:  " <<
    numOfMoves << endl;
    cout << "\n*******************************************************************************************\n";

    return newBoard;
}

bool PegSolitaire::compare(PegSolitaire objectTwo) const
{
    int numOfPegsO1 = getNumberOfPegs();
    int numofPegsO2 = objectTwo.getNumberOfPegs();

    if(numOfPegsO1>numofPegsO2)
        return true;
    else
        return false;
}



void PegSolitaire::setTotalPegNumber(int change)
{
    totalPegs += change;
}