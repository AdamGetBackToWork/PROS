
#ifndef MYLIBRARY_H
#define MYLIBRARY_H

void specifyTableSize(int *table_size);
void initializeTable(int table_size, char table[table_size][table_size]);
void displayTable(int table_size, char table[table_size][table_size]);
int getUserInput(int row_num, int col_num);
void updateTable(int table_size, char table[][table_size], int row_num, int col_num, int move_count, int count_check);
int checkWinCondition(int count_check);

#endif
