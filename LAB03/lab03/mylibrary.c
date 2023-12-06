#include "mylibrary.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

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
void initializeTable(int table_size, char **table) {
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
            table[i][j] = '0';
        }
    }
}

//Function for displaying the UPDATED table
void displayTable(int table_size, char **table) {

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
                if ((*row_num >= 1 && *row_num <= *table_size) || *row_num == 69) {
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
                if ((*col_num >= 1 && *col_num <= *table_size) || *col_num == 69) {
                    break;
                }
            }
        }
        printf("Invalid input. Please pick a number between 1 and %d: ", *table_size);
    }

    if (*row_num == 69 && *col_num == 69) {
        return 0; // Easter egg found, return 0 to indicate this
    }


    // Adjust to 0-based index
    (*col_num) -= 1;
    (*row_num) -= 1; 

    return 1;
}

bool easterEgg(int *row_num, int *col_num){
    if (*col_num == 69 && *row_num == 69){
	return true;
    } else {
	return false;
    }
}

//Function for updating the table of the user input row_number and column_number
void updateTable(int table_size, char **table, int row_num, int col_num, int move_count, int count_check) {
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
int checkWinCondition(int count_check, int table_size, char **table, int move_count) {
    
    for (int i = 0; i < table_size; i++) {
        for (int j = 0; j < table_size; j++) {
		if (table[i][j] == '+'){
			(count_check)++;
		}	
	  }
    }
    return count_check;
}

void winnerMessage(int move_count){
		    
        printf("\n----------------------------------------\n");
        printf("---------------!-YOU WIN-!--------------\n");
        printf("----------------------------------------\n");
        printf("------------Your score is: %d------------\n", move_count);
        printf("----------------------------------------\n");


}


void writeIntoFile(int table_size, int move_count){
    
    FILE *fp;

    fp = fopen("scores.txt", "a+");

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if(fp == NULL) {
        printf("file couldn't be opened\n");
        exit(1);
    }
    fprintf(fp, "------------------------------\n");

    fprintf(fp, "game date: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    fprintf(fp, "------------------------------\n");
    fprintf(fp, "---------table size: %d--------\n", table_size);
    fprintf(fp, "---------move count: %d--------\n", move_count);
    fprintf(fp, "------------------------------\n\n");

    fclose(fp);
}


void openGameFile(FILE **file){

    *file = fopen("gamefile.txt", "a+");


    if(file == NULL) {
        printf("file couldn't be opened\n");
        exit(1);
    }
}


void writeGameFile(int *row_num, int *col_num, int iteration, FILE *file){

    fprintf(file, "------------------------------\n");
    fprintf(file, "----------Round:  %d   --------\n", iteration);
    fprintf(file, "--------row number: %d --------\n", *row_num + 1);
    fprintf(file, "--------col number: %d --------\n", *col_num + 1);
    fprintf(file, "------------------------------\n\n");

}

void closeGameFile(FILE **file){
	
    fprintf(*file, "\n\n\n");

    fclose(*file);

    *file = NULL;

}

