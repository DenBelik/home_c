// На вход программе подается беззнаковое 32-битное целое число N. Требуется найти количество единичных битов в двоичном представлении данного числа.

#include <stdio.h>
#include <inttypes.h>

int main(void) {
    uint32_t n;
    scanf("%u", &n);
    int counter = 0;

    while (n) {
        counter += n & 1;
        n >>= 1;
    }

    printf("%d", counter);

    return 0;
}