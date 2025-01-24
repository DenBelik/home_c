// На вход программе подается беззнаковое 32-битное целое число N и натуральное число K (1 ≤ K ≤ 31). 
// Требуется взять K подряд идущих битов числа N так, чтобы полученное число было максимальным. Программа должна вывести полученное число.

#include <inttypes.h>
#include <stdio.h>

int main(void) {
    uint32_t n, k;
    scanf("%u%u", &n, &k);

    uint32_t max = 0;
    uint32_t bits = 32;

    for (int i = 0; i <= bits; ++i) {
        uint32_t temp = (n >> i) & ((1U << k) - 1);
        if (temp > max) 
            max = temp;
    }

    printf("%u\n", max);

    return 0;
}
