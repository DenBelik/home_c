#include <stdio.h>
#include <limits.h>

int main(void) {
    int a[10][10];
    int max[10] = {INT_MIN};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            scanf("%d", &a[i][j]);
            if (a[i][j] > max[i]) max[i] = a[i][j];
        }
    }

    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += max[i];
    }

    printf("%d", sum);

    return 0;
}