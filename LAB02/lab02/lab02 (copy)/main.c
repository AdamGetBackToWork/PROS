#include <stdio.h>
#include <stdlib.h>
#include "mylibrary.h"

int main(int argc, char *argv[]) {
    int table_size = 0;
    int count_check = 0;
    int move_count = 0;
    int row_num, col_num;
    
    if (argc != 2) {
        printf("Usage: %s <table_size>\n", argv[0]);
        return 1;
    }
    
    table_size = atoi(argv[1]);
    if (table_size < 2 || table_size > 9) {
        printf("Invalid input. Please pick a number between 2 and 9.\n");
        return 1;
    }
    
    char table[table_size][table_size];
    initializeTable(table_size, table);

    while (count_check != table_size * table_size) {
        displayTable(table_size, table);
        count_check = 0;

        if (getUserInput(&row_num, &col_num, &table_size)) {
            updateTable(table_size, table, row_num, col_num, move_count, count_check);
        }

        move_count++;
        count_check = checkWinCondition(count_check, table_size, table, move_count);
    }

    checkWinCondition(count_check, table_size, table, move_count);
    return 0;
}





