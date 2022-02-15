/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include <vector>
#include <string>
using namespace std;

enum class Cell {none, empty, peg};

vector <vector<Cell>> initGameTypeFour(); /* Initiliaze the game as the 'first' table that is showed in PDF */

vector <vector<Cell>> initGameTypeTwo(); /* Initiliaze the game as the 'second' table that is showed in PDF */

vector <vector<Cell>> initGameTypeOne(); /* Initiliaze the game as the 'third' table that is showed in PDF */

vector <vector<Cell>> initGameTypeThree(); /* Initiliaze the game as the 'fourth' table that is showed in PDF */

vector <vector<Cell>> initGameTypeFive(); /* Initiliaze the game as the 'fifth' table that is showed in PDF */

vector <vector<Cell>> initGameTypeSix(); /* Iniliaze the game as the 'sixth' table that is showed in PDF */


void print(vector <vector<Cell>> &board); /* Prints the current board */

bool moveValid(vector <vector<Cell>> &board, int xChoice, int yChoice, string directionChoice, bool isTypeSix); 
/* This function checks that the move is valid or not; if the move is valid, returns true */

void makeMove(vector <vector<Cell>> &board, int xChoice, int yChoice, string directionChoice, bool isTypeSix);
/* This function makes move. Updates the board according to valid move */

bool checkFinish(vector <vector<Cell>> &board, bool isTypeSix); 
/* THIS FUNCTION CHECKS WHETHER THE GAME IS OVER */

string getRandomMove(); /* Makes randomly direction selection for board 1-2-3-4-5*/

string getRandomMove(bool isTypeSix); /* Makes randomly direction selection for board 6*/

int gameScore(vector <vector<Cell>> &board); /*Calculates the game score. COunts the pegs in the current board */

void loadGame(fstream &file); /* This function loads the game from text file */

void saveGame(vector <vector<Cell>> &board, string fileName, const int &gameType, const int &numberOfMoves, const bool &isTypeSix); /* This function saves the current game to the text file*/

void humanGame(vector <vector<Cell>> &board, bool isTypeSix, int numberOfMoves = 0); /* Game type that user plays */

void computerGame(vector <vector<Cell>> &board, bool isTypeSix, int numberOfMoves = 0); /* Game type that computer plays */



