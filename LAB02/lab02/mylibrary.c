#include "mylibrary.h"
#include <stdio.h>

void specifyTableSize(int *table_size){
	printf("Input size of the game board, make it reasonalbe though... so between 2 'n 9: ");
	char buffer[256];

	while (1) {
        	if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            		if (sscanf(buffer, "%d", table_size) == 1) {
                		if (*table_size >= 2 && *table_size <= 9) {
                    			break;
                		}
            		}
        	}
        	printf("Invalid input. Please pick a number between 2 and 9: ");
	}
}

void initializeTable(int table_size, char table[][table_size]) {
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            table[i][j] = '0';
        }
    }
}

void displayTable(int table_size, char table[table_size][table_size]) {

    printf("  ");

    for(int i = 0; i < table_size; i++){
	printf("%d ", i+1);
    }

    printf("\n");

    for (int i = 0; i < table_size; i++) {
	printf("%d ", i+1);    
        	for(int j = 0; j < table_size; j++){
	   		 printf("--");
		}
	printf("\n ");
        for (int j = 0; j < table_size; j++) {
            printf("|");
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

int getUserInput(int row_num, int col_num) {
    char buffer[256];

    printf("Input row number: ");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &row_num) == 1) {
                if (row_num >= 1 && row_num <= 9) {
                    break;
                }
            }
        }
        printf("Invalid input. Please pick a number between 1 and 9: ");
    }

    printf("Input column number: ");
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &col_num) == 1) {
                if (col_num >= 1 && col_num <= 9) {
                    break;
                }
            }
        }
        printf("Invalid input. Please pick a number between 1 and 9: ");
    }

    (col_num) -= 1; // Adjust to 0-based index
    (row_num) -= 1; // Adjust to 0-based index

    return 1;
}

void updateTable(int table_size, char table[][table_size], int row_num, int col_num, int move_count, int count_check) {
    if (table[row_num][col_num] == '0' || table[row_num][col_num] == '+') {
        table[row_num][col_num] = (table[row_num][col_num] == '0') ? '+' : '0';

        if (row_num > 0) {
            table[row_num - 1][col_num] = (table[row_num - 1][col_num] == '0') ? '+' : '0';
        }
        if (row_num < 8) {
            table[row_num + 1][col_num] = (table[row_num + 1][col_num] == '0') ? '+' : '0';
        }
        if (col_num > 0) {
            table[row_num][col_num - 1] = (table[row_num][col_num - 1] == '0') ? '+' : '0';
        }
        if (col_num < 8) {
            table[row_num][col_num + 1] = (table[row_num][col_num + 1] == '0') ? '+' : '0';
        }
    }

    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            if (table[i][j] == '+') {
                (count_check)++;
            }
        }
    }

    printf("Your current score is %d! Get 81 to win!\n", count_check);
    (move_count)++;
}

int checkWinCondition(int count_check) {
    if (count_check == 81) {
        printf("\n----------------------------------------\n");
        printf("---------------!-YOU WIN-!--------------\n");
        printf("----------------------------------------\n");
        printf("------------Your score is: %d------------\n", count_check);
        printf("----------------------------------------\n");
    }
    return count_check;
}

