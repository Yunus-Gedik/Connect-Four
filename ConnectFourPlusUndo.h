//ConnectFourPlusUndo.h
//Yunus_Gedik
//141044026

#ifndef CONNECTFOURPLUSUNDO_H   
#define CONNECTFOURPLUSUNDO_H 

#include "ConnectFourAbstract.h"

using namespace std;

class ConnectFourPlusUndo : public ConnectFourAbstract {
    protected:
        int ** Undos;                               //Carries the steps played.
        int Undosize=0;                             //Carries how many step have played.
        void save(void) override;                   //Saves the game to the txt file with steps have played.
        void load(void) override;                   //Loads the game from the txt file with steps have played.
        void mallocer(void) override;               //Sizes the board.
        bool Four(void) override;                   //Checks if the game has finished or not.
        bool LetterTaker(void) override;            //Lets the user choose a column to instert or save/load/undo.
        int Filler(char player) override;           //Fills the choosen column.
        bool play(void) override;                   //Plays for the computer and add a a step to Undos array.
        bool play(char position) override;          //This function has overrided cause we also need to undo the current player.
    public:
        ConnectFourPlusUndo();                      //Allocates Undos array which carries the played steps and gameboard.
        ~ConnectFourPlusUndo();                     //Deallocates.
};

#endif