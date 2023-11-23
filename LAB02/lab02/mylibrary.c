#include "mylibrary.h"
#include <stdio.h>


//Function for specyfying the gameboard, sizes from 2 to 9.
void specifyTableSize(int *table_size){
	printf("Input size of the game board, make it reasonalbe though... so between 2 'n 9: ");
	
	//Buffer for comparing sizes with user input
	char buffer[256];
	
	//Checking whether or not, the input size is an integer. 
	//Only if it is, this while loop will let us proceed
	while (1) {
        	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            		if (sscanf(buffer, "%d", table_size) == 1) {
                		if (*table_size >= 2 && *table_size <= 9) {
                    			break;
                		}
            		}
        	}
        	printf("Invalid parameter. Please pick a number between 2 and 9: ");
	}
}

//Function for initializing the table of "0s"
void initializeTable(int table_size, char table[][table_size]) {
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            table[i][j] = '0';
        }
    }
}

//Function for displaying the UPDATED table
void displayTable(int table_size, char table[table_size][table_size]) {

    printf("  ");

    for(int i = 0; i < table_size; i++){
	printf("%d ", i+1);
    }

    printf("\n");


    //Printing the border
    for (int i = 0; i < table_size; i++) {
	    printf("  ");
        	for(int j = 0; j < table_size; j++){
	   		 printf("--");
		}
	printf("\n%d", i+1);

        for (int j = 0; j < table_size; j++) {
            printf("|");

	    	//Adjusting the color in regard to symbol in the [i][j]
            	if (table[i][j] == '0') {
               		printf("\033[36m%c\033[0m", table[i][j]);
            	} else if (table[i][j] == '+') {
                	printf("\033[31m%c\033[0m", table[i][j]);
            	}
        }
        printf("|\n");
    }

    for(int j = 0; j < table_size + 1; j++){
	printf("--");
    }
    printf("\n\n");
}

//Function for getting the user input for specified row and column number
int getUserInput(int *row_num, int *col_num, int *table_size) {
    
    //Buffer for comparing sizes with input
    char buffer[256];

    printf("Input row number: ");
    //Again loop waiting for an input to be an integer, now for row_number
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", row_num) == 1) {
                if (*row_num >= 1 && *row_num <= *table_size) {
                    break;
                }
            }
        }
        printf("Invalid input. Please pick a number between 1 and %d: ", *table_size);
    }

    printf("Input column number: ");
    //The same loop, now for column
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", col_num) == 1) {
                if (*col_num >= 1 && *col_num <= *table_size) {
                    break;
                }
            }
        }
        printf("Invalid input. Please pick a number between 1 and %d: ", *table_size);
    }

    // Adjust to 0-based index
    (*col_num) -= 1;
    (*row_num) -= 1; 

    return 1;
}


//Function for updating the table of the user input row_number and column_number
void updateTable(int table_size, char table[][table_size], int row_num, int col_num, int move_count, int count_check) {
    if (table[row_num][col_num] == '0' || table[row_num][col_num] == '+') {
            table[row_num][col_num] = (table[row_num][col_num] == '0') ? '+' : '0';

            // Toggle adjacent cells,
            if (row_num > 0) {
                table[row_num - 1][col_num] = (table[row_num - 1][col_num] == '0') ? '+' : '0';
            }
            if (row_num < table_size - 1) {
                table[row_num + 1][col_num] = (table[row_num + 1][col_num] == '0') ? '+' : '0';
            }
            if (col_num > 0) {
                table[row_num][col_num - 1] = (table[row_num][col_num - 1] == '0') ? '+' : '0';
            }
            if (col_num < table_size - 1) {
                table[row_num][col_num + 1] = (table[row_num][col_num + 1] == '0') ? '+' : '0';
            }
    }

    //Couting the user score
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            if (table[i][j] == '+') {
                count_check++;
            }
        }
    }

    //Letting the user know what their score is
    int win_score = table_size*table_size;
    printf("Your current score is %d! Get %d to win!\n", count_check, win_score);
    (move_count)++;
}

//Function for ending the game, it checks the winning condition based on the counted 
//number of "+" and if it matches the dim of gameboard then display WIN msg
int checkWinCondition(int count_check, int table_size, char table[][table_size], int move_count) {
    
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            if (table[i][j] == '+') {
                (count_check)++;
            }
        }
    }


    if (count_check == table_size*table_size) {
        printf("\n----------------------------------------\n");
        printf("---------------!-YOU WIN-!--------------\n");
        printf("----------------------------------------\n");
        printf("------------Your score is: %d------------\n", move_count);
        printf("----------------------------------------\n");
    }
    return count_check;
}

