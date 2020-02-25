//ConnectFourPlus.h
//Yunus_Gedik
//141044026

#ifndef CONNECTFOURPLUS_H   
#define CONNECTFOURPLUS_H  

#include "ConnectFourAbstract.h"

using namespace std;

class ConnectFourPlus : public ConnectFourAbstract {
    private:
        bool Four(void) override;                                    //Checks if the game has finished or not.
    public:
        ConnectFourPlus();

        ~ConnectFourPlus();
        
        bool play(void) override;                           //Plays for the computer.
                                    
};

#endif