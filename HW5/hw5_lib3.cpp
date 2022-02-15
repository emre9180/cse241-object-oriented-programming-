/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include "hw5_lib3.h"

using namespace std;

namespace GTU
{
    EightPuzzle::EightPuzzle()
    {
        file = new fstream;
        file->open("EightPuzzleOutput.txt",ios::app);
    }

    vector<vector<int>> EightPuzzle::init()
    {
        vector<vector<int>> board2
        {
            {1, 2, 3},
            {4, -1, 6},
            {7, 8, 5}
        };
        return board2;
    }

    void EightPuzzle::shuffle()
    {   
        /* Makes 200 movement randomly to shuffle the board */
        for(int i=0;i<200;i++)
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
                    break;   
                }
                else
                    continue;
            }
        }
    }

    void EightPuzzle::initiliaze()
    {
    board = init();
    shuffle();
    }

    bool EightPuzzle::endGame() const
    {
        bool flag = true; /* If the game is NOT finished, the flag will be FALSE */
        int ct = 1;

        for(int i=0;i<3;i++)
        {
            for(int k=0;k<3;k++)
            {   
                if(i==2 && k==2) break;
                if(getBoard()[i][k]!=ct) flag=false;
                ct++;
            }
        }
        return flag;
    }

    void EightPuzzle::print() const
    {
        /* Pause */
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0

        cout << "\t";
        *file << "\t";

        for(int i=0;i<3;i++)
        {
            cout << static_cast<char>(i+'A') << "   ";
            *file << static_cast<char>(i+'A') << "   ";
        }

        cout << endl << endl << endl;
        *file << endl << endl << endl;

        for(int i=0;i<3;i++)
        {
            for(int k=0;k<3;k++)
            {
                if(k==0)
                {
                    cout << (i+1) << "\t";
                    *file << (i+1) << "\t";

                    if(board[i][k] == -1)
                    {
                        cout << ' ' << "   ";
                        *file << ' ' << "   ";
                    }

                    else
                    {
                        cout << board[i][k] << "   ";
                        *file << board[i][k] << "   ";
                    }

                } 
                
                else if(k==2)
                {
                    if(board[i][k] == -1)
                    {
                        cout << ' ' << "   ";
                        *file << ' ' << "   ";
                    }

                    else
                    {
                        cout << board[i][k] << "   ";
                        *file << board[i][k] << "   ";
                    }

                    cout << endl;
                    *file << endl;
                }

                else
                {
                    if(board[i][k] == -1)
                    {
                        cout << ' ' << "   ";
                        *file << ' ' << "   ";
                    }
                    else
                    {
                        cout << board[i][k] << "   ";
                        *file << board[i][k] << "   ";
                    }
        
                }
            }
        }

        cout << endl << endl;
        *file << endl << endl;
    }

    void EightPuzzle::playAuto()
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
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
                *file << "\n\nYour current score is: " << boardScore() << " Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";

                print();

                cout << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";
                *file << "\nThe random move " << yChoice << xChoice <<  '-' << directionChoice << " is OK! New board is above.\n\n";

                break;   
            }
            else
                continue;
        }
        

        if(endGame())
        {
            cout << "GAME OVER! Congratulations! Your score is: " << boardScore() << endl;
            *file << "GAME OVER! Congratulations! Your score is: " << boardScore() << endl;
        }
            
        return;
    }

    inline vector<vector<int>> EightPuzzle::getBoard() const{return board;};

    void EightPuzzle::setBoard(int x, int y, int newNumber)
    {
        board[x][y] = newNumber;
    }

    void EightPuzzle::makeMove(int xChoice, int yChoice, string directionChoice) /*  This function makes move. Updates the board according to valid move */
    {
        if(directionChoice=="R")
        {
            int temp = board[xChoice][yChoice];
            setBoard(xChoice, yChoice, -1);
            setBoard(xChoice,yChoice+1, temp);
        }
            
        
        else if(directionChoice=="L")
        {
            int temp = board[xChoice][yChoice];
            setBoard(xChoice, yChoice, -1);
            setBoard(xChoice,yChoice-1, temp);
        }
        
        
        else if(directionChoice=="U")
        {
            int temp = board[xChoice][yChoice];
            setBoard(xChoice, yChoice, -1);
            setBoard(xChoice-1,yChoice, temp);
        }

        else if(directionChoice=="D")
        {
            int temp = board[xChoice][yChoice];
            setBoard(xChoice, yChoice, -1);
            setBoard(xChoice+1,yChoice, temp);
        }

    }

    bool EightPuzzle::moveValid(int xChoice, int yChoice, string directionChoice) const /* This function checks that the move is valid or not; if the move is valid, returns true */
    {
        bool result = false;
        int size_row =  board.size(); /* Find the row size of board */
        int size_column = board.at(0).size(); /* Find the column size of board */

        if(xChoice>=size_row || xChoice<0 || yChoice>=size_column || yChoice<0) /* If the entered row and column are out of board's size, it means that the move is invalid. */
            return false;

        
        if(directionChoice=="R")
        {
            if(!(yChoice+1<size_column)) /* If the cell that will be moved to 'right' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if(board[xChoice][yChoice+1]==-1)
                result = true;
            else
                result = false;
        }


        else if(directionChoice=="L")
        {
            if(!(yChoice-1>=0)) /* If the cell that will be moved to 'left' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if(board[xChoice][yChoice-1]==-1)
                result = true;
            else
                result = false;
        }


        if(directionChoice=="U")
        {   
            
            if(!(xChoice-1>=0)) /* If the cell that will be moved to 'up' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be 'PEG', the cell that our move jumps over must be 'PEG', the cell that our move ends must be 'EMPTY'*/
            else if(board[xChoice-1][yChoice]==-1)
                result = true;
            else
                result = false;
        }
        

        else if(directionChoice=="D")
        {
            if(!(xChoice+1<size_row)) /* If the cell that will be moved to 'down' is out of board's size, it means that the move is invalid. */
                result = false;
            /* The cell that our move starts must be PEG, the cell that our move jumps over must be PEG, the cell that our move ends must be EMPTY*/
            else if(board[xChoice+1][yChoice]==-1)
                result = true;
            else
                result = false;
        }
        return result;
    }

    string EightPuzzle::getRandomMove() const/* Makes randomly direction selection for board 6*/
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

    void EightPuzzle::playUser(string input)
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
            return;
        }
        

        /* If the move is valid then move.*/
        if(moveValid(xChoice-1, yChoice-'A',directionChoice))
        {
            makeMove(xChoice-1, yChoice-'A',directionChoice);
            print();
            cout << "\n\nThe move " << yChoice << xChoice << '-' << directionChoice << " is successful." << " Your current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            *file << "\n\nThe move " << yChoice << xChoice << '-' << directionChoice << " is successful." << " Your current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        }
        else
        {
            print();
            cerr << "\nYour move " << yChoice << xChoice << '-' << directionChoice << " was not OK! Please enter a valid move!\n";
            *file << "\nYour move " << yChoice << xChoice << '-' << directionChoice << " was not OK! Please enter a valid move!\n";

            cout << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            *file << "\n\nYour current score is: " << boardScore() << " The current board is above. Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        }

    }

    int EightPuzzle::boardScore() const /* Returns number of numbers that is in the wrong place */
    {
        int ct = 0; /* Number of numbbers that is in the wrong place in tho board */
        int numbers = 1;

        for(int i=0;i<3;i++)
        {
            for(int k=0;k<3;k++)
            {   
                if(i==2 && k==2 && getBoard()[i][k]!=' ') ct++;  
                else if(getBoard()[i][k]!=numbers) ct++;
                numbers++;
            }
        }
        return ct;
    }

    void EightPuzzle::information() const
    {
        print();
        cout << "\n\nYour current score is: " << boardScore() << " Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
        *file << "\n\nYour current score is: " << boardScore() << " Move entry format is: 'coordinate'-'direction'. Examples move entries: D3-R, A5-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
    }
}   


