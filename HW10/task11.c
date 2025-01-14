// Заканчивается на a
// В файле .txt дано предложение. Необходимо определить, сколько слов заканчиваются на букву 'а'. 
// Ответ записать в файл .txt. 

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    char c;
    int size = 0;   
    int counter = 0;

    fin = fopen("input.txt", "r");

    while(((c = getc(fin)) != EOF) && (c != '\n')) {
        str[size++] = c;
    }

    char *token;
    
    token = strtok(str, " ");
    
    while(token != NULL) {
        if (token[strlen(token) - 1] == 'a') counter++;
        token = strtok(NULL, " ");
    }
    
    fout = fopen("output.txt", "w");
    
    fprintf(fout, "%d", counter);
    
    fclose(fin);
    fclose(fout);
    
    return 0;
}
