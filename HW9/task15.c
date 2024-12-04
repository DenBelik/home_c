#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 0; i < size; ++i) {
        if (arr[i] > max) max = arr[i];
    }

    return max;
}

int count_bigger_abs(int n, int a[]) {
    int max = find_max(a, n);
    int col = 0;

    for (int i = 0; i < n; ++i) {
        if (abs(a[i]) > max) col++;
    }

    return col;
}


int main(void) {
    int *arr = NULL;
    int buffer = 10;

    arr = (int*)malloc(buffer * sizeof(int));

    int size = input_array(arr, &buffer);

    printf("%d" , count_bigger_abs(size, arr));
    
    return 0;
}