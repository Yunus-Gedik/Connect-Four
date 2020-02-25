//ConnectFourPlus.cpp
//Yunus_Gedik
//141044026

#include "ConnectFourPlus.h"
#include <iostream>

using namespace std;

bool ConnectFourPlus::Four(void){                           //Checks if the game has finished or not.
        
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

ConnectFourPlus::ConnectFourPlus(){
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

ConnectFourPlus::~ConnectFourPlus(){
            for(int i = 0; i < height; ++i) {
                delete[] b[i];   
            }
            delete[] b;
}

bool ConnectFourPlus::play(void){                           //Plays for the computer.
                                    
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