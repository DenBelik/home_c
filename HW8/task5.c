#include <stdio.h>

int find_pos_sum(int arr[10]) {
    int sum = 0;
    for (int i = 0; i < 10; ++i) {
        if (arr[i] >=0) sum += arr[i];
    }
    return sum;
}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }
    printf("%d", find_pos_sum(arr));
    return 0;
}