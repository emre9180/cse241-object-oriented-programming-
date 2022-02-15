/* Emre YILMAZ - 1901042606 - Gebze Technical University */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "hw5_lib2.h"
#include "hw5_lib3.h"
#include "hw5_lib.h"
#include "hw5_lib4.h"

using namespace std;
using namespace GTU;

int main()
{

    vector<BoardGame2D*> games;

    BoardGame2D* pegP = new PegSolitaire;
    pegP->initiliaze();
    games.push_back(pegP);

    BoardGame2D* pegP2 = new PegSolitaire;
    pegP2->initiliaze();
    games.push_back(pegP2);

    BoardGame2D* pegP3 = new PegSolitaire;
    pegP3->initiliaze();


    BoardGame2D *eightP = new EightPuzzle;
    eightP->initiliaze();
    games.push_back(eightP);

    BoardGame2D *eightP2 = new EightPuzzle;
    eightP2->initiliaze();
    games.push_back(eightP2);

    BoardGame2D *eightP3 = new EightPuzzle;
    eightP3->initiliaze();

    BoardGame2D *klotskiP = new Klotski;
    klotskiP->initiliaze();
    games.push_back(klotskiP);

    BoardGame2D *klotskiP2 = new Klotski;
    klotskiP2->initiliaze();
    games.push_back(klotskiP2);

    BoardGame2D *klotskiP3 = new Klotski;
    klotskiP3->initiliaze();


    

   

    if(!eightP->endGame()) cout << "The EightPuzzle game is not finished yet!\n";
    eightP3->playUser();

     if(!pegP->endGame()) cout << "The PegSolitaire game is not finished yet!\n";
    pegP3->playUser();

    if(!klotskiP->endGame()) cout << "The Klotski game is not finished yet!\n";
    klotskiP3->playUser();
    BoardGame2D::playVector(games);





}


/* 
    output texte
    
    */
