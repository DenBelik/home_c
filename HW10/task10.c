// Самое длинное слово
// В файле .txt дана строка слов, разделенных пробелами. Найти самое длинное слово и вывести его в файл .txt. 
// Случай, когда самых длинных слов может быть несколько, не обрабатывать.

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    char max_word[1000] = "";
    int max_len = 0;

    fin = fopen("input.txt", "r");

    fscanf(fin, "%[^\n]", str);

    fclose(fin);

    char *token = strtok(str, " ");

    while (token != NULL) {
        int len = strlen(token);
        if (len > max_len) {
            max_len = len;
            strcpy(max_word, token);
        }
        token = strtok(NULL, " ");
    }
    
    fout = fopen("output.txt", "w");

    fputs(max_word, fout);

    fclose(fout);

    return 0;
}
