//Cell.cpp
//Yunus_Gedik
//141044026

#include "Cell.h"

using namespace std;

        Cell::Cell(){
            row=0;column=0;value='.';}
        void Cell::setcell(int c,int r,char v){
            row=r;column=c;value=v;}
        int Cell::getrow(){return(row);}
        int Cell::getcolumn(){return(column);}
        char Cell::getvalue(){return(value);}
        int Cell::getcelltype(){return(celltype);}
