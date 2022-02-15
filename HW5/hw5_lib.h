/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#ifndef HW5_LIB_H
#define HW5_LIB_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <thread> /* To pause while printing the games */
#include <chrono> /* To pause while printing the games */

using namespace std;

namespace GTU
{
    class BoardGame2D
    {
        public:

            BoardGame2D();

            virtual void playUser(string input) = 0; /* Takes a string as a parameter and plays the game accordingly. */
            virtual void playUser() final; /* Plays the game until it is over. */
            virtual void playAuto() = 0; /* Plays the game by the computer for one move */
            virtual void playAutoAll() final; /* It plays the game until it is over. This one calls playAuto for all the moves. It also prints the board between the moves after some pause. */
            virtual void print() const = 0; /* < Prints the game on the screen starting from the top left corner of the terminal. */
            friend ostream& operator <<(ostream& outputStream, const BoardGame2D& object); 
            virtual bool endGame() const = 0; /*  Returns true if the game is ended. */
            virtual int boardScore() const = 0; /* returns an int score value for the current board. It returns a positive integer that indicates the goodness of the current board. Smaller the returned value, better the board. If the game is
                                        finished for the current board, it returns return 0, which is the best case. */
            virtual void initiliaze() = 0; /* Initializes the board. For some games the initial board is the same, for other games the initial board is random. */
            static void playVector(vector<BoardGame2D*> objects); /* . It plays all the games in the vector until they end. */
            virtual void information() const = 0; /* Prints the information about the related game */
  

            

        private:
            


    };
}



#endif

