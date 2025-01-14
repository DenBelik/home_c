// Soundex
// Известный алгоритм Soundex (https://ru.wikipedia.org/wiki/Soundex) определяет, похожи ли два английских слова по звучанию. 
// На вход он принимает слово и заменяет его на некоторый четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило, звучат похоже.

// Вам требуется реализовать этот алгоритм. Он работает так:
// Первая буква слова сохраняется.
// В остальной части слова:

// буквы, обозначающие, как правило, гласные звуки: a, e, h, i, o, u, w и y — отбрасываются; 
// оставшиеся буквы (согласные) заменяются на цифры от 1 до 6, причём похожим по звучанию буквам соответствуют одинаковые цифры:

// 1: b, f, p, v
// 2: c, g, j, k, q, s, x, z
// 3: d, t
// 4: l
// 5: m, n
// 6: r

// Любая последовательность одинаковых цифр сокращается до одной такой цифры. Итоговая строка обрезается до первых четырёх символов. 
// Если длина строки меньше требуемой, недостающие символы заменяются знаком 0.


#include <stdio.h>
#include <string.h>
#include <ctype.h>

char get_code(char c) {
    switch(c) {
        case 'b': case 'f': case 'p': case 'v': return '1';
        case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z': return '2';
        case 'd': case 't': return '3';
        case 'l': return '4';
        case 'm': case 'n': return '5';
        case 'r': return '6';
        default: return '0';
    }
}

int main(void) {
    FILE *fin, *fout;
    char str[21];

    fin = fopen("input.txt", "r");

    fgets(str, sizeof(str), fin);
    printf("str[0] = %c\n", str[0]);
    str[strcspn(str, "\n")] = 0;

    char temp[21];
    
    temp[0] = str[0];
    int size = 1;

    for (int i = 1; i < strlen(str); ++i) {
        if (get_code(str[i]) != '0') temp[size++] = get_code(str[i]);
    }
    
    temp[size] = '\0';
    
    char result[21] = {0};
    result[0] = temp[0];
    int res_size = 1;
    
    int counter = 1;
    
    printf("%c\n", result[5]);
        
    while (res_size < 4 && counter < size) {
        if (temp[counter] != temp[counter + 1]) {
            result[res_size++] = temp[counter];
            counter++;
        } else {
            counter++;
        }
    }
    
    while (res_size < 4) { 
        result[res_size++] = '0'; 
    } 
    
    result[res_size] = '\0';
    
    fout = fopen("output.txt", "w");
    
    fprintf(fout, "%s", result);

    return 0;
}
