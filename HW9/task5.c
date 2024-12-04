#include <stdio.h>
#include <stdlib.h>

int find_max_array(int size, int a[]) {
    int max = a[0];
    for (int i = 0; i < size; ++i) {
        if (a[i] > max) max = a[i];
    }

    return max;
}

int main(void) {
    int *arr = NULL;
    int size = 0;
    int max = 10;
    char c;

    arr = (int*)malloc(max * sizeof(int));

    while ((c = getchar()) != '.') {
        int num = 0;
        while(c != ' ' && c != '.') {
            num = num * 10 + c - '0';
            c = getchar();
        }

        if (size == max) {
            max *= 2;
            arr = (int*)realloc(arr, max * sizeof(int));
        }
        arr[size++] = num;
        if (c == '.') break;
    }

    printf("%d", find_max_array(size, arr));

    free(arr);

    return 0;
}