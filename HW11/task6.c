// На вход программе подается беззнаковое 32-битное целое число N. 
// Требуется изменить значения всех битов старшего байта числа на противоположные и вывести полученное таким образом число.

#include <stdio.h>
#include <inttypes.h>

int main(void) {
    uint32_t n;
    scanf("%u", &n);

    uint32_t mask = 0xFF000000;

    uint32_t result = n ^ mask;

    printf("%u", result);

    return 0;
}