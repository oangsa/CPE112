// Suthang Sukrueangkun
// 67070503477

#include <stdio.h>

int main() {
    int first_col_size;
    int first_row_size;

    int second_col_size;
    int second_row_size;

    int firstMatrix[99][99];
    int secondMatrix[99][99];
    int newMatrix[99][99];

    int val = 0;

    scanf(" %d %d", &first_col_size, &first_row_size);

    for (int col = 0; col < first_col_size; col++) {
        for (int row = 0; row < first_row_size; row++) {
            scanf("%d", &firstMatrix[col][row]);
        }
    }

    scanf(" %d %d", &second_col_size, &second_row_size);

    for (int col = 0; col < second_col_size; col++) {
        for (int row = 0; row < second_row_size; row++) {
            scanf("%d", &secondMatrix[col][row]);
        }
    }

    if (first_row_size != second_col_size) {
        printf("Matrices cannot be multiplied");
        return 1;
    }

    // col = x, row = y | 2x3 , 3x2 || new = 3x3
    for (int i = 0; i < first_col_size; i++) {
        for (int j = 0; j < second_row_size; j++) {
            for (int k = 0; k < second_col_size; k++) {
                val += firstMatrix[i][k] * secondMatrix[k][j];
            }
        newMatrix[i][j] = val;
        val = 0;
        }
    }

    int new_col_size = first_col_size;
    int new_row_size = second_row_size;

    for ( int col = 0; col < new_col_size; col++) {
        for (int row = 0; row < new_row_size; row++) printf("%d ", newMatrix[row][col]);
        printf("\n");
    }

}