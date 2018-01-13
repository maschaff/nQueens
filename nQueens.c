#include <stdio.h>
#include <stdlib.h>


int numSolutions = 0;

void printSolution(int dim, int rows[], int cols[]){
    int i, j;

    for(i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            if(rows[j] == cols[i]){
                printf("%c%d", i+97, j+1);
            }
        }
    }

    printf("\n");
    return;
}

void recQueenSolver(int dim, int col, int rows[], int cols[], int slash[], int backslash[]){

    if(col == dim){
        printSolution(dim, rows, cols);
        numSolutions++;
        return;
    }

    int row;

    for(row = 0; row < dim; row++){

        //check if safe to place queen
        if(rows[row] == 0 && slash[row + col] == 0 && backslash[row-col+(dim-1)] == 0){

            //set placement details
            rows[row] = col+1;
            cols[col] = col+1;
            slash[row + col] = col+1;
            backslash[row-col+(dim-1)] = col+1;
            
            //continue solving recursively
            recQueenSolver(dim, col+1, rows, cols, slash, backslash);

            //remove placement details
            rows[row] = 0;
            cols[col] = 0;
            slash[row + col] = 0;
            backslash[row-col+(dim-1)] = 0;
        }
    }

    return;
}

void nQueensSolver(int n){
    int rows[n];
    int cols[n];
    int slash[n*2-1];
    int backslash[n*2-1];

    //initialize arrays to 0
    int i;
    for(i = 0; i < n*2-1; i++){
        if(i < n){
            rows[i] = 0;
            cols[i] = 0;
        }

        slash[i] = 0;
        backslash[i] = 0;
    }

    recQueenSolver(n, 0, rows, cols, slash, backslash);
    printf("Found %d solutions to %d Queen problem.", numSolutions, n);
    return;
}


int main(int argc, char *argv[]){

    if(argc > 1){
        nQueensSolver(atoi(argv[1]));
    } else {
        printf("No dimension specified. Running 8 Queen solver.\n");
        nQueensSolver(8);
    }

    return 0;
}