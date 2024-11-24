#include <stdio.h>

void print_arr(int arr[10]) {
    for (int i = 0; i < 10; ++i) {
        int col = 0;
        for (int j = 0; j < 10; ++j) {
            if (arr[i] == arr[j]) col++;
            if (col > 1) break;
        }
        if (col == 1) printf("%d ", arr[i]);
    }

}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &arr[i]);
    }

    print_arr(arr);

    return 0;
}