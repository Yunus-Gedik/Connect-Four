//main.cpp
//Yunus_Gedik
//141044026

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>


#include "ConnectFourAbstract.h"
#include "ConnectFourPlus.h"
#include "ConnectFourDiag.h"
#include "ConnectFourPlusUndo.h"

using namespace std;

int main(void){
    
    char gamemode='a';
    string CheckType="";
    int obje;
    
    while(CheckType!="P"&&CheckType!="p"&&CheckType!="D"&&CheckType!="d"&&CheckType!="U"&&CheckType!="u"){              //game mode
        cout<<"Choose a game mode:"<<endl;
        cin>>CheckType;                                                                    
        if(CheckType=="P"||CheckType=="p")
            gamemode='P';
        else if(CheckType=="D"||CheckType=="d")
            gamemode='D';
        else if(CheckType=="U"||CheckType=="u")
            gamemode='U';
        else
            cerr<<"Unexpected input"<<endl;
    }
    if(gamemode=='P'){
        ConnectFourPlus yunus;
            while(yunus.getplayeble()==true){
        yunus.playGame(); 
    }
    }
    else if(gamemode=='U'){
        ConnectFourPlusUndo yunus;
            while(yunus.getplayeble()==true){
        yunus.playGame(); 
    }
    }
    else if(gamemode=='D'){
        ConnectFourDiag yunus;
            while(yunus.getplayeble()==true){
        yunus.playGame(); 
    }
    }
    

    
    return(0);
}