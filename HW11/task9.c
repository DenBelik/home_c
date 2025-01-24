// В программе реализована структура данных:
// struct pack_array {
// uint32_t array; // поле для хранения упакованного массива из 0 и 1
// uint32_t count0 : 8; // счетчик нулей в array
// uint32_t count1 : 8; // счетчик единиц в array
// }
// Необходимо реализовать программу, которая упаковывает переданный ей массив из 32-ух элементов 0 и 1 в указанную структуру данных.

#include <stdio.h>
#include <inttypes.h>

struct pack_array {
    uint32_t array;
    uint32_t count0 : 8;
    uint32_t count1 :8;
};

uint32_t pow_uint(uint32_t val, int st) {
    uint32_t result = 1;

    for (int i = 0; i < st; ++i) {
        result *= val;
    }

    return result;
}


void array2struct(int arr[], struct pack_array *p_a) {
    for (int i = 0; i < 32; ++i) {
        if (arr[i] == 1)
            p_a->count1++;
        else
            p_a->count0++;
        p_a->array += ((uint32_t)arr[i] * pow_uint(2, 31 - i));
    }
}

int main(void) {
    int arr[32];
    struct pack_array p_a;
    p_a.array = 0;
    p_a.count0 = 0;
    p_a.count1 = 0;

    for (int i = 0; i < 32; ++i) {
        scanf("%d", &arr[i]);
    }

    array2struct(arr, &p_a);

    printf("%u %d %d", p_a.array, p_a.count0, p_a.count1);

    return 0;
}