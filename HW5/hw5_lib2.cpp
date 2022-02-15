/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include "hw5_lib2.h"

using namespace std;

namespace GTU
{
    PegSolitaire::PegSolitaire() 
    {
        file = new fstream;
        file->open("PegSolitaireOutput.txt",ios::app);
    }


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
    int PegSolitaire::boardScore() const
    {
        int counterPeg = 0;
        int size_row = getBoard().size(); /* Find the row size of board */
        int size_column = getBoard().at(0).size(); /* Find the column size of board */

        for(int i=0;i<size_row;i++)
            for(int k=0;k<size_column;k++)
                if(getBoard().at(i).at(k).getCell()==cellType::peg) ++counterPeg;

        return counterPeg;
    }

    

    bool PegSolitaire::endGame() const
    {
        bool result = true;

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
        
        return result;
    }

    void PegSolitaire::setBoard(int x, int y, cellType newCell)
    {
        board[x][y].setCell(newCell);
    }

    bool PegSolitaire::moveValid(int xChoice, int yChoice, string directionChoice) const /* This function checks that the move is valid or not; if the move is valid, returns true */
    { 
        bool result = false;
        int size_row =  board.size(); /* Find the row size of board */
        int size_column = board.at(0).size(); /* Find the column size of board */

        if(xChoice>=size_row || xChoice<0 || yChoice>=size_column || yChoice<0) /* If the entered row and column are out of board's size, it means that the move is invalid. */
            return false;

        
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
        return result;
    }

    void PegSolitaire::makeMove(int xChoice, int yChoice, string directionChoice) /* This function makes move. Updates the board according to valid move */
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
        
        
        else if(directionChoice=="U")
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
    }

    void PegSolitaire::playUser(string input)
    {
        int xChoice; /* row selection of user */
        char yChoice; /* column selection of user */
        string directionChoice; /* dircection selection of user */
        char garbage;

        /* If the input is a valid move command */
        if(input[0]>='A' && input[0]<='Z' && input[1]>='1' && input[1]<='9' && input[2]=='-')
        {
            yChoice = input[0];
            xChoice = input[1] - '0';
            directionChoice = input.substr(3);
        }

        /* If the input is not valid file command nor valid move command */
        else
        {
            cerr << "You entered invalid input. Try again!\n\n";
            *file << "You entered invalid input. Try again!\n\n";
        }
            
        /* If the move is valid then move.*/
        if(moveValid(xChoice-1, yChoice-'A',directionChoice))
            {
                makeMove(xChoice-1, yChoice-'A',directionChoice);
                print();

                cout << "\nYour move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above. Go on!\n";
                *file << "\nYour move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above. Go on!\n";

                cout << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
                *file << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            }
            
        else
        {
            print();

            cerr << "\nYour move was not OK! Please enter a valid move!\n";
            *file << "\nYour move was not OK! Please enter a valid move!\n";

            cout << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            *file << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        }
    

        if(endGame())
        {
            cout << "GAME OVER! Your score is: " << boardScore() << endl;
            *file << "GAME OVER! Your score is: " << boardScore() << endl;       
        }
    }
    void PegSolitaire::playAuto()
    {      
            while(1)
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
                    makeMove(xChoice-1, yChoice-'A',directionChoice);

                    cout << "\n\nYour current score is: " << boardScore() << " Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
                    "\nU: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right\nUL: Up-Left\nDR: Down-Right\nDL: Down-Left\n";
                    *file << "\n\nYour current score is: " << boardScore() << " Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
                    "\nU: Up\nD: Down\nL: Left\nR: Right\nUR: Up-Right\nUL: Up-Left\nDR: Down-Right\nDL: Down-Left\n";

                    print();
                    cout << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";
                    *file << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";
                    break;      
                }
                else continue;
            }
            
        if(endGame())
        {
            cout << "GAME OVER! Your score is: " << boardScore() << endl;
            *file << "GAME OVER! Your score is: " << boardScore() << endl;
        }
        return;
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
        return Board;
    }

    void PegSolitaire::initiliaze()
    {
        board = initGameTypeTwo();
    }

    void PegSolitaire::print() const
    {
        /* Pause */
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0

        int size_row = getBoard().size(); /* Find the row size of board */
        int size_column = getBoard().at(0).size(); /* Find the column size of board */
        for(int i=0;i<size_row;i++)
        {
            for(int k=0;k<size_column;k++)
            {
                if(i==0 && k==0) /* Printing row coordinates "a b c d ..." */
                {
                    cout << "\n    ";
                    *file << "\n    ";
                    for(int j=0;j<size_column;j++)
                    {
                        cout << static_cast<char>('A' + j) << ' '; 
                        *file << static_cast<char>('A' + j) << ' '; 
                    }
                    cout << "\n\n";
                    *file << "\n\n";
                }

                if(k==0) /* Printing column coordinates "1 2 3 4 5..." */
                {
                    cout << (i+1) << "   "; 
                    *file << (i+1) << "   "; 
                }
            switch(getBoard().at(i).at(k).getCell()) /* Printing the cell according to cell type, in this switch case */
            {
                    case cellType::none:
                        cout << ' ' << ' ';
                        *file << ' ' << ' ';
                        break;

                    case cellType::empty:
                        cout << '.' << ' ';
                        *file << '.' << ' ';
                        break;

                    case cellType::peg:
                        cout << 'P' << ' ';
                        *file << 'P' << ' ';
                        break;
            }
            }            
        cout << "\n";
        *file << "\n";
        }
    }

    string PegSolitaire::getRandomMove() const/* Makes randomly direction selection for board 6*/
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

    void PegSolitaire::information() const
    {   
        print();
        cout << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        *file << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
    }
}
