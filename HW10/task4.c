// По одному разу
// В файле .txt даны два слова не более 100 символов каждое, разделенные одним пробелом. 
// Найдите только те символы слов, которые встречаются в обоих словах только один раз. 
// Напечатайте их через пробел в файл .txt в лексикографическом порядке. 

#include <stdio.h>

int main(void) {
    FILE *fin, *fout;
    char first[100], second[100];
    int count_first = 0;
    int count_second = 0;
    char c;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    while (((c = getc(fin)) != ' ') && (c != EOF)) {
        first[count_first++] = c;
    }

    while (((c = getc(fin)) != EOF) && (c != '\n')) {
        second[count_second++] = c;
    }

    fclose(fin);

    for (int i = 0; i < count_first; ++i) {
        int counter_f = 0;
        int counter_s = 0;

        for (int j = 0; j < count_first; ++j) {
            if (first[i] == first[j]) counter_f++;
        }

        if (counter_f != 1) continue;

        for (int j = 0; j < count_second; ++j) {
            if (first[i] == second[j]) counter_s++;
        }

        if (counter_s == 1) fprintf(fout, "%c ", first[i]);
    }

    fclose(fout);

    return 0;
}
