#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FIELD_SIZE 5

int main() {
    int numb = 1;
    int usx = 0;
    int usy = 0;
    int play = 1;

    srand(time(NULL));
    int field[FIELD_SIZE][FIELD_SIZE] = {
            {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2},
            {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2},
            {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2},
            {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2},
            {rand() % 2, rand() % 2, rand() % 2, rand() % 2, rand() % 2},
    };

    printf("+--------------------------------+\n");
    printf("| WELCOME TO THE LIGHTS OUT GAME |\n");
    printf("+--------------------------------+\n\n");

    do {

        printf("\n\t| 1. | 2. | 3. | 4. | 5. |\n\n");

        printf("\t+----+----+----+----+----+\n");
        for (int row = 0; row < FIELD_SIZE; row++) {
            printf("| %d. |\t| ", row + 1);
            for (int col = 0; col < FIELD_SIZE; col++) {
                if (field[row][col] != 0) {
                    printf(" # | ");
                } else {
                    printf("   | ");
                }
            }
            printf("\n\t+----+----+----+----+----+\n");

        }

        printf("Enter your first field: ");
        scanf(" %d", &usx);

        printf("Enter your second field: ");
        scanf(" %d", &usy);

        usx -= 1;
        usy -= 1;

        if (-1 < usy - 1) {
            if (1 == field[usy - 1][usx]) {
                field[usy - 1][usx] = 0;
            } else {
                field[usy - 1][usx] = 1;
            }
        }
        if (5 > usy + 1) {
            if (1 == field[usy + 1][usx]) {
                field[usy + 1][usx] = 0;
            } else {
                field[usy + 1][usx] = 1;
            }
        }
        if (-1 < usx - 1) {
            if (1 == field[usy][usx - 1]) {
                field[usy][usx - 1] = 0;
            } else {
                field[usy][usx -1] = 1;
            }
        }
        if (5 > usx + 1) {
            if (1 == field[usy][usx + 1]) {
                field[usy][usx + 1] = 0;
            } else {
                field[usy][usx + 1] = 1;
            }
        }
        if (1 == field[usy][usx]) {
            field[usy][usx] = 0;
        } else {
            field[usy][usx] = 1;
        }
    }while (play == 1);
    return 0;
}
