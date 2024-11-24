#include <stdio.h>

void sort_array(int arr[10]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = i; j < 10; j++) {
            if (arr[i] % 10 > arr[j] % 10) {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
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