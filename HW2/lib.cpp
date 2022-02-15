/* EMRE YILMAZ - 1901042606 - Gebze Technical University */
/* NOTE: Default parameters is only defined in function declarations, not in implementations */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "lib.h"

using namespace std;

vector <vector<Cell>> initGameTypeFour() /* Initiliaze the game as the 'first' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}, 
            {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::empty,Cell::peg,Cell::peg,Cell::peg},{Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg}, 
            {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}
            };
   return Board;
}

vector <vector<Cell>> initGameTypeTwo() /* Initiliaze the game as the 'second' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {Cell::none, Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none},
            {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg, Cell::peg, Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::empty,Cell::peg,Cell::peg, Cell::peg, Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg, Cell::peg, Cell::peg}, 
            {Cell::none, Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none ,Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}
            };
    return Board;
}

vector <vector<Cell>> initGameTypeOne() /* Initiliaze the game as the 'third' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}, {Cell::none, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::none}, 
            {Cell::peg, Cell::peg, Cell::peg,Cell::empty,Cell::peg,Cell::peg,Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg}, 
            {Cell::none, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none}
            };
    return Board;
}

vector <vector<Cell>> initGameTypeThree() /* Initiliaze the game as the 'fourth' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none},
            {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg, Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::empty,Cell::peg,Cell::peg,Cell::peg, Cell::peg}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg,Cell::peg,Cell::peg,Cell::peg, Cell::peg}, 
            {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg,Cell::peg,Cell::none,Cell::none, Cell::none}
            };
    return Board;
}

vector <vector<Cell>> initGameTypeFive() /* Initiliaze the game as the 'fifth' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
            {Cell::none, Cell::none, Cell::none,Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none,Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none}, 
            {Cell::none, Cell::peg, Cell::peg,Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none}, {Cell::peg, Cell::peg, Cell::peg,Cell::peg, Cell::empty, Cell::peg, Cell::peg, Cell::peg, Cell::peg},
            {Cell::none, Cell::peg, Cell::peg,Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none}, {Cell::none, Cell::none, Cell::peg,Cell::peg, Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none}, {Cell::none, Cell::none, Cell::none,Cell::peg, Cell::peg, Cell::peg, Cell::none, Cell::none, Cell::none}, 
            {Cell::none, Cell::none, Cell::none,Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none, Cell::none}
            };
    return Board;
}

vector <vector<Cell>> initGameTypeSix() /* Iniliaze the game as the 'sixth' table that is showed in PDF */
{
    vector <vector<Cell>> Board = {
                {Cell::none, Cell::none, Cell::none, Cell::none, Cell::empty, Cell::none, Cell::none, Cell::none, Cell::none},
                {Cell::none, Cell::none, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::none, Cell::none},
                {Cell::none, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::none},
                {Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none},
                {Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg, Cell::none, Cell::peg},
            };
    return Board;
}


void print(vector <vector<Cell>> &board) /* This function prints the current board */
{
    int size_row = board.size(); /* Find the row size of board */
    int size_column = board[0].size(); /* Find the column size of board */
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
           switch(board[i][k]) /* Printing the cell according to cell type, in this switch case */
           {
                case Cell::none:
                    cout << ' ' << ' ';
                    break;

                case Cell::empty:
                    cout << '.' << ' ';
                    break;

                case Cell::peg:
                    cout << 'P' << ' ';
                    break;
           }
        }            
       cout << "\n";
    }
}


