//ConnectFourDiag.h
//Yunus_Gedik
//141044026

#ifndef CONNECTFOURDIAG_H 
#define CONNECTFOURDIAG_H  

#include "ConnectFourAbstract.h"

using namespace std;

class ConnectFourDiag : public ConnectFourAbstract {
    private:
        bool Four(void);                                    //Checks if the game has finished or not.
    public:
        ConnectFourDiag();

        ~ConnectFourDiag();
        
        bool play(void) override;
};

#endif