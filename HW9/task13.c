#include <stdio.h>
#include <stdlib.h>

int count_between(int from, int to, int size, int a[]) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (a[i] >= from && a[i] <= to) {
            count++;
        }
    }
    return count;
}

int main(void) {
    int *arr = NULL;
    int size = 0;
    int max = 10;
    char c;

    arr = (int*)malloc(max * sizeof(int));

    while ((c = getchar()) != '\n') {
        int num = 0;
        while (c != ' ' && c != '\n') {
            num = num * 10 + c - '0';
            c = getchar();
        }

        if (size == max) {
            arr = (int*)realloc(arr, max * sizeof(int));
        }

        arr[size++] = num;

        if (c == '\n') break;
    }

    int from;
    int to;

    scanf("%d%d", &from, &to);
    printf("%d", count_between(from, to, size, arr));

    free(arr);

    return 0;
}