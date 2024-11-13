#include <stdio.h>

int pow(int num, int st) {
    if (st == 0) {
        num = 1;
        return num;
    }
    int buf = num;
    for (int i = 1; i <st; ++i) {
        num = num * buf;
    }
    return num;
}

int main(void) {
    int n, p;
    scanf("%d%d", &n, &p);
    printf("%d", pow(n, p));
    return 0;
}