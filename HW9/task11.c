#include <stdio.h>
#include <limits.h>

void find_min_sum(int arr[]) {
    int min = INT_MAX;
    int min_pos_1 = 0;
    int min_pos_2 = 0;

    for (int i = 0; i < 29; ++i) {
        for (int j = i + 1; j < 30; ++j) {
            int sum = arr[i] + arr[j];
            if (sum < min) {
                min = sum;
                min_pos_1 = i;
                min_pos_2 = j;
            }
        }
    }
    (min_pos_1 > min_pos_2) ? printf("%d %d", min_pos_2, min_pos_1) : printf("%d %d", min_pos_1, min_pos_2); 
}

int main(void) {
    int arr[30];
    for (int i = 0; i < 30; ++i) {
        scanf("%d", &arr[i]);
    }

    find_min_sum(arr);

    return 0;
}