bool moveValid(vector <vector<Cell>> &board, int xChoice, int yChoice, string directionChoice, bool isTypeSix) /* This function checks that the move is valid or not; if the move is valid, returns true */
{ 
    bool result = false;
    int size_row = board.size(); /* Find the row size of board */
    int size_column = board[0].size(); /* Find the column size of board */

    if(xChoice>=size_row || xChoice<0 || yChoice>=size_column || yChoice<0) /* If the entered row and column are out of board's size, it means that the move is invalid. */
        return false;

    if(isTypeSix) /* If the board type is 'Type-6'... *//* This if-else block is written for only right and left moves */
    {
        if(directionChoice=="R")
        {
            if(!(yChoice+4<size_column)) /* If the cell that will be moved to 'right' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)]==Cell::peg && board[xChoice][(yChoice)+2]==Cell::peg && board[xChoice][(yChoice)+4]==Cell::empty))
                result = true;
            else
                result = false;
        }
    

        else if(directionChoice=="L") 
        {
            if(!(yChoice-4>=0)) /* If the cell that will be moved to 'left' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)]==Cell::peg && board[xChoice][(yChoice)-2]==Cell::peg && board[xChoice][(yChoice)-4]==Cell::empty))
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
            else if((board[xChoice][(yChoice)]==Cell::peg && board[xChoice][(yChoice)+1]==Cell::peg && board[xChoice][(yChoice)+2]==Cell::empty))
                result = true;
            else
                result = false;
        }
    

        else if(directionChoice=="L")
        {
            if(!(yChoice-2>=0)) /* If the cell that will be moved to 'left' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if((board[xChoice][(yChoice)]==Cell::peg && board[xChoice][(yChoice)-1]==Cell::peg && board[xChoice][(yChoice)-2]==Cell::empty))
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
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice-1][yChoice]==Cell::peg && board[xChoice-2][yChoice]==Cell::empty)
            result = true;
        else
            result = false;
    }
    

    else if(directionChoice=="D")
    {
        if(!(xChoice+2<size_row)) /* If the cell that will be moved to 'down' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice+1][yChoice]==Cell::peg && board[xChoice+2][yChoice]==Cell::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="UR")
    {
        if(!(xChoice-2>=0) && yChoice+2<size_column) /* If the cell that will be moved to 'up-right' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice-1][yChoice+1]==Cell::peg && board[xChoice-2][yChoice+2]==Cell::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="UL")
    {
        if(!(xChoice-2>=0 && yChoice-2>=0)) /* If the cell that will be moved to 'up-left' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice-1][yChoice-1]==Cell::peg && board[xChoice-2][yChoice-2]==Cell::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="DR")
    {
        if(!(xChoice+2<size_row && yChoice+2<size_column)) /* If the cell that will be moved to 'down-right' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move starts must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice+1][yChoice+1]==Cell::peg && board[xChoice+2][yChoice+2]==Cell::empty)
            result = true;
        else
            result = false;
    }

    else if(directionChoice=="DL")
    {
        if(!(xChoice+2<size_row && yChoice-2>=0)) /* If the cell that will be moved to 'down-left' is out of board's size, it means that the move is invalid. */
            result = false;
        /* The cell that our move starts must be PEG, the cell that our move starts must be PEG, the cell that our move ends must be EMPTY*/
        else if(board[xChoice][(yChoice)]==Cell::peg && board[xChoice+1][yChoice-1]==Cell::peg && board[xChoice+2][yChoice-2]==Cell::empty)
            result = true;
        else
            result = false;
    }
    return result;
}

void makeMove(vector <vector<Cell>> &board, int xChoice, int yChoice, string directionChoice, bool isTypeSix) /* This function makes move. Updates the board according to valid move */
{
    if(isTypeSix)
    {
        if(directionChoice=="R")
        {
            board[xChoice][yChoice] = Cell::empty;
            board[xChoice][yChoice+4] = Cell::peg;
            board[xChoice][yChoice+2] = Cell::empty;
        }
            
        
        else if(directionChoice=="L")
        {
            board[xChoice][yChoice] = Cell::empty;
            board[xChoice][yChoice-4] = Cell::peg;
            board[xChoice][yChoice-2] = Cell::empty;
        }
    }

    else
    {
        if(directionChoice=="R")
        {
            board[xChoice][yChoice] = Cell::empty;
            board[xChoice][yChoice+2] = Cell::peg;
            board[xChoice][yChoice+1] = Cell::empty;
        }
            
        
        else if(directionChoice=="L")
        {
            board[xChoice][yChoice] = Cell::empty;
            board[xChoice][yChoice-2] = Cell::peg;
            board[xChoice][yChoice-1] = Cell::empty;
        }
    }
    
    if(directionChoice=="U")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice-2][yChoice] = Cell::peg;
        board[xChoice-1][yChoice] = Cell::empty;
    }

    else if(directionChoice=="D")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice+2][yChoice] = Cell::peg;
        board[xChoice+1][yChoice] = Cell::empty;
    }

    else if(directionChoice=="UL")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice-2][yChoice-2] = Cell::peg;
        board[xChoice-1][yChoice-1] = Cell::empty;
    }

    else if(directionChoice=="DL")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice+2][yChoice-2] = Cell::peg;
        board[xChoice+1][yChoice-1] = Cell::empty;
    }

    else if(directionChoice=="DR")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice+2][yChoice+2] = Cell::peg;
        board[xChoice+1][yChoice+1] = Cell::empty;
    }

    else if(directionChoice=="UR")
    {
        board[xChoice][yChoice] = Cell::empty;
        board[xChoice-2][yChoice+2] = Cell::peg;
        board[xChoice-1][yChoice+1] = Cell::empty;
    }
           
    //return board;
}


