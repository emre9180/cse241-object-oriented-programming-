/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include "hw5_lib4.h"

namespace GTU
{
    Klotski::Klotski()
    {
        file = new fstream;
        file->open("KlotskiOutput.txt",ios::app);
    }

    /*void Klotski::closefile()
    {
        file->close();
        delete file;
    }*/

    void Klotski::initiliaze()
    {
        board = 
        {
            {'A', 'B', 'B', 'C'},
            {'A', 'B', 'B', 'C'},
            {'D', 'E', 'E', 'F'},
            {'D', 'G', 'H', 'F'},
            {'I', ' ', ' ', 'J'}
        };
    }

    inline vector<vector<char>> Klotski::getBoard() const{return board;}

    void Klotski::print() const
    {
        /* Pause */
        std::this_thread::sleep_for(std::chrono::milliseconds(400));
        cout << "\x1b[2J"; 
        cout << "\033[0;0H"; // move cursor to 0,0
        

        for(int i=0;i<5;i++)
        {
            for(int k=0;k<4;k++)
            {
                if(k==3)
                {
                    cout << getBoard()[i][k] << "\n";
                    *file << getBoard()[i][k] << "\n";
                }

                else
                {
                    cout << getBoard()[i][k] << "  ";
                    *file << getBoard()[i][k] << "  ";
                }
            }
        }
        cout << endl << endl;
        *file << endl << endl;
    }

    bool Klotski::endGame() const
    {
        if(getBoard()[3][1]=='B' && getBoard()[3][2]=='B' && getBoard()[2][1]=='B' && getBoard()[2][2]=='B') return true;
        else return false;
    }

    int Klotski::boardScore() const /* Returns the distance between the point of left-top corner of the block B and (2,1) coordinates that its corner has to be. */
    {
        int i,k;
        for(i=0;i<5;i++)
        {
            for(k=0;k<4;k++)
            {
                if(getBoard()[i][k]=='B') break;
            }
        }
        int result = (i-2)*(i-2)  + (k-1)*(k-1);
        return result;

    }

    bool Klotski::moveValid(char selection, string direction) const
    {
        bool flag = true;
        int size_row =  board.size(); /* Find the row size of board */
        int size_column = board.at(0).size(); /* Find the column size of board */

        if(direction=="U")
        {   
            for(int i=0;i<5;i++)
            {
                for(int k=0;k<4;k++)
                {
                    if(i>0 && (getBoard()[i][k]==selection && getBoard()[i-1][k]==' '));
                    else if((i>1 )&& (getBoard()[i][k]==selection && getBoard()[i-1][k]==selection && getBoard()[i-2][k]==' '));
                    else if (board[i][k]==selection) flag=false;
                }
            }
        }

        if(direction=="D")
        {   
            for(int i=0;i<5;i++)
            {
                for(int k=0;k<4;k++)
                {
                    if((i<size_row-1) && (getBoard()[i][k]==selection && getBoard()[i+1][k]==' '));
                    else if((i<size_row-2 )&& (getBoard()[i][k]==selection && getBoard()[i+1][k]==selection && getBoard()[i+2][k]==' '));
                    else if (board[i][k]==selection) flag=false;
                }
            }
        }

        if(direction=="R")
        {   
            for(int i=0;i<5;i++)
            {
                for(int k=0;k<4;k++)
                {
                    if((k<size_column-1) && (getBoard()[i][k]==selection && getBoard()[i][k+1]==' '));
                    else if((k<size_column-2) && (getBoard()[i][k]==selection && getBoard()[i][k+1]==selection && getBoard()[i][k+2]==' '));
                    else if (board[i][k]==selection) flag=false;
                }
            }
        }

        if(direction=="L")
        {   
            for(int i=0;i<5;i++)
            {
                for(int k=0;k<4;k++)
                {
                    if((k>0) && (getBoard()[i][k]==selection && getBoard()[i][k-1]==' '));
                    else if((k>1) && (getBoard()[i][k]==selection && getBoard()[i][k-1]==selection && getBoard()[i][k-2]==' '));
                    else if (board[i][k]==selection) flag=false;
                }
            }
        }
        return flag;
    }

