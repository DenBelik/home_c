// Проверка на палиндром
// Считать предложение из файла .txt и определить можно ли из английских букв предложения записанного в файле получить одно слово - палиндром. 
// Ответ напечатать на стандартный поток вывода. Требуется реализовать логическую функцию и применить ее.

#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdbool.h>

bool is_palindrome(char str[]) {
    int count[256] = {0};

    for (int i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'A' && str[i] <= 'z') count[(uint8_t)str[i]]++;
    }

    int counter = 0;

    for (int i = 0; i < 256; ++i) {
        if (count[i] % 2 == 1) counter++;
        //printf("symbol = %c  counter = %d\n",(char)i, counter);
        if (counter > 1) return false;
    }
    
    return true;
}

int main(void) {
    FILE *fin;
    char str[1001];

    fin = fopen("input.txt", "r");

    fgets(str, sizeof(str), fin);

    fclose(fin);

    printf("%s", is_palindrome(str) ? "YES" : "NO");

    return 0;
}
