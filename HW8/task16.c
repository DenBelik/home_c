#include <stdio.h>

int foo(int arr[10]) {
    int res_num = arr[0];
    int res_num_col = 1;

    for (int i = 0; i < 10; ++i) {
        int col = 0;
        if (arr[i] == res_num) continue;
        for (int j = 0; j < 10; ++j) {
            if (arr[j] == arr[i]) col++;
        }
        if (col > res_num_col) {
            res_num = arr[i];
            res_num_col = col;
        }
    }

    return res_num;
}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("%d", foo(arr));

    return 0;
}