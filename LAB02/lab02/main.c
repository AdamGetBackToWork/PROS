#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int main(int argc, char *argv[]) {
    int table_size = 0; // variable for user-input gameboard size
    int count_check = 0; // variable to keep track of the number of checked cells
    int move_count = 0; // variable to keep track of the number of moves
    int row_num, col_num; // variables for user-input row and column number
    char table[table_size][table_size]; // table of table_size size (not initialized)

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

    // Initializing the game table based on user input
    initializeTable(table_size, table);

    // Game loop: continues until all cells are checked or win condition is met
    while (count_check != table_size * table_size) {
        // Displaying the game table
        displayTable(table_size, table);
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
    }

    // Checking the win condition one last time before exiting
    checkWinCondition(count_check, table_size, table, move_count);
    return 0;
}






