#include <stdio.h>
#include <windows.h>

int main(){

    int move_count = 0, col_num, row_num, limit =0, count_check = 0;
    char buffer[256];

    char table[9][9];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            table[i][j] = '0';
        }
    }

    while(count_check != 81){

        count_check = 0;

        printf("  1 2 3 4 5 6 7 8 9\n ");
        for(int i=0;i<9;i++){
            printf("------------------- \n%d", i+1);
            for(int j= 0;j<9;j++){
                printf("|%c", table[i][j]);
            }
            printf("|\n ");
        }
        printf("------------------- \n\nLiczba ruchów: %d\n", move_count);

        printf("Podaj nr. wiersza: ");
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL){
                if (sscanf(buffer, "%d", &row_num) == 1){
                    if (row_num >= 1 && row_num <= 9){
                        break;
                    }
                }
            }
            printf("Nieprawidłowe dane. Podaj nr. wiersza z przedziału 1-9: ");
        }

        printf("Podaj nr. kolumny: ");
        while (1) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL){
                if (sscanf(buffer, "%d", &col_num) == 1){
                    if (col_num >= 1 && col_num <= 9){
                        break;
                    }
                }
            }
            printf("Nieprawidłowe dane. Podaj nr. kolumny z przedziału 1-9: ");
        }

        col_num -= 1, row_num -=1;

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

        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (table[i][j] == '+'){
                    count_check = count_check + 1;
                }
            }
        }
        printf("Get 81 to win! Your current score is %d\n", count_check);
        move_count = move_count + 1;
    }
    printf("YOU WIN \n Your score is: %d", count_check);
    return 0;
}
