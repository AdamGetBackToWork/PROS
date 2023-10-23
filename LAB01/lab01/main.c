#include <stdio.h>
#include <windows.h>

int main() {
    int move_count = 0, col_num, row_num, limit = 0, count_check = 0;
    char buffer[256];

    // Initialize a 9x9 table with '0' values
    char table[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            table[i][j] = '0';
        }
    }

    // Main game loop - continues until 'count_check' reaches 81 - meaning the entire board is covered with "+"
    while (count_check != 10) {
        count_check = 0;

        // Display the game board, as a 9x9 table with border
        printf("  1 2 3 4 5 6 7 8 9\n ");
        for (int i = 0; i < 9; i++) {
            printf("------------------- \n%d", i + 1);
            for (int j = 0; j < 9; j++) {
                printf("|%c", table[i][j]);
            }
            printf("|\n ");
        }
        printf("------------------- \n\nLiczba ruchów: %d\n", move_count);

        // Get row number input from the user
        // Using buffer to store the input, to avoid entering infinite loop when user inputs not an integer
        printf("Podaj nr. wiersza: ");
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%d", &row_num) == 1) {
                    if (row_num >= 1 && row_num <= 9) {
                        break;
                    }
                }
            }
            printf("Nieprawidłowe dane. Podaj nr. wiersza z przedziału 1-9: ");
        }

        // Same goes here get column number input from the user
        printf("Podaj nr. kolumny: ");
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (sscanf(buffer, "%d", &col_num) == 1) {
                    if (col_num >= 1 && col_num <= 9) {
                        break;
                    }
                }
            }
            printf("Nieprawidłowe dane. Podaj nr. kolumny z przedziału 1-9: ");
        }

        col_num -= 1; // Adjust to 0-based index
        row_num -= 1; // Adjust to 0-based index

        // Update the game board based on user input, input the "+" where user specified
        if (table[row_num][col_num] == '0' || table[row_num][col_num] == '+') {
            table[row_num][col_num] = (table[row_num][col_num] == '0') ? '+' : '0';

            // Toggle adjacent cells,
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

        // Count the number of '+' symbols on the board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (table[i][j] == '+') {
                    count_check = count_check + 1;
                }
            }
        }
        // Display the current score
        printf("Your current score is %d! Get 81 to win! \n", count_check);
        move_count = move_count + 1;
    }

    // Display a win message and final score
    printf("\n----------------------------------------\n");
    printf("---------------!-YOU WIN-!--------------\n");
    printf("----------------------------------------\n");
    printf("------------Your score is: %d------------\n", move_count);
    printf("----------------------------------------\n");

    return 0;
}
