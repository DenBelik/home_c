#include <stdio.h>

int find_average(int arr[5][5]) {
    int i = 0;
    int j = 0;
    int average = 0;
    while (i < 5 && j < 5) {
        average += arr[i][j];
        i++;
        j++;
    }
    return average / 5;
}

int main(void) {
    int arr[5][5];
    int counter = 0;
    int avg;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }

    avg = find_average(arr);

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (arr[i][j] > 0 && arr[i][j] > avg) counter++;
        }
    }

    printf("%d", counter);

    return 0;
}