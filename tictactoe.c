#define _GNU_SOURCE  // A lot of different header files. Don't look at them.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#define ROWS 3
#define COLS 3

int main(){
    int grid[ROWS][COLS]={
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
    };

    printf("Tic-tac-toe (by Dakilla-ROSHUN)\n\n\n\n");

    int row, col, player=1, filled=0;
    while(1){
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(grid[i][j]){
                    filled++;
                }
            }
        }
        printf("\n");
        if((grid[0][0]==1 && grid[0][1]==1 && grid[0][2]==1) || (grid[1][0]==1 && grid[1][1]==1 && grid[1][2]==1) || (grid[2][0]==1 && grid[2][1]==1 && grid[2][2]==1) || (grid[0][0]==1 && grid[1][0]==1 && grid[2][0]==1) || (grid[0][1]==1 && grid[1][1]==1 && grid[2][1]==1) || (grid[0][2]==1 && grid[1][2]==1 && grid[2][2]==1)  || (grid[0][0]==1 && grid[1][1]==1 && grid[2][2]==1) || (grid[0][2]==1 && grid[1][1]==1 && grid[2][0]==1)){
            printf("\t  Player 1 wins!\n\n");
            break;
        }
        if((grid[0][0]==2 && grid[0][1]==2 && grid[0][2]==2) || (grid[1][0]==2 && grid[1][1]==2 && grid[1][2]==2) || (grid[2][0]==2 && grid[2][1]==2 && grid[2][2]==2) || (grid[0][0]==2 && grid[1][0]==2 && grid[2][0]==2) || (grid[0][1]==2 && grid[1][1]==2 && grid[2][1]==2) || (grid[0][2]==2 && grid[1][2]==2 && grid[2][2]==2)  || (grid[0][0]==2 && grid[1][1]==2 && grid[2][2]==2) || (grid[0][2]==2 && grid[1][1]==2 && grid[2][0]==2)){
            printf("\t  Player 2 wins!\n\n");
            break;
        }
        else if(filled==9){
            printf("\t  It's a tie!\n\n");
            break;
        }
        else{
            filled=0;
        }

        for(int i=0;i<ROWS;i++){
            printf("\t\t");
            for(int j=0;j<COLS;j++){
                printf("%d  ", grid[i][j]);
            }
            printf("\n");
        }

        printf("\nPlayer %d's turn. Enter a row and a column:\n\n", player);

        if(player==1){
            scanf("%d %d", &row, &col);
            if(row>3 || row<1 || col<1 || col >3){
                printf("\nInvalid row or column!\n");
                continue;
            }
            if(grid[row-1][col-1]){
                printf("\nThere is already a number in this position!\n");
                continue;
            }
            grid[row-1][col-1]=player;
            player=2;
        }
        else{
            scanf("%d %d", &row, &col);
            if(row>3 || row<1 || col<1 || col >3){
                printf("\nInvalid row or column!\n");
                continue;
            }
            if(grid[row-1][col-1]){
                printf("\nThere is already a number in this position!\n");
                continue;
            }
            grid[row-1][col-1]=player;
            player=1;
        }
    }

    for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                printf("\t%d", grid[i][j]);
            }
            printf("\n");
        }

    return 0;
}
