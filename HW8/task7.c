#include <stdio.h>

void reverse_array(int arr[10], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; ++i) scanf("%d", &arr[i]);
    reverse_array(arr, 0, 4);
    reverse_array(arr, 5, 9);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}