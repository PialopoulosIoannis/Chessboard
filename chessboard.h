#ifndef CHESSBOARDARRAY_H
#define CHESSBOARDARRAY_H
#include <iostream>  
#include <iomanip>  
using namespace std;  
#include <stdexcept>  
  
  
  
class ChessBoardArray {  
private:  
    int * c;  
    int mybase;  
    int mysize;  
    unsigned int loc(int i, int j) const {  
        int k;  
        int b[mysize+mybase][mysize+mybase];  
  
        int l=1;  
        if (mysize%2==1) {  
            for (int i=mybase; i<mysize+mybase; i++) {  
                for (int j=mybase; j<mysize+mybase; j++) {  
                    b[i][j]=(l++)%2;  
                }  
            }  
        }  
        else { for (int i=mybase; i<mysize+mybase; i++) {  
            if (i!=mybase) l++;  
            for (int j=mybase; j<mysize+mybase; j++) {  
                b[i][j]=(l++)%2; //cout<<b[i][j]<<" ";  
            }  
        }}  
        if (b[i][j]==1) {  
            k= ((mysize*(i-mybase)+j-mybase)/2);  
            return k;  
        }  
        throw out_of_range("black spot");  
    }  
protected:  
    class Row {  
    public:  
        Row( ChessBoardArray &a, int i) { mychess=&a; row=i;}  
  
        Row(const ChessBoardArray & a, int i);  
  
        int & operator [] (int i) const {int h=mychess->loc(row,i); return mychess->c[h];}  
    private:  
        ChessBoardArray *mychess;  
        int row;  
    };  
    class ConstRow {  
    public:  
        ConstRow( const ChessBoardArray &a, int i) { mychess=&a; row=i;}  
        int operator [] (int i) const {int h=mychess->loc(row,i); return mychess->c[h];}  
    private:  
        const ChessBoardArray *mychess;  
        int row;  
    };  
public:  
    ChessBoardArray(unsigned size = 0, unsigned base = 0) {  
        c= new int[((size*size)/2) + size%2];  
        mybase=base;  
        mysize=size;  
        for (int i=0;i<((size*size)/2) +size%2;i++) c[i]=0;  
  
  
    }  
    ChessBoardArray(const ChessBoardArray &a) {  
        mybase=a.mybase; mysize=a.mysize;  
        c= new int[((mysize*mysize)/2) +mysize%2];  
        for (int i=0;i<(((mysize*mysize)/2)+mysize%2 );i++) c[i]=a.c[i];  
  
    }  
    ~ChessBoardArray() { delete[] c;}  
  
    ChessBoardArray & operator = (const ChessBoardArray &a) {  
        delete [] c;  
        mybase=a.mybase; mysize=a.mysize;  
        c= new int[((mysize*mysize)/2)+(mysize%2)];  
        for (int i=0;i<((mysize*mysize)/2)+(mysize%2);i++) c[i]=a.c[i];  
        return *this;  
    }  
  
    int & select(int i, int j) {  
        return c[loc(i,j)];  
    }  
    int select(int i, int j) const  {  
        return c[loc(i,j)];  
    }  
    const Row operator [] (int i) { return Row(*this,i);}  
    const ConstRow operator [] (int i) const { return ConstRow(*this,i);}  
    friend ostream & operator << (ostream &out, const ChessBoardArray &a) {  
        for (int i=a.mybase; i<a.mysize+a.mybase; i++) {  
            if (i!=a.mybase) cout<<endl;  
            for (int j=a.mybase; j<a.mysize+a.mybase; j++) {  
                try { cout<<setw(4)<<a[i][j]; }  
                catch(out_of_range &e) { cout << setw(4)<<"0" ; }  
            }  
        } if (a.mysize!=0) out<<endl;  
        return out;  
    }  
};  

#endif
  
/* 
int main() { 
    ChessBoardArray a(4, 1); // size 4x4, rows and columns numbered from 1 
    a[3][1] = 42; 
    a[4][4] = 17; 
    try { a[2][1] = 7; } 
    catch(out_of_range &e) { cout << "a[2][1] is black" << endl; } 
    try { cout << a[1][2] << endl; } 
    catch(out_of_range &e) { cout << "and so is a[1][2]" << endl; } 
    //  cout<< a[3][1]<<" "<<a[4][4]; 
    cout << a; 
} 
 
*/  
