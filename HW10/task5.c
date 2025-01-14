// Заменить a на b
// В файле .txt дана символьная строка не более 1000 символов. 
// Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в .txt. 

#include <stdio.h>

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    int count = 0;
    char c;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    while(((c = getc(fin)) != EOF) && (c != '\n')) {
        str[count++] = c;
    }

    fclose(fin);

    for (int i = 0; i < count; ++i) {
        switch (str[i])
        {
        case 'a':
            str[i] = 'b';
            break;
        case 'b':
            str[i] = 'a';
            break;
        case 'A':
            str[i] = 'B';
            break;
        case 'B':
            str[i] = 'A';
            break;
        default:
            break;
        }

        fprintf(fout, "%c", str[i]);
    }

    fclose(fout);

    return 0;
}
