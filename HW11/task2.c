// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
// Требуется циклически сдвинуть биты числа N вправо на K битов и вывести полученное таким образом число.

#include <stdio.h>
#include <inttypes.h>

int main(void) {
    uint32_t n, k;
    scanf("%u%u", &n, &k);

    uint32_t bits = 32;

    k %= 32;

    uint32_t result = (n >> k) | (n << (bits - k));

    printf("%u", result);

    return 0;
}