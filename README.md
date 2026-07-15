# ChessBoardArray (Σκακιέρα)

A highly memory-efficient C++ class implementation that represents a square matrix using a chessboard-style pattern. This project was developed as part of **Exercise 8 (ChessBoardArray)** for the *Programming Techniques* course at the **National Technical University of Athens (NTUA)**, School of Electrical and Computer Engineering.

---

## Technical Concept & Architecture

The `ChessBoardArray` class represents a square array where non-zero integers can only reside on cells corresponding to **white squares** of a chessboard. 

* **Memory Allocation:** To minimize memory overhead, only the white squares are allocated space in a flat, one-dimensional array ($c$). 
* **Zero Initialization:** The default constructor initializes all elements to zero.
* **Coordinate Mapping:** The private function `loc(int i, int j)` dynamically translates a 2D matrix coordinate into its corresponding flat 1D index inside the allocated array.
* **Exceptional Safety:** If an operation attempts to read or write to a coordinate mapped to a black cell, the class throws an `std::out_of_range` exception ("black spot").
* **Subscript Operator (`[][]`):** Implements dual subscripting through helper proxy classes (`Row` and `ConstRow`) to allow standard array interactions like `a[i][j]` on both mutable and constant instances.

### White Cells vs Black Cells Coordinate Layout (Size: 4x4, Base: 1)

```text
       Col 1    Col 2    Col 3    Col 4
Row 1: [White]  [Black]  [White]  [Black]   <-- Only [White] cells are stored
Row 2: [Black]  [White]  [Black]  [White]
Row 3: [White]  [Black]  [White]  [Black]
Row 4: [Black]  [White]  [Black]  [White]
