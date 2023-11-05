#include <stdio.h>
#include "mylibrary.h"

int main() {
    int table_size;
    specifyTableSize(&table_size);

    char table[table_size][table_size];
    initializeTable(table_size, table);

    int move_count = 0;
    int count_check = 0;
    int row_num, col_num;
    while (count_check != table_size * table_size) {
        displayTable(table_size, table);

        if (getUserInput(row_num, col_num)) {
            updateTable(table_size, table, row_num, col_num, move_count, count_check);
        }

        count_check = checkWinCondition(count_check);
        move_count++;
    }

    printf("You win! Your score is: %d\n", move_count);
    return 0;
}




