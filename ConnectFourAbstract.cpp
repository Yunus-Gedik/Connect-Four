//ConnectFourAbstract.cpp
//Yunus_Gedik
//141044026

#include "ConnectFourAbstract.h"
#include <iostream>
#include <fstream>
using namespace std;

//private:
        void ConnectFourAbstract::mallocer(void){                                        //Sizes the vector< vector<Cell> >.
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
                
        bool ConnectFourAbstract::IsEmpty(int i,int j){                                  //Returns true if the cell is empty.
            return(b[i][j].getvalue()=='.' ? true : false);
        }
        
        int ConnectFourAbstract::Filler(char player){                                    //Fills the choosen column.
            int i,j=temp[0]-'a';
            for(i=(width-1);i>=0;i--){
                if(IsEmpty(i,j)){
                    b[i][j].setcell(i,j,player);
                    return(0);
                }
            }
        }
        
        bool ConnectFourAbstract::play(void){                                            //Plays for the computer.
            
            if(gametype=='C'){
                cout<<"Computer's turn."<<endl;
                Display();
                for(i=width-1;i>=0;i--){
                    for(j=height-1;j>=0;j--){
                        if(i<width&&(j+3)<height){
                            if(b[i][j].getvalue()=='O'&&b[i][j+1].getvalue()=='O'&&b[i][j+2].getvalue()=='O'&&b[i][j+3].getvalue()=='.'){ 
                                if(i==(width-1)||b[i+1][j+3].getvalue()!='.'){
                                    b[i][j+3].setcell(i,j+3,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i+3)<width&&j<height){
                            if(b[i][j].getvalue()=='O'&&b[i+1][j].getvalue()=='O'&&b[i+2][j].getvalue()=='O'&&b[i+3][j].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j].getvalue()!='.'){
                                    b[i+1][j].setcell(i+3,j,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i+3)<width&&(j+3)<height){
                            if(b[i][j].getvalue()=='O'&&b[i+1][j+1].getvalue()=='O'&&b[i+2][j+2].getvalue()=='O'&&b[i+3][j+3].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j+3].getvalue()!='.'){
                                    b[i+3][j+3].setcell(i+3,j+3,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i-3)>0&&(j-3)>=0){
                            if(b[i][j].getvalue()=='O'&&b[i-1][j-1].getvalue()=='O'&&b[i-2][j-2].getvalue()=='O'&&b[i-3][j-3].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j-3].getvalue()!='.'){
                                    b[i-3][i-3].setcell(i-3,j-3,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i-3)>=0&&j<height){
                            if(b[i][j].getvalue()=='O'&&b[i-1][j].getvalue()=='O'&&b[i-2][j].getvalue()=='O'&&b[i-3][j].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j].getvalue()!='.'){
                                    b[i-3][j].setcell(i-3,j,'O');
                                    return(true);
                                }
                            }
                        }
                        if(i<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='O'&&b[i][j-1].getvalue()=='O'&&b[i][j-2].getvalue()=='O'&&b[i][j-3].getvalue()=='.'){
                                if(i==(width-1)||b[i+1][j-3].getvalue()!='.'){
                                    b[i][j-3].setcell(i,j-3,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i+3)<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='O'&&b[i+1][j-1].getvalue()=='O'&&b[i+2][j-2].getvalue()=='O'&&b[i+3][j-3].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j-3].getvalue()!='.'){
                                    b[i+3][j-3].setcell(i+3,j-3,'O');
                                    return(true);
                                }
                            }
                        }
                        if((i-3)>=0&&(j+3)<height){
                            if(b[i][j].getvalue()=='O'&&b[i-1][j+1].getvalue()=='O'&&b[i-2][j+2].getvalue()=='O'&&b[i-3][j+3].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j+3].getvalue()!='.'){
                                    b[i-3][j+3].setcell(i-3,j+3,'O');
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
                                    Display();
                                    return(false);
                                }
                            }
                        }
                        if((i+3)<width&&j<height){
                            if(b[i][j].getvalue()=='X'&&b[i+1][j].getvalue()=='X'&&b[i+2][j].getvalue()=='X'&&b[i+3][j].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j].getvalue()!='.'){
                                    b[i+3][j].setcell(i+3,j,'O');
                                    Display();
                                    return(false);
                                }
                            }
                        }
                        if((i+3)<width&&(j+3)<height){
                            if(b[i][j].getvalue()=='X'&&b[i+1][j+1].getvalue()=='X'&&b[i+2][j+2].getvalue()=='X'&&b[i+3][j+3].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j+3].getvalue()!='.'){
                                    b[i+3][j+3].setcell(i+3,j+3,'O');
                                    Display();
                                    return(false);
                                }
                            }
                       }
                        if((i-3)>=0&&(j-3)>=0){
                            if(b[i][j].getvalue()=='X'&&b[i-1][j-1].getvalue()=='X'&&b[i-2][j-2].getvalue()=='X'&&b[i-3][j-3].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j-3].getvalue()!='.'){
                                    b[i-3][j-3].setcell(i-3,j-3,'O');
                                    Display();
                                    return(false);}
                            }
                        }
                        if((i-3)>=0&&j<height){
                            if(b[i][j].getvalue()=='X'&&b[i-1][j].getvalue()=='X'&&b[i-2][j].getvalue()=='X'&&b[i-3][j].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j].getvalue()!='.'){
                                    b[i-3][j].setcell(i-3,j,'O');
                                    Display();
                                    return(false);}
                            }
                        }
                        if(i<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='X'&&b[i][j-1].getvalue()=='X'&&b[i][j-2].getvalue()=='X'&&b[i][j-3].getvalue()=='.'){
                                if(i==(width-1)||b[i+1][j-3].getvalue()!='.'){
                                    b[i][j-3].setcell(i,j-3,'O');
                                    Display();
                                    return(false);}
                            }
                        }
                        if((i+3)<width&&(j-3)>=0){
                            if(b[i][j].getvalue()=='X'&&b[i+1][j-1].getvalue()=='X'&&b[i+2][j-2].getvalue()=='X'&&b[i+3][j-3].getvalue()=='.'){
                                if((i+3)==(width-1)||b[i+4][j-3].getvalue()!='.'){
                                    b[i+3][j-3].setcell(i+3,j-3,'O');
                                    Display();
                                    return(false);}
                            }
                        }
                        if((i-3)>=0&&(j+3)<height){
                            if(b[i][j].getvalue()=='X'&&b[i-1][j+1].getvalue()=='X'&&b[i-2][j+2].getvalue()=='X'&&b[i-3][j+3].getvalue()=='.'){
                                if((i-3)==(width-1)||b[i-2][j+3].getvalue()!='.'){
                                    b[i-3][j+3].setcell(i-3,j+3,'O');
                                    Display();
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
                            Display();
                            return(false);
                        }
                    }
                }
            
                Display();
            }
            return(false);
        }
        
        bool ConnectFourAbstract::play(char position){                                   //Plays for the player.
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
                        Filler('X');
                    }
                }

                if(!AnyEmpty()){
                    return(false);
                }
                
                if(turn!=1){
                    cout<<"Player 2's turn."<<endl;
                    if(LetterTaker()){
                        turn=1;
                        Filler('O');
                    }
                }
                Display();
            }
            
            return(true);
            
        }
        
        bool ConnectFourAbstract::AnyEmpty(void){                                        //Checks if there is any empty cell to fill.
            for(int i=0;i<width;i++){
                for(int j=0;j<height;j++){
                    if(b[i][j].getvalue()=='.')
                        return(true);
                }
            }
            return(false);
        }
        
        bool ConnectFourAbstract::LetterTaker(void){                                     //Lets the user choose a column to instert or save/load.
            int strlen;
            int csize=height;
            char controlletter='a';
            Display();
            cout<<"Choose a column to fill by using the letters over the board or save/load game."<<endl;
            cin>>temp;
            while(csize>0){
                cin.clear();
                cin.ignore(10000,'\n');
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
        
        bool ConnectFourAbstract::AnyEmptyInColumn(void){                                //Returns true if are there any empty cell to fill in a specific column.
            int i=0,n=0;
            
            for(int i=0;i<width;++i){
                if(b[i][(tolower(temp[0]))-'a'].getvalue()!='.'){
                    n++;
                }
            }
            
            if(n==width){
                return(false);
            }
            else{
                return(true);
            }
        }
        
        void ConnectFourAbstract::takesizes(int i){                                //Assigns width and height.
            do{
                cin.clear();
                cin.ignore(10000,'\n');
                if(i==1){
                    cout<<"Input the height:"<<endl;
                    cin>>height;}
                else{
                    cout<<"Input the width:"<<endl;
                    cin>>width;}
                if(cin.fail()){cerr<<"Unexpected input!"<<endl;}                                  
            }while(cin.fail());
            cin.clear();
        }
        
//public:
        
        void ConnectFourAbstract::Display(void){                                         //Display the game to the console.
            int csize=height;
            char harf='a';
            while(csize>0){
                cout<<harf<<' ';
                csize--;
                harf++;
            }
            cout<<endl;
            
            for(i=0;i<width;++i){
                for(j=0;j<height;++j){
                    cout<<b[i][j].getvalue()<<" ";
                }
                cout<<endl;
            }
        }
        
        void ConnectFourAbstract::save(void){                                            //Saves the game to the txt file.
            ofstream dosya;
            dosya.open(temp.c_str());
            dosya<<width<<endl<<height<<endl<<gametype<<endl<<turn<<endl;

            for(i=0;i<width;i++){
                for(j=0;j<height;j++){
                    dosya<<b[i][j].getvalue();
                }
                dosya<<endl;
            }
            dosya.close();
        }

        void ConnectFourAbstract::load(void){                                            //Loads the game from the txt file.
            ifstream dosya;
            char t;
            dosya.open(temp.c_str());
            dosya>>width>>height>>gametype>>turn;
            
            mallocer();
                
            
            for(i=0;i<width;i++){
                for(j=0;j<height;j++){
                    dosya>>t;
                    b[i][j].setcell(i,j,t);
                }
            }
            dosya.close();
        }
        
        bool ConnectFourAbstract::playGame(void){                                        //Plays the game.
            play(gametype);
                
            if(Four()){
                PLAYEBLE=false;
                return(true);
            }
            else if(!AnyEmpty()){
                Display();
                cerr<<"Game has finished.There is no more empty cell to fill."<<endl;
                PLAYEBLE=false;
                return(true);
            }
            
            play();
            
            if(Four()==true){
                PLAYEBLE=false;
                return(true);
            }
            else if(!AnyEmpty()){
                Display();
                cerr<<"Game has finished.There is no more empty cell to fill."<<endl;
                PLAYEBLE=false;
                return(true);
            }

        return(true);
        }
        
        bool ConnectFourAbstract::getplayeble(void){return(PLAYEBLE);}                   //Returns if game is still playeble or not.
        
        int ConnectFourAbstract::livingcell(void){                                       //Livincell:number of filled cells
            int lcell=0;
            for(i=width-1;i>=0;--i){
                for(j=height-1;j>=0;--j){
                    if(b[i][j].getvalue()=='O'||b[i][j].getvalue()=='X'){
                        ++lcell;
                    }
                }
            }
            return(lcell);
        }
        
        int ConnectFourAbstract::getheight(void){                                        //Returns height.
            return(height);
        }
        
        int ConnectFourAbstract::getwidth(void){                                         //Returns width.
            return(width);
        }
        
