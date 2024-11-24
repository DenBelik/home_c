#include <stdio.h>

float foo (int arr[12]) {
    int sum = 0;
    for (int i = 0; i < 12; ++i) sum += arr[i];
    return (float)sum / 12;
}

int main(void) {
    int arr[12];
    for (int i = 0; i < 12; ++i) scanf("%d", &arr[i]);
    printf("%.2f", foo(arr));
    return 0;
}