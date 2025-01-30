// Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
// Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0. 
// Если есть несколько таких блоков, то вернуть адрес любого из них.

#include <inttypes.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head) {
    if (head == NULL)
        return 0;

    uint64_t max_address = head->address;
    size_t max_size = head->size;

    list *curr = head->next;

    while(curr != NULL) {
        if (curr->size > max_size) {
            max_size = curr->size;
            max_address = curr->address;
        }
        curr = curr->next;
    }

    return max_address;
}