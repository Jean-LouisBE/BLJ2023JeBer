#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNums(int i);

int main() {

    int answer;

    do {
        printf("Wie viele zufällige Zahlen möchten Sie? \n");
        fflush(stdin);
        scanf("%d", &answer);

        if (answer < 1 || answer > 500) {
            printf("Bitte eine Zahl zwischen 1-500 \n");
        }

    } while (answer < 1 || answer > 500);

    getRandomNums(answer);

    return 0;
}

int getRandomNums(int i) {

    srand(time(NULL));

    int *nums = malloc(i * sizeof(int));65

    if (nums == NULL) {
        exit(1);
    }
    for (int n = 0; n < i; n++) {
        int RandNums = rand() % 100 + 1;
        *(nums + 1) = RandNums;
        printf("%d   ", *(nums + 1));

    }
    return nums;
}