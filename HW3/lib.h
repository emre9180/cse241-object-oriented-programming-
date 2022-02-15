/* Emre Yilmaz - Gebze Technical University - 1901042606 -*/
/* NOTE FOR T.A. -> The rest of pegs in a finished game is subtracted from total pegs */

#include <vector>
#include <string>
using namespace std;

enum class cellType {none, empty, peg};

class PegSolitaire
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

    PegSolitaire(); /* contructor that makes the board as NULL */
    PegSolitaire(int boardType); /* constractor that makes the board according to board type choice 1-6 */
    PegSolitaire(string fileName); /* constructor that loads that already exists */

    vector <vector<Cell>> initGameTypeOne(); /* Initiliaze the game as the 'first' table that is showed in PDF */
    vector <vector<Cell>> initGameTypeTwo(); /* Initiliaze the game as the 'second' table that is showed in PDF */
    vector <vector<Cell>> initGameTypeFour(); /* Initiliaze the game as the 'fourth' table that is showed in PDF */
    vector <vector<Cell>> initGameTypeThree(); /* Initiliaze the game as the 'third' table that is showed in PDF */
    vector <vector<Cell>> initGameTypeFive(); /* Initiliaze the game as the 'fifth' table that is showed in PDF */
    vector <vector<Cell>> initGameTypeSix(); /* Initiliaze the game as the 'sixth' table that is showed in PDF */

    inline int getNumOfTakenPegs() const {return numOfTakenPegs;}; /* Returns the number of taken pegs from the board */
    int getNumberOfEmpties() const; /* Returns the number of empty cells */
    int getNumberOfPegs() const; /* Returns the number of Pegs */
    inline vector <vector<Cell>> getBoard() const{return board;};
    inline bool getIsTypeSix() const {return isTypeSix;};
    string getRandomMove() const; /* Returns a random movement choice */

    void play(); /* Makes only one movement randomly */
    void play(Cell moveCell); /* User makes only one movement */
    void playGame(int boardType = -1); /* Plays the game  automatically until it ends. */

    vector <vector<Cell>> load();
    vector <vector<Cell>> load(string fileName); /* This function loads the game from text file */
    void save(string fileName); /* This function saves the game to text file */
    bool compare(PegSolitaire objectTwo) const;
    
    void printBoard() const; /* Prints the curent board */
    int gameScore() const; /* Returns the game score when game ends */
    bool checkFinish() const;/* Checks whether game is finished */
    bool moveValid(int xChoice, int yChoice, string directionChoice) const;/* Checks whether move is valid */
    void makeMove(int xChoice, int yChoice, string directionChoice); /* Makes moves, updates the board */
   
    void setIsTypeSix(bool newB);
    void setBoard(int x, int y, cellType cell);

    inline static int getTotalPegNumber(){return totalPegs;};
    void setTotalPegNumber(int change);
    
    
private:
    static int totalPegs;
    int gameType;
    vector <vector<Cell>> board;
    bool isTypeSix;
    int numOfTakenPegs = 0; 
};




