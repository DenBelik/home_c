#include <stdio.h>

void sort_array(int arr[10]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = i; j < 5; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 5; i < 9; ++i) {
        for (int j = i; j < 10; ++j) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    sort_array(arr);

    for (int i = 0; i < 10; ++i) printf("%d ", arr[i]);
    return 0;
}