#include <stdio.h>

float foo (int arr[5]) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) sum += arr[i];
    return (float)sum / 5;
}

int main(void) {
    int arr[5];
    for (int i = 0; i < 5; ++i) scanf("%d", &arr[i]);
    printf("%.3f", foo(arr));
    return 0;
}