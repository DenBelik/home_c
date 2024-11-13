#include <stdio.h>
#include <inttypes.h>

int NOD(int a, int b) {
        while (b) {
        int buf = b;
        b = a % b;
        a = buf;
    }
    return a;
}

int main(void) {   
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", NOD(a, b));
}