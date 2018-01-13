#include <stdio.h>
#include <stdlib.h>

void nQueensSolver(int n){
    printf("%d", n);
    return;
}

int main(int argc, char *argv[]){

    if(argc > 1){
        nQueensSolver(atoi(argv[1]));
    } else {
        printf("Please enter a number n to specify board dimensions.\n");
    }

    return 0;
}