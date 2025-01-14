// Количество букв
// В файле .txt считать символьную строку, не более 10 000 символов. Посчитать количество строчных (маленьких) и прописных (больших) букв в введенной строке. 
// Учитывать только английские буквы. Результат записать в файл .txt. 


#include <stdio.h>
#include <ctype.h>

int main(void) {
    FILE *fin, *fout;
    int counter_big = 0;
    int counter_small = 0;
    char c;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    while(((c = getc(fin)) != EOF) && (c != '\n')) {
        if (c != ' ' && ((c >= 'A' && c <= 'Z') || (c >='a' && c <= 'z')))
            (islower(c)) ? counter_small++ : counter_big++;
    }

    fclose(fin);

    fprintf(fout, "%d %d", counter_small, counter_big);

    fclose(fout);

    return 0;
}
