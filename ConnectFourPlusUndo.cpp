//ConnectFourPlusUndo.cpp
//Yunus_Gedik
//141044026

#include "ConnectFourPlusUndo.h"

#include <fstream>
#include <iostream>

using namespace std;

bool ConnectFourPlusUndo::Four(void){                                      //Checks if the game has finished or not.
        
            for(int i=width-1;i>=0;i--){
                for(int j=height-1;j>=0;j--){
                    if(i<width&&(j+3)<height){
                        if(b[i][j].getvalue()=='O'&&b[i][j+1].getvalue()=='O'&&b[i][j+2].getvalue()=='O'&&b[i][j+3].getvalue()=='O'){       
                            b[i][j].setcell(i,j,'o');b[i][j+1].setcell(i,j,'o');b[i][j+2].setcell(i,j,'o');b[i][j+3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }
                    if((i+3)<width&&j<height){
                        if(b[i][j].getvalue()=='O'&&b[i+1][j].getvalue()=='O'&&b[i+2][j].getvalue()=='O'&&b[i+3][j].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i+1][j].setcell(i,j,'o');b[i+2][j].setcell(i,j,'o');b[i+3][j].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }


                    if((i-3)>=0&&j<height){
                        if(b[i][j].getvalue()=='O'&&b[i-1][j].getvalue()=='O'&&b[i-2][j].getvalue()=='O'&&b[i-3][j].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i-1][j].setcell(i,j,'o');b[i-2][j].setcell(i,j,'o');b[i-3][j].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                    if(i<width&&(j-3)>=0){
                        if(b[i][j].getvalue()=='O'&&b[i][j-1].getvalue()=='O'&&b[i][j-2].getvalue()=='O'&&b[i][j-3].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i][j-1].setcell(i,j,'o');b[i][j-2].setcell(i,j,'o');b[i][j-3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                }
            }

            for(int i=width-1;i>=0;i--){
                for(int j=height-1;j>=0;j--){
                    if(i<width&&(j+3)<height){
                        if(b[i][j].getvalue()=='X'&&b[i][j+1].getvalue()=='X'&&b[i][j+2].getvalue()=='X'&&b[i][j+3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i][j+1].setcell(i,j,'x');b[i][j+2].setcell(i,j,'x');b[i][j+3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }
                    if((i+3)<width&&j<height){
                        if(b[i][j].getvalue()=='X'&&b[i+1][j].getvalue()=='X'&&b[i+2][j].getvalue()=='X'&&b[i+3][j].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i+1][j].setcell(i,j,'x');b[i+2][j].setcell(i,j,'x');b[i+3][j].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }
                    if((i-3)>=0&&j<height){
                        if(b[i][j].getvalue()=='X'&&b[i-1][j].getvalue()=='X'&&b[i-2][j].getvalue()=='X'&&b[i-3][j].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i-1][j].setcell(i,j,'x');b[i-2][j].setcell(i,j,'x');b[i-3][j].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                    if(i<width&&(j-3)>=0){
                        if(b[i][j].getvalue()=='X'&&b[i][j-1].getvalue()=='X'&&b[i][j-2].getvalue()=='X'&&b[i][j-3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i][j-1].setcell(i,j,'x');b[i][j-2].setcell(i,j,'x');b[i][j-3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                }
            }

        return(false);
    
}

bool ConnectFourPlusUndo::LetterTaker(void){                               //Lets the user choose a column to instert or save/load/undo.
            int strlen;
            int csize=height;
            char controlletter='a';
            Display();
            cout<<"Choose a column to fill by using the letters over the board or save/load game/undo the last step."<<endl;
            cin>>temp;
            while(csize>0){
                cin.clear();
                if(temp=="save"||temp=="SAVE"){
                    while(1){
                        getline(cin,temp);
                        strlen=temp.size();
                        if(tolower(temp[strlen-1])=='t'&&tolower(temp[strlen-2])=='x'&&tolower(temp[strlen-3])=='t'&&tolower(temp[strlen-4])=='.'){
                            save();
                            cout<<"Game saved to "<<temp<<"."<<endl;
                            return(false);
                        }
                        else{
                            cin.clear();
                            cin.ignore(10000,'\n');
                            cerr<<"Unexpected input!Input a file name like; ABC.TXT."<<endl;
                        }
                    }
                }
                
                else if(temp=="load"||temp=="LOAD"){
                    while(1){
                        getline(cin,temp);
                        strlen=temp.size();
                        if(tolower(temp[strlen-1])=='t'&&tolower(temp[strlen-2])=='x'&&tolower(temp[strlen-3])=='t'&&tolower(temp[strlen-4])=='.'){
                            load();
                            cout<<"Game loaded from "<<temp<<"."<<endl;
                            return(false);
                        }
                        else{
                            cin.clear();
                            cin.ignore(10000,'\n');
                            cerr<<"Unexpected input!Input a file name like; ABC.TXT."<<endl;
                        }
                    }
                }
                
                else if(temp=="UNDO"||temp=="undo"){
                    //Above line gets the parameters from the Undos 2d array(last played step).
                    if(Undosize==0){
                        cerr<<"Unexpected input!"<<endl;
                        csize=height;
                        controlletter='a';
                        cin>>temp;
                    }
                    else{
                        b[Undos[Undosize-1][0]][Undos[Undosize-1][1]].setcell(Undos[Undosize-1][0],Undos[Undosize-1][1],'.');
                        Undos[Undosize-1][0]=-1;                                            
                        Undos[Undosize-1][1]=-1;
                        Undosize-=1;
                        return(true);
                    }
                }
                
                strlen=temp.size();
                if(strlen!=1){
                    csize=width;
                    controlletter='a';
                    cin.clear();
                    cin.ignore(10000,'\n');
                    cerr<<"Unexpected input!"<<endl;
                }
                
                else{
                    while(csize>0){
                        if(tolower(temp[0])==controlletter){
                            temp[0]=controlletter;
                            csize=-1;
                        }
                        else{
                            --csize;
                            ++controlletter;

                        }
                    }
                    
                    if(csize==0){
                        cerr<<"Unexpected input!"<<endl;
                        csize=height;
                        controlletter='a';

                    }
                    else{
                        if(!AnyEmptyInColumn()){
                            cerr<<"Unexpected input!"<<endl;
                            csize=height;
                            controlletter='a';
                            cin>>temp;
                        }
                        
                    }
                }
            }
            return(true);
    
}

void ConnectFourPlusUndo::save(void){                                      //Saves the game to the txt file with steps have played.
    ofstream dosya;
    dosya.open(temp.c_str());
    dosya<<width<<endl<<height<<endl<<gametype<<endl<<turn<<endl<<Undosize<<endl;

    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            dosya<<b[i][j].getvalue();
        }
        dosya<<endl;
    }
    for(i=0;i<Undosize;++i){
        dosya<<Undos[i][0]<<" "<<Undos[i][1]<<endl;
    }
    dosya.close();
}         

void ConnectFourPlusUndo::load(void){                                      //Loads the game from the txt file with steps have played.
    ifstream dosya;
    char t;
    dosya.open(temp.c_str());
    dosya>>width>>height>>gametype>>turn>>Undosize;
    
    mallocer();
    
    for(i=0;i<width;i++){
        for(j=0;j<height;j++){
            dosya>>t;
            b[i][j].setcell(i,j,t);
        }
    }
    for(i=0;i<Undosize;++i){
        dosya>>Undos[i][0];
        dosya>>Undos[i][1];
    }
    dosya.close();
}

void ConnectFourPlusUndo::mallocer(void){                                  //Sizes the board.
    cout<<"SELAM BEN UNDODAN MALLOCER"<<endl;
    Undos=new int*[width*height];
    for(i = 0; i < (width*height); ++i){
        Undos[i] = new int[2];
    }
    for(i = 0; i < (width*height); ++i){                                   
        Undos[i][0]=-1;
        Undos[i][1]=-1;
    }
    
    
    
    b = new Cell*[width];
    for(i = 0; i < width; ++i){
        b[i] = new Cell[height];
    }
    for(i=width-1;i>=0;--i){
        for(j=height-1;j>=0;--j){
            b[i][j].setcell(i,j,'.');
        }
    }
}

ConnectFourPlusUndo::~ConnectFourPlusUndo(){                               //Deallocates.
    for(int i = 0; i < (height*width); ++i) {
        delete[] Undos[i];   
    }
    delete[] Undos;
}

ConnectFourPlusUndo::ConnectFourPlusUndo(){                                //Allocates Undos array which carries the played steps and gameboard.
            string CheckType="";
            takesizes(0);                                                               //Gets height.
            takesizes(1);                                                               //Gets width.
            mallocer();
            
            while(CheckType!="P"&&CheckType!="C"&&CheckType!="c"&&CheckType!="p"){              //game type
                cout<<"'P' to player to player,'C' to player to computer"<<endl;
                cin>>CheckType;
                if(CheckType=="P"||CheckType=="p")
                    gametype='P';
                else if(CheckType=="C"||CheckType=="c")
                    gametype='C';
                else
                    cerr<<"Unexpected input"<<endl;
            
            }
}

int ConnectFourPlusUndo::Filler(char player){                              //Fills a dot in board and also filss the Undos array.
    int i,j=temp[0]-'a';
    for(i=(width-1);i>=0;i--){
        if(IsEmpty(i,j)){
            b[i][j].setcell(i,j,player);
            Undos[Undosize][0]=i;
            Undos[Undosize][1]=j;
            Undosize+=1;
            return(0);
        }
    }
}

bool ConnectFourPlusUndo::play(void){                                      //Plays for the computer and add a a step to Undos array.
                                    
            if(gametype=='C'){
                cout<<"Computer's turn."<<endl;
                Display();
                for(i=width-1;i>=0;i--){
                    for(j=height-1;j>=0;j--){
                        if(i<width&&(j+3)<height){
                            if(b[i][j].getvalue()=='O'&&b[i][j+1].getvalue()=='O'&&b[i][j+2].getvalue()=='O'&&b[i][j+3].getvalue()=='.'){ 
                                if(i==(width-1)||b[i+1][j+3].getvalue()!='.'){
                                    b[i][j+3].setcell(i,j+3,'O');
                                    Undos[Undosize][0]=i;
                                    Undos[Undosize][1]=j+3;
                                    Undosize+=1;
                                    return(true);
                                }
                            }
                        }
                        if((i+3)<width&&j<height){
                            if(b[i][j].getvalue()=='O'&&b[i+1][j].getvalue()=='O'&&b[i+2][j].getvalue()=='O'&&b[i+3][j].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j].getvalue()!='.'){
                                    b[i+3][j].setcell(i+3,j,'O');
                                    Undos[Undosize][0]=i+3;
                                    Undos[Undosize][1]=j;
                                    Undosize+=1;
                                    return(true);
                                }
                            }
                        }

                        if((i-3)>=0&&j<height){
                            if(b[i][j].getvalue()=='O'&&b[i-1][j].getvalue()=='O'&&b[i-2][j].getvalue()=='O'&&b[i-3][j].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j].getvalue()!='.'){
                                    b[i-3][j].setcell(i-3,j,'O');
                                    Undos[Undosize][0]=i-3;
                                    Undos[Undosize][1]=j;
                                    Undosize+=1;
                                    return(true);
                                }
                            }
                        }
                        if(i<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='O'&&b[i][j-1].getvalue()=='O'&&b[i][j-2].getvalue()=='O'&&b[i][j-3].getvalue()=='.'){
                                if(i==(width-1)||b[i+1][j-3].getvalue()!='.'){
                                    b[i][j-3].setcell(i,j-3,'O');
                                    Undos[Undosize][0]=i;
                                    Undos[Undosize][1]=j-3;
                                    Undosize+=1;
                                    return(true);
                                }
                            }
                        }
                    }
                }
                
                for(i=width-1;i>=0;i--){
                    for(j=height-1;j>=0;j--){
                        if(i<width&&(j+3)<height){
                            if(b[i][j].getvalue()=='X'&&b[i][j+1].getvalue()=='X'&&b[i][j+2].getvalue()=='X'&&b[i][j+3].getvalue()=='.'){
                                if(i==(width-1)||b[i+1][j+3].getvalue()!='.'){
                                    b[i][j+3].setcell(i,j+3,'O');
                                    Undos[Undosize][0]=i;
                                    Undos[Undosize][1]=j+3;
                                    Undosize+=1;
                                    return(false);
                                }
                            }
                        }
                        if((i+3)<width&&j<height){
                            if(b[i][j].getvalue()=='X'&&b[i+1][j].getvalue()=='X'&&b[i+2][j].getvalue()=='X'&&b[i+3][j].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j].getvalue()!='.'){
                                    b[i+3][j].setcell(i+3,j,'O');
                                    Undos[Undosize][0]=i+3;
                                    Undos[Undosize][1]=j;
                                    Undosize+=1;
                                    return(false);
                                }
                            }
                        }
                        if((i-3)>=0&&j<height){
                            if(b[i][j].getvalue()=='X'&&b[i-1][j].getvalue()=='X'&&b[i-2][j].getvalue()=='X'&&b[i-3][j].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j].getvalue()!='.'){
                                    b[i-3][j].setcell(i-3,j,'O');
                                    Undos[Undosize][0]=i-3;
                                    Undos[Undosize][1]=j;
                                    Undosize+=1;
                                    return(false);}
                            }
                        }
                        if(i<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='X'&&b[i][j-1].getvalue()=='X'&&b[i][j-2].getvalue()=='X'&&b[i][j-3].getvalue()=='.'){
                                if(i==(width-1)||b[i+1][j-3].getvalue()!='.'){
                                    b[i][j-3].setcell(i,j-3,'O');
                                    Undos[Undosize][0]=i;
                                    Undos[Undosize][1]=j-3;
                                    Undosize+=1;
                                    return(false);}
                            }
                        }
                    }
                }
            
                while(1){
                    srand(time(NULL));
                    j=(rand())%height;
                    for(i=width-1;i>=0;i--){
                        if(IsEmpty(i,j)){
                            b[i][j].setcell(i,j,'O');
                            Undos[Undosize][0]=i;
                            Undos[Undosize][1]=j;
                            Undosize+=1;
                            return(false);
                        }
                    }
                }
                
                
            }
            return(false);
}

bool ConnectFourPlusUndo::play(char position){                             //This function has overrided cause we also need to undo the current player.
            if(gametype=='C'){
                cout<<"Player's turn."<<endl;
                if(LetterTaker()){
                    Filler('X');
                }
            }
            
            else{
                if(turn==1){
                    cout<<"Player 1's turn."<<endl;
                    if(LetterTaker()){
                        turn=2;
                        if(temp!="UNDO"&&temp!="undo"){
                            Filler('X');
                        }
                    }
                }

                if(!AnyEmpty()){
                    return(false);
                }
                
                if(turn!=1){
                    cout<<"Player 2's turn."<<endl;
                    if(LetterTaker()){
                        turn=1;
                        if(temp!="UNDO"&&temp!="undo"){
                            Filler('O');
                        }
                    }
                }
                Display();
            }
}

