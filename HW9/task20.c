#include <stdio.h>
#include <stdlib.h>

int input_array(int arr[], int *max) {
    char c;
    int size = 0;
    while ((c = getchar()) != '\n') {
        int num = 0;
        while (c != ' ' && c != '\n') {
            num = num * 10 + c - '0';
            c = getchar();
        }

        if (size == *max) {
            arr = (int*)realloc(arr, *max * sizeof(int));
        }

        arr[size++] = num;

        if (c == '\n') break;
    }

    return size;
}

void replace_even(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 0) {
            int temp = 1;
            while (arr[i]) {
                if (arr[i] % 10 % 2 == 0) {
                    temp *= arr[i] % 10;
                }
                arr[i] /= 10;
            }
            arr[i] = temp;
        }
    }    
}

void replace_odd(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] % 2 == 1) {
            int temp = 1;
            while (arr[i]) {
                if (arr[i] % 10 % 2 == 1) {
                    temp *= arr[i] % 10;
                }
                arr[i] /= 10;
            }
            arr[i] = temp;
        }
    }
}

int main() {
    int *arr = NULL;
    int max = 10;
    int even_count = 0;
    int odd_count = 0;
    char c;
    arr = (int*)malloc(max * sizeof(int));
    int size = input_array(arr, &max);
    for (int i = 0; i < size; ++i) {
        (arr[i] % 2 == 0) ? even_count++ : odd_count++;
    }

    (even_count > odd_count) ? replace_odd(arr, size) : replace_even(arr, size);

    for (int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);

    return 0;    
}