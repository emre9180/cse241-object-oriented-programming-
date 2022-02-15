/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include "hw5_lib.h"

using namespace std;

namespace GTU
{
    BoardGame2D::BoardGame2D() {}

    void BoardGame2D::playAutoAll()
    {
        int ct = 1;
        while(!endGame())
        {
            if(ct%20==0)
            {
                string select;
                cout << "1. I am bored. I do not want to play anymore.\n2. GO ON!\nYour choice: ";
                cin >> select;
                if(select=="1") break;
            }
            else 
            {
                playAuto();
            }

            ct++;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1800));
    
    }


    void BoardGame2D::playUser()
    {   
        information();
        do
        {   
            string choices; /* Row and column selections */
            
            /* Ask for move */
            cout << "Make your move (to exit, type EXIT): ";
            
            getline(cin >> ws,choices);
            if(choices=="EXIT")
            {
                cout << "Bye!\n";
                return;
            }
            playUser(choices);
        }while(!endGame());

        if(endGame())
        {
            cout << "GAME OVER! Your score is: " << boardScore() << endl;
        }
    }

    void BoardGame2D::playVector(vector<BoardGame2D*> objects)
    {
        int size = objects.size();
        for(int i=0;i<size;i++)
        {
            objects.at(i)->playAutoAll();
            if(objects.at(i)->endGame())
                continue;
        }
    }

    ostream& operator <<(ostream& outputStream, const BoardGame2D* object)
    {
        object->print();
        return outputStream;
    } 
}
