#include <stdio.h>
#include <stdlib.h>

int is_two_same(int size, int a[]) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (a[i] == a[j]) return 1;
        }
    }
    return 0;
}

int is_digit(char c)
{
    return ((c>='0')&&(c<='9'));
}


int main(void) {
    int *arr = NULL;
    int max = 10;
    int size = 0;
    char c;

    arr = (int*)malloc(max * sizeof(int));

    while ((c = getchar()) != '\n') {
        if (is_digit(c)) {
            int num = 0;
            do {
                num = num * 10 + c - '0';
                c = getchar();
            } while (is_digit(c));

            if (size == max) {
                max *= 2;
                arr = (int*)realloc(arr, max * sizeof(int));
            }

            arr[size++] = num;
            if (c == '\n') break;
        }
    }

    printf(is_two_same(size, arr) ? "YES" : "NO");

    free(arr);

    return 0;
}