#include <stdio.h>
#include "mylibrary.h"


//Main function of my programme
int main() {
    int table_size = 0; //variable for user-input gameboard size
    int count_check = 0; //variable 
    int move_count = 0; //variable to keep track of the number of moves
    int row_num, col_num; //variables for user-input row and column number
    char table[table_size][table_size]; //table of table_size size


    specifyTableSize(&table_size);
    initializeTable(table_size, table);
 
    //While (player hasn't already won) still display table, get user_input, etc. 
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




