// Пары соседних символов
// В файле .txt записаны символы. Необходимо разработать функцию, которая меняет местами пары соседних символов не обращая внимание на символы пробел. 
// Если количество символов нечетно (пробелы не считаем), то последний символ не меняем. Результат записать в файл .txt. 

#include <stdio.h>
#include <string.h>

void swap_char(char str[], int index1, int index2) {
    char buf = str[index2];
    str[index2] = str[index1];
    str[index1] = buf;
}

int main(void) {
    FILE *fin, *fout;
    char str[1001];
    int indexes[1001];
    int counter = 0;

    fin = fopen("input.txt", "r");
    fgets(str, sizeof(str), fin);
    
    fclose(fin);

    str[strcspn(str, "\n")] = 0;
    int len = strlen(str);

    for (int i = 0; i < len; ++i) {
        if (str[i] != ' ') {
            indexes[counter++] = i;
        }
    }

    int temp = 0;

    while (temp + 1 < counter) {
        swap_char(str, indexes[temp], indexes[temp + 1]);
        temp += 2;
    }
    
       
    //printf("%s", str);
    
    fout = fopen("output.txt", "w");

    fprintf(fout, "%s", str);
    
    fclose(fout);

    return 0;

}
