#ifndef MYLIBRARY_H
#define MYLIBRARY_H
#include <stdbool.h>
#include <stdio.h>

void specifyTableSize(int *table_size);
void initializeTable(int table_size, char **table);
void displayTable(int table_size, char **table);
int getUserInput(int *row_num, int *col_num, int *table_size);
bool easterEgg(int *row_num, int *col_num);
void updateTable(int table_size, char **table, int row_num, int col_num, int move_count, int count_check);
int checkWinCondition(int count_check, int table_size, char **table, int move_count);
void winnerMessage(int move_count);
void writeIntoFile(int table_size, int move_count);
void openGameFile(FILE **file);
void writeGameFile(int *row_num, int *col_num, int iteration, FILE *file);
void closeGameFile(FILE **file);

#endif
