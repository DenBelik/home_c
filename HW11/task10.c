// Необходимо реализовать программу, которой на входе передаётся вещественное число в типе float, 
// она возвращает порядок который хранится в поле EXP в виде десятичного целого числа. Функция должна строго соответствовать прототипу
// int extractExp(float)

#include <stdio.h>
#include <inttypes.h>

int extractEpx(float num) {
    uint32_t bits = *(uint32_t*)&num;
    int exp = ((bits >> 23) & 0xFF);
    return exp;
}

int main(void) {
    float num;
    scanf("%f", &num);

    printf("%d", extractEpx(num));

    return 0;
}