bool checkFinish(vector <vector<Cell>> &board, bool isTypeSix) /* This function checks whether the game is over */
{
    bool result = true;
    if(isTypeSix)
    {
        /* This loop tries to make move from all the cells, if there are no valid move then returns TRUE that means the game is finished */
        for(int i = 0;i<board.size();i++)
        {
            for(int k=0;k<board[0].size();k++)
            {
                if(moveValid(board,i,(k),"UR",isTypeSix) ||  moveValid(board,i,(k),"DL",isTypeSix) || 
                    moveValid(board,i,(k),"UL",isTypeSix) || moveValid(board,i,(k),"DR",isTypeSix) || 
                    moveValid(board,i,(k),"R",isTypeSix) || moveValid(board,i,(k),"L",isTypeSix))
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
                if(moveValid(board,i,(k),"R",isTypeSix) ||  moveValid(board,i,(k),"L",isTypeSix) || 
                    moveValid(board,i,(k),"U",isTypeSix) || moveValid(board,i,(k),"D",isTypeSix))
                    {
                        result=false;
                        return result;
                    }
            }
        }
    }

    return result;
}

string getRandomMove() /* Makes randomly direction selection for board 1-2-3-4-5*/
{

    string directionChoice;
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

    return directionChoice;
}

string getRandomMove(bool isTypeSix) /* Makes randomly direction selection for board 6*/
{
    string directionChoice;
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

    return directionChoice;
}

int gameScore(vector <vector<Cell>> &board) /*Calculates the game score. COunts the pegs in the current board */
{
    int counterPeg = 0;
    int size_row = board.size(); /* Find the row size of board */
    int size_column = board[0].size(); /* Find the column size of board */

    for(int i=0;i<size_row;i++)
        for(int k=0;k<size_column;k++)
            if(board[i][k]==Cell::peg) ++counterPeg;

    return counterPeg;
}


void saveGame(vector <vector<Cell>> &board, string fileName, const int &gameType, const int &numberOfMoves, const bool &isTypeSix) /* This function saves the current game to the text file*/
{
    /* Open file in write mode */
    fstream file;
    file.open(fileName, ios::out);

    /* Write the game's type to the text file */
    file << "GAME TYPE:\n";
    if(gameType==1)
        file << "human\n";
    else   
        file << "computer\n";
    
    /* Write the number of moves to the text file */
    file << "NUMBER OF MOVES:\n";
    file << numberOfMoves << endl;

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
                if(board.at(i).at(k)==Cell::none)
                    file << '0' << '\n';
                else if(board.at(i).at(k)==Cell::empty)
                    file << '1' << '\n';
                else if(board.at(i).at(k)==Cell::peg)
                    file << '2' << '\n';
            }

            else
            {
                if(board.at(i).at(k)==Cell::none)
                    file << '0' << ' ';
                else if(board.at(i).at(k)==Cell::empty)
                    file << '1' << ' ';
                else if(board.at(i).at(k)==Cell::peg)
                    file << '2' << ' ';
            }
        }
    }
    file << 'e'; /* Indicates that the end of the file */
    file.close();
}

