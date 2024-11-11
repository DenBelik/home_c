#include <stdio.h>
#include <ctype.h>

int main(void) {
    char text[100];
    fgets(text, sizeof(text), stdin);
    
    for (int i = 0; i < sizeof(text); ++i) {
        if (text[i] != '.') {
            if (isupper(text[i])) text[i] = tolower(text[i]);
        } else {
            text[i] = ' ';
        }
    }
    printf("%s", text);
}