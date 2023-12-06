#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"
#include <stdbool.h>

int main(int argc, char *argv[]) {
    int table_size = 0; // variable for user-input gameboard size
    int count_check = 0; // variable to keep track of the number of checked cells
    int move_count = 0; // variable to keep track of the number of moves
    int row_num, col_num; // variables for user-input row and column number

    // Checking for correct command line arguments
    if (argc != 2) {
        printf("Usage: %s <table_size>\n", argv[0]);
        return 1;
    }

    // Converting command line argument to integer
    table_size = atoi(argv[1]);

    // Validating input size
    if (table_size < 2 || table_size > 9) {
        printf("Invalid input. Please pick a number between 2 and 9.\n");
        return 1;
    }
    
    // char table[table_size][table_size];

    char **table = (char **)malloc(table_size * sizeof(char *));
    for (int i = 0; i < table_size; ++i){
	    table[i] = (char *)malloc(table_size * sizeof(char));
    }

    // Initializing the game table based on user input
    initializeTable(table_size, table);

    FILE *file = NULL;	

    openGameFile(&file);

    // Game loop: continues until all cells are checked or win condition is met
    while ((count_check != table_size * table_size) && (easterEgg(&row_num, &col_num) == false)) {
        // Displaying the game table
        displayTable(stdout,table_size, table);
        count_check = 0;

        // Getting user input for row and column
        if (getUserInput(&row_num, &col_num, &table_size)) {
            // Updating the table based on user input
            updateTable(table_size, table, row_num, col_num, move_count, count_check);
        }

        // Incrementing move count
        move_count++;

        // Checking win condition and updating count_check
        count_check = checkWinCondition(count_check, table_size, table, move_count);
    	
	writeGameFile(&row_num, &col_num, move_count, file);
    }

    // Checking the win condition one last time before exiting
    winnerMessage(move_count);

    // Writing game score and table size with game time to a file named scores.txt
    writeIntoFile(table_size, move_count);

    // I didnt want to open the file at the start of the game, cause then the game
    // would be heavier to run. This choice was only because of my preference, if
    // necessary, I can change it.

    closeGameFile(&file);
    
    for(int i = 0; i < table_size; ++i){
	free(table[i]);
    }

    free(table);

    return 0;
}






