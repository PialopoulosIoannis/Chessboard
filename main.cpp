#include "chessboardarray.h"
#include <iostream>

int main() { 
    ChessBoardArray a(4, 1); // size 4x4, rows and columns numbered from 1 
    a[3][1] = 42; 
    a[4][4] = 17; 
    try { a[2][1] = 7; } 
    catch(out_of_range &e) { std::cout << "a[2][1] is black" << std::endl; } 
    try { std::cout << a[1][2] << std::endl; } 
    catch(out_of_range &e) { std::cout << "and so is a[1][2]" << std::endl; } 
    std::cout << a; 
}
