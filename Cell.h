//Cell.h
//Yunus_Gedik
//141044026


class Cell{
    private:  
        int column;
        int row;
        char value;
        int celltype=0;            
                
    public:
        Cell();
        void setcell(int c,int r,char v);
        int getrow();
        int getcolumn();
        char getvalue();
        int getcelltype();
};