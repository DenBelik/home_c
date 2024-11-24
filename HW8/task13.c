#include <stdio.h>

int main(void) {
    int arr[10];
    int res[10];
    int res_pos = 0;
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);

        if ((arr[i] / 10) % 10 == 0) {
            res[res_pos] = arr[i];
            res_pos++;
        }
    }

    for (int i = 0; i < res_pos; ++i) printf("%d ", res[i]);
    return 0;
}