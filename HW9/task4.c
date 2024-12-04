#include <stdio.h>

int is_digit(char c) {
    return ((c >= '0') && (c <= '9'));
}

void print_digit(char s[]) {
    int pos_s = 0;
    int pos_buf = 0;
    int col[10] = {0};
    int buf[100];
    char c;

    while(s[pos_s] != '.') {
        if (is_digit(s[pos_s])) {
            buf[pos_buf] = s[pos_s] - '0';
            col[buf[pos_buf]]++;
            pos_buf++;
        }
        pos_s++;
    }

    for (int i = 0; i < 10; ++i) {
        if (col[i] != 0) {
            printf("%d %d ", i, col[i]);
        }
    }

}

int main(void) {
    int buffer = 100;
    char arr[buffer];
    int size = 0;
    char c;
    while((c = getchar()) != '\n') {
        arr[size] = c;
        ++size;
    }

    print_digit(arr);
}