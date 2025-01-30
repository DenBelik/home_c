// Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется. 
// Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.

#include <inttypes.h>

typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t totalMemoryUsage(list *head) {
    if (head == NULL)
        return 0;

    size_t memory = 0;

    list *curr = head;

    while (curr != NULL) {
        memory += curr->size;
        curr = curr->next;
    }

    return memory;
}