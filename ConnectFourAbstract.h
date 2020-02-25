//ConnectFourAbstract.h
//Yunus_Gedik
//141044026

#ifndef CONNECTFOURABSTRACT_H   
#define CONNECTFOURABSTRACT_H 

#include "Cell.h"
#include <string>
using namespace std;


class ConnectFourAbstract: public Cell {
    protected:
        
        Cell ** b;                                                  //Main board.
        int width=0,height=0;                                       //Sizes
        char gametype='a';                                          //C or P
        int turn=1;                                                 //The turn to gametype P
        string temp="";                                             //To take input from user.It can be file name or column name or etc.
        bool PLAYEBLE=true;                                         //If it is true;the game is playeble.
        
        
        virtual void mallocer(void);                                //Sizes the gameboard.
        virtual bool Four(void)=0;                                  //Checks if the game has finished or not.
        void takesizes(int i);                                      //Assigns width and height.
        bool IsEmpty(int i,int j);                                  //Returns true if the cell is empty.
        virtual int Filler(char player);                            //Fills the choosen column.
        virtual bool play(void);                                    //Plays for the computer.
        virtual bool play(char position);                           //Plays for the player.
        bool AnyEmpty(void);                                        //Checks if there is any empty cell to fill.
        virtual bool LetterTaker(void);                             //Lets the user choose a column to instert or save/load.
        bool AnyEmptyInColumn(void);                                //Returns true if are there any empty cell to fill in a specific column.
    public:
        
        int j=0,i=0;
        void Display(void);                                         //Display the game to the console.
        virtual void save(void);                                    //Saves the game to the txt file.
        virtual void load(void);                                    //Loads the game from the txt file.
        void ready(void);                                           //Gets necessary inputs to begin the game and resize the vector.
        bool playGame(void);                                        //Plays the game.
        bool getplayeble(void);                                     //Returns if game is still playeble or not.     
        int livingcell(void);                                       //Livincell:number of filled cells
        int getheight(void);                                        //Returns height.
        int getwidth(void);                                         //Returns width.
            
};

#endif