    void Klotski::makeMove(char selection, string direction)
    {   
        /* Counting the number of characters that will be change */
        int numberOfTarget = 0;
        for(int i=0;i<5;i++)
            for(int k=0;k<4;k++)
                if(getBoard()[i][k]==selection) numberOfTarget++;

        int ct = 0; /* Indicates that moves that has been made */

        if(direction=="U")
        {   
            while(ct<numberOfTarget)
            {
                for(int i=0;i<5;i++)
                {
                    if(ct>=numberOfTarget) break;
                    for(int k=0;k<4;k++)
                    {
                        if(i==0) continue;
                        if(ct>=numberOfTarget) break;
                        if(getBoard()[i][k]==selection && getBoard()[i-1][k]==' ')
                        {
                            ++ct;
                            board[i-1][k] = board[i][k];
                            board[i][k] = ' ';
                        }
                    }
                }
            }
            
        }

        if(direction=="D")
        {   
            while(ct<numberOfTarget)
            {
                for(int i=0;i<5;i++)
                {
                    if(ct>=numberOfTarget) break;
                    for(int k=0;k<4;k++)
                    {
                        if(ct>=numberOfTarget) break;
                        if(i==4) continue;
                        if(getBoard()[i][k]==selection && getBoard()[i+1][k]==' ')
                        {
                            ++ct;
                            board[i+1][k] = board[i][k];
                            board[i][k] = ' ';
                        }
                    }
                }
            }

        }


        if(direction=="R")
        {   
            while(ct<numberOfTarget)
            {
                for(int i=0;i<5;i++)
                {   
                    if(ct>=numberOfTarget) break;
                    for(int k=0;k<4;k++)
                    {   
                        if(k==3) continue;
                        if(ct>=numberOfTarget) break;
                        if(getBoard()[i][k]==selection && getBoard()[i][k+1]==' ')
                        {
                            ++ct;
                            board[i][k+1] = board[i][k];
                            board[i][k] = ' ';
                        }
                    }
                }
            }
            
        }

        if(direction=="L")
        {   
            while(ct<numberOfTarget)
            {
                for(int i=0;i<5;i++)
                {
                    if(ct>=numberOfTarget) break;
                    for(int k=0;k<4;k++)
                    {
                        if(k==0) continue;
                        if(ct>=numberOfTarget) break;
                        if(getBoard()[i][k]==selection && getBoard()[i][k-1]==' ')
                        {
                            ++ct;
                            board[i][k-1] = board[i][k];
                            board[i][k] = ' ';
                        }
                    }
                }
            }
            
        }
    }

    void Klotski::playUser(string input)
    {
        print();

        string directionChoice; /* dircection selection of user */

        /* Input validity check */
        if(!(input[0]>='A' && input[0]<='J'))
        {
            cout << "Your entry is not OK! Please try again!\n";
            *file << "Your entry is not OK! Please try again!\n";
            return;
        }

        /* Input validity check */
        if(!input[2]=='U' && !input[2]=='D' && !input[2]=='R' && !input[2]=='L')
        {
            cout << "Your entry is not OK! Please try again!\n";
            *file << "Your entry is not OK! Please try again!\n";
            return;
        }

        directionChoice = input.substr(2);

        /* If the move is valid then move.*/
        if(moveValid(input[0], directionChoice))
        {
            makeMove(input[0], directionChoice);
            print();

            cout << "\nYour move " << input[0] << '-' << directionChoice << " was OK!\n";
            *file << "\nYour move " << input[0] << '-' << directionChoice << " was OK!\n";

            cout << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. The current board is above. Move entry format is: 'block type'-'direction'. Examples move entries: A-R, F-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            *file << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. The current board is above. Move entry format is: 'block type'-'direction'. Examples move entries: A-R, F-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        }
        else
        {
            print();
            cerr << "\nYour move was not OK! Please enter a valid move!\n";
            *file << "\nYour move was not OK! Please enter a valid move!\n";

            cout << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. The current board is above. Move entry format is: 'block type'-'direction'. Examples move entries: A-R, F-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
            *file << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. The current board is above. Move entry format is: 'block type'-'direction'. Examples move entries: A-R, F-U\n\n" << 
                "U: Up\nD: Down\nL: Left\nR: Right\n\n";
        }
            

    }

    void Klotski::playAuto()
    {
        while(1)
        {
            /* Getting random movements */
            int selection = ((rand() % 10 ));
            string directionChoice;

            /* Get random direction for move according to board type*/
            directionChoice = getRandomMove();

            /* If the move is valid then move.*/
            if(moveValid(static_cast<char> (selection+'A'),directionChoice))
            {
                makeMove(static_cast<char> (selection+'A'),directionChoice);

                cout << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. Move entry format is: 'block name'-'direction'. Examples move entries: A-R, H-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
                *file << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. Move entry format is: 'block name'-'direction'. Examples move entries: A-R, H-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";

                print();

                cout << "\nThe random move " << static_cast<char> (selection+'A') <<  '-' << directionChoice << " is OK! New board is above.\n";
                *file << "\nThe random move " << static_cast<char> (selection+'A') <<  '-' << directionChoice << " is OK! New board is above.\n"; 
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

    string Klotski::getRandomMove() const/* Makes randomly direction selection for board 6*/
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

    void Klotski::information() const
    {
        print();
        cout << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. Move entry format is: 'block name'-'direction'. Examples move entries: A-R, H-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
        *file << "\n\nYour current score is: " << boardScore() << " Your goal is reach the block B to exit. Move entry format is: 'block name'-'direction'. Examples move entries: A-R, H-U" << 
                "\nU: Up\nD: Down\nL: Left\nR: Right\n";
    }
}
