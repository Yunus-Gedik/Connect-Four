//ConnectFourPlus.cpp
//Yunus_Gedik
//141044026

#include "ConnectFourDiag.h"

#include <iostream>

using namespace std;

bool ConnectFourDiag::Four(void){                                    //Checks if the game has finished or not.

            for(int i=width-1;i>=0;i--){
                for(int j=height-1;j>=0;j--){
                    if((i+3)<width&&(j+3)<height){
                        if(b[i][j].getvalue()=='O'&&b[i+1][j+1].getvalue()=='O'&&b[i+2][j+2].getvalue()=='O'&&b[i+3][j+3].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i+1][j+1].setcell(i,j,'o');b[i+2][j+2].setcell(i,j,'o');b[i+3][j+3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }
                    if((i-3)>0&&(j-3)>=0){
                        if(b[i][j].getvalue()=='O'&&b[i-1][j-1].getvalue()=='O'&&b[i-2][j-2].getvalue()=='O'&&b[i-3][j-3].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i-1][j-1].setcell(i,j,'o');b[i-2][j-2].setcell(i,j,'o');b[i-3][j-3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }

                    if((i+3)<width&&(j-3)>=0){
                        if(b[i][j].getvalue()=='O'&&b[i+1][j-1].getvalue()=='O'&&b[i+2][j-2].getvalue()=='O'&&b[i+3][j-3].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i+1][j-1].setcell(i,j,'o');b[i+2][j-2].setcell(i,j,'o');b[i+3][j-3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                    if((i-3)>=0&&(j+3)<height){
                        if(b[i][j].getvalue()=='O'&&b[i-1][j+1].getvalue()=='O'&&b[i-2][j+2].getvalue()=='O'&&b[i-3][j+3].getvalue()=='O'){
                            b[i][j].setcell(i,j,'o');b[i-1][j+1].setcell(i,j,'o');b[i-2][j+2].setcell(i,j,'o');b[i-3][j+3].setcell(i,j,'o');
                            cout<<"Player 2 (may be the computer) won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                }
            }

            for(int i=width-1;i>=0;i--){
                for(int j=height-1;j>=0;j--){
                    if((i+3)<width&&(j+3)<height){
                        if(b[i][j].getvalue()=='X'&&b[i+1][j+1].getvalue()=='X'&&b[i+2][j+2].getvalue()=='X'&&b[i+3][j+3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i+1][j+1].setcell(i,j,'x');b[i+2][j+2].setcell(i,j,'x');b[i+3][j+3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);
                        }
                    }
                    if((i-3)>=0&&(j-3)>=0){
                        if(b[i][j].getvalue()=='X'&&b[i-1][j-1].getvalue()=='X'&&b[i-2][j-2].getvalue()=='X'&&b[i-3][j-3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i-1][j-1].setcell(i,j,'x');b[i-2][j-2].setcell(i,j,'x');b[i-3][j-3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            cout<<"Choose a column to fill by using the letters over the board or save/load game."<<endl;                            
                            return(true);}
                    }
                    if((i+3)<width&&(j-3)>=0){
                        if(b[i][j].getvalue()=='X'&&b[i+1][j-1].getvalue()=='X'&&b[i+2][j-2].getvalue()=='X'&&b[i+3][j-3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i+1][j-1].setcell(i,j,'x');b[i+2][j-2].setcell(i,j,'x');b[i+3][j-3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                    if((i-3)>=0&&(j+3)<height){
                        if(b[i][j].getvalue()=='X'&&b[i-1][j+1].getvalue()=='X'&&b[i-2][j+2].getvalue()=='X'&&b[i-3][j+3].getvalue()=='X'){
                            b[i][j].setcell(i,j,'x');b[i-1][j+1].setcell(i,j,'x');b[i-2][j+2].setcell(i,j,'x');b[i-3][j+3].setcell(i,j,'x');
                            cout<<"Player 1 won!"<<endl;
                            Display();
                            PLAYEBLE=false;
                            return(true);}
                    }
                }
            }

        return(false);
}

ConnectFourDiag::ConnectFourDiag(){
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

ConnectFourDiag::~ConnectFourDiag(){
            for(int i = 0; i < height; ++i) {
                delete[] b[i];   
            }
            delete[] b;
}

bool ConnectFourDiag::play(void){                                            //Plays for the computer.
            
            if(gametype=='C'){
                cout<<"Computer's turn."<<endl;
                Display();
                for(i=width-1;i>=0;i--){
                    for(j=height-1;j>=0;j--){
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