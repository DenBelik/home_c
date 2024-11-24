#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);

    int temp = num;
    int digits_col = 0;

    while(temp > 0) {
        temp /= 10;
        digits_col++;
    }

    int arr[digits_col];
    int pos = 0;

    while(num > 0) {
        arr[pos] = num % 10;
        pos++;
        num /= 10;
    }

    for (int i = 0; i < pos - 1 ; ++i) {
        for (int j = i; j < pos; ++j) {
            if (arr[i] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < pos; ++i) {
        printf("%d", arr[i]);
    }

    return 0;
}