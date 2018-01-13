# N Queens Solution

This is a solution to the N Queens Problem where the solution for a chessboard of dimension N x N is the placement of N number of Queens in such a way that none of them can atack any of each other. In other words, no two pieces share the same row, column, or diagonal. My solution solves the problem recursively by keeping track of which rows, columns, and diagonals have been taken already, and placing pieces in the remaining open, safe spots. If the function is able to place N number of pieces on the board then it has found a solution. The time required to solve the problem scales rapidly, so boards where N is greater than 12 may take some time to complete. For example, a 12 Queen solution can be generated in 2-3 seconds, while and 14 Queen solution takes 30+ seconds to finish.

## Compiling and Running
    
Once installed, the program can be compiled by calling the make command. 
```
make
```

To run, simply call the binary nQueens followed by an integer N representing the dimension of the board to be solved.

```
./nQueens 8
```