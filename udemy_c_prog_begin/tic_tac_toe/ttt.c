#include "ttt.h"

int main(){
    int grid[3][3] = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1, -1}
        };

    int winner = check_for_winner(grid);
    int current_player = 0;
    while (winner == -1){
        print_board(grid);
        printf("\nIt is player %i's turn. Please enter a row:  ", current_player + 1);
        
        int row_selection = -1;
        scanf("%i", &row_selection);
        row_selection -= 1;

        int column_selection = -1;
        printf("\nPlease enter a column:  ");
        scanf("%i", &column_selection);
        column_selection -= 1;

        if(grid[row_selection][column_selection] != -1){
            printf("That space is not available, please select another.");
        }
        else{
            grid[row_selection][column_selection] = current_player;
            if(current_player == 0){
                current_player = 1;
            }
            else{
                current_player = 0;
            }
            winner = check_for_winner(grid);
        }
    }

    if(winner == -2){
        printf("Stalemate!!!\n");
    }
    else{
        printf("Player %i wins!", winner + 1);
    }

    return 0;
}

int check_for_winner(int grid[3][3]){

    for (int i = 0; i < 3; i++){
        //check columns
        if(grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != -1){
            return grid[0][i];
        }

        //check rows
        if(grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != -1){
            return grid[i][0];
        }
    } 
    //check diagonals
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != -1){
        return grid[0][0];
    }
    else if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != -1){
        return grid[0][2];
    }

    //check for stalemate
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (grid[r][c] == -1){
                return -1;
            }
        }
    }
    

    return -2;
}

void print_board(int grid[3][3]){
    printf("\n\n\n   1  2  3 \n");
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            char marker = ' ';
            if(grid[r][c] == 0){
                marker = 'O';
            }
            else if (grid[r][c] == 1){
                marker = 'X';
            }
            if (c == 0){
                printf("%i ", r + 1);
            }
            printf("[%c]", marker);
            if(c == 2){
                printf("\n");
            }
        }
    }
}