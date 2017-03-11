#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#define ROWS 5
#define COLS 5

int main(){
    int **matrix=malloc(ROWS*sizeof(int*));  // Pointer to a pointer. Malloc 5 times the size of a pointer integer
    if(!matrix){  // Check if it was allocated successfully
        return 1;
    }

    for(int i=0;i<ROWS;i++){
        matrix[i]=malloc(COLS*sizeof(int));  // Malloc 5 integer spaces(we will put aour columns there)
        if(!matrix[i]){  // Check if it was allocated successfully
            return 1;
        }
    }

    int row, col, count=1;
    for(row=0;row<ROWS;row++){  // Now start filling the matrix
        for(col=0;col<COLS;col++, count++){
            matrix[row][col]=count;
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }

    for(row=0;row<ROWS;row++){
        free(matrix[row]);  // Free every row
    }

    free(matrix); // free the main variable

    return 0;
}