void loadGame(fstream &file) /* This function loads the game from text file */
{
    bool isTypeSix; /* Indicates that the load game is type-6 board or not */
    int eofFlag = 0; /* Indicates whether we reach the end of the file */
    int numOfMoves = 0; /* Number of moves made in the loaded game */
    string gameType; /* Loaded game type, (computer game or human game) */
    vector <vector<Cell>> newBoard; /* New board that will be loaded */

    if(!file.is_open())
    {
        cerr << "Your file can not be found!\nProgram is terminating... Please start the game again.";
        return;
    }
    while(eofFlag==0)
    {
        string readLine; /* Readed line from text file */
        getline(file,readLine);

        /* We are getting loaded game type from the text file */
        if(readLine=="GAME TYPE:")
        {
            getline(file,readLine);
            if(readLine=="human")
                gameType = "Human";
            else   
                gameType = "Computer";
            getline(file,readLine);
        }

        /* We are getting number of moves made from the text file */
        if(readLine=="NUMBER OF MOVES:")
        {
            file >> numOfMoves;
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
                    newBoard.at(ctRow).push_back(Cell::none);
                    break;

                    case '1':
                    newBoard.at(ctRow).push_back(Cell::empty);
                    break;

                    case '2':
                    newBoard.at(ctRow).push_back(Cell::peg);
                    break;
                }

                ++ctColumn;
            }
        }
    }
    file.close();

    /* Inform the user */
    cout << "\n*******************************************************************************************\n";
    cout << "The game is loaded successfuly. New game is starting... New board and the game information will be belove.\nThe move number that had been done in the game that is loaded is:  " <<
    numOfMoves << endl << "The type of the game: "<< gameType;
    cout << "\n*******************************************************************************************\n";
    
    /* Start the loaded game according the game type */
    if(gameType=="Human")
        humanGame(newBoard, isTypeSix, numOfMoves);
    else
        computerGame(newBoard, isTypeSix, numOfMoves);
}

void humanGame(vector <vector<Cell>> &board, bool isTypeSix, int numberOfMoves)
{
    print(board);
    cout << "\n\nThe current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
    "U: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right (For only board-6)\nUL: Up-Left (For only board-6)\nDR: Down-Right (For only board-6)\nDL: Down-Left (For only board-6)\n" <<
    "Type 'SAVE FILE.TXT' to save the current game to FILE.TXT\nType 'LOAD FILE.TXT' to load the game that is stored in FILE.TXT\n\n";;

    do
    {
        string choices; /* Row and column selections */
        int xChoice; /* row selection of user */
        char yChoice; /* column selection of user */
        string directionChoice; /* dircection selection of user */
        char garbage;
        
        /* Ask for move */
        cout << "Make your move: ";
        string part2;
        
        getline(cin >> ws,choices);
    
        /* Check the file commands */

        if(choices.substr(0,4)=="LOAD")
        {
            string fileName;
            decltype (choices.find("LOAD")) pos;
            pos = choices.find("LOAD");
            fileName = choices.substr(pos+5);
            /* Open the file in read mode */
            fstream file;
            file.open(fileName, ios::in);
            if(!file.is_open())
            {
                cerr << "Your file can not be found. Please try again!\n\n";
                continue;
            }
            else
            {
                loadGame(file);
                exit(0);
            }
        }

        else if(choices.substr(0,4)=="SAVE")
        {
            string fileName;
            auto pos = choices.find("SAVE");
            fileName = choices.substr(pos+5);
            saveGame(board, fileName, 1, numberOfMoves, isTypeSix);
            cout << "Save process is done successfuly!\n";
            continue;
        }
    
        /* If the input is a valid move command */
        else if(choices[0]>='A' && choices[0]<='Z' && choices[1]>='1' && choices[1]<='9' && choices[2]=='-')
        {
            yChoice = choices[0];
            xChoice = choices[1] - '0';
            directionChoice = choices.substr(3);
        }

        /* If the input is not valid file command nor valid move command */
        else
        {
            cerr << "You entered invalid input. Try again!\n\n";
            continue;
        }

        /* If the move is valid then move.*/
        if(moveValid(board,xChoice-1, yChoice-'A',directionChoice,isTypeSix))
            {
                ++numberOfMoves;
                makeMove(board,xChoice-1, yChoice-'A',directionChoice,isTypeSix);
                print(board);
                cout << "\nYour move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above. Go on!\n";
                cout << "\n\nThe current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right (For only board-6)\nUL: Up-Left (For only board-6)\nDR: Down-Right (For only board-6)\nDL: Down-Left (For only board-6)\n\n";
            }
            
        else
        {
            print(board);
            cerr << "\nYour move was not OK! Please enter a valid move!\n";
            cout << "\n\nThe current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right (For only board-6)\nUL: Up-Left (For only board-6)\nDR: Down-Right (For only board-6)\nDL: Down-Left (For only board-6)\n\n";
            continue;
        }
    }while(!checkFinish(board,isTypeSix));

    if(checkFinish)
        cout << "GAME OVER! Your score is: " << gameScore(board) << endl;
}

