#include <stdio.h>

int main(void) {
    int mas[5];
    scanf("%d%d%d%d%d", &mas[0], &mas[1], &mas[2], &mas[3], &mas[4]);
    int max = mas[0];
    int min = mas[0];
    for (int i = 1; i < 5; ++i) {
        max = (max > mas[i]) ? max : mas[i];
        min = (min < mas[i]) ? min : mas[i];
    }
    printf("%d", max + min);
    return 0;
}