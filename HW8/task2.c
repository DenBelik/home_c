#include <stdio.h>

int find_min(int arr[5]) {
    int min = arr[0];
    for (int i = 0; i < 5; ++i) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int main(void) {
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("%d", find_min(arr));
    return 0;
}