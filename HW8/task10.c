#include <stdio.h>

void foo(int arr[12]) {
    int temp[4];
    for (int i = 0; i < 4; ++i) {
        temp[i] = arr[8 + i];
    }

    for (int i = 11; i >= 4; --i) {
        arr[i] = arr[i - 4];
    }

    for (int i = 0; i < 4; ++i) {
        arr[i] = temp[i];
    }

}

int main(void) {
    int arr[12];
    for (int i = 0; i < 12; ++i) {
        scanf("%d", &arr[i]);
    }

    foo(arr);

    for (int i = 0; i < 12; ++i) printf("%d ", arr[i]);
}