void computerGame(vector <vector<Cell>> &board, bool isTypeSix, int numberOfMoves)
{
    do
    {   
        int xChoice = ((rand() % board.size())+1);
        char yChoice = static_cast<char>((rand() % board[0].size())+ 'A');
        string directionChoice;

        /* Get random direction for move according to board type*/
        if(isTypeSix) directionChoice = getRandomMove(isTypeSix);
        else directionChoice = getRandomMove();
       
        /* If the move is valid then move.*/
        if(moveValid(board,xChoice-1, yChoice-'A',directionChoice,isTypeSix))
        {
            string goOn;
            makeMove(board,xChoice-1, yChoice-'A',directionChoice,isTypeSix);
            ++numberOfMoves;
            cout << "\n\nMove entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
            "\nU: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right\nUL: Up-Left\nDR: Down-Right\nDL: Down-Left\n";
            print(board);
            cout << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\nType something to go next move" << 
            "\nType 'SAVE FILE.TXT' to save the current game to FILE.TXT\nType 'LOAD FILE.TXT' to load the game that is stored in FILE.TXT\n\n";
            getline(cin >> ws,goOn);

            if(goOn.substr(0,4)=="LOAD")
            {
                string fileName;
                int pos = goOn.find("LOAD");
                fileName = goOn.substr(pos+5);

                /* Open text file in read mode */
                fstream file;
                file.open(fileName, ios::in);
                if(!file.is_open())
                {
                    cerr << "\n\n*********************************************************" << "\nYour file can not be found. Please try again.\n" << 
                    "*********************************************************\n" << "\t\t\tWARNING";
                    cerr << "\n*********************************************************" << "\nYour file can not be found. Please try again.\n" << 
                    "*********************************************************\n";

                    continue;
                }
                else
                {
                    loadGame(file);
                    exit(0);
                }
                
            }

            else if(goOn.substr(0,4)=="SAVE")
            {
                string fileName;
                int pos = goOn.find("SAVE");
                fileName = goOn.substr(pos+5);
                saveGame(board, fileName, 2, numberOfMoves, isTypeSix);

                cout << "\n*******************************************************************************************\n";
                cout << "\n\n*********************************************************" << "\nSave process is done successfuly! The game is going on...\n" << 
                "*********************************************************\n" << "\t\t\tINFORMATION";
                cout << "\n*********************************************************" << "\nSave process is done successfuly! The game is going on...\n" << 
                "*********************************************************\n";

                continue;
            }
        }
        else
            continue;

    } while (!checkFinish(board, isTypeSix));

    if(checkFinish)
        cout << "GAME OVER! Your score is: " << gameScore(board) << endl;
    
}
