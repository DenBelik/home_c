#include <stdio.h>

int main(void) {
    int arr[10];
    int positive[10];
    int positive_pos = 0;
    int negative[10];
    int negative_pos = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);

        if (arr[i] > 0) {
            positive[positive_pos] = arr[i];
            positive_pos++;
        } else if (arr[i] < 0) {
            negative[negative_pos] = arr[i];
            negative_pos++;
        }
    }
    
    for (int i = 0; i < positive_pos; ++i) printf("%d ", positive[i]);
    for (int i = 0; i < negative_pos; ++i) printf("%d ", negative[i]);

    return 0;
}