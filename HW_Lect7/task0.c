#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

void add_to_list(struct list **head, const char *word) {
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

void swap_elements(struct list *a, struct list *b) {
    char temp[20];
    strcpy(temp, a->word);
    strcpy(a->word, b->word);
    strcpy(b->word, temp);
}

void sort_list(struct list *head) {
    int swapped;
    struct list *ptr1;
    struct list *lptr = NULL;
    
    if (head == NULL)
        return;
    
    do {
        swapped = 0;
        ptr1 = head;
        
        while (ptr1->next != lptr) {
            if (strcmp(ptr1->word, ptr1->next->word) > 0) {
                swap_elements(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void print_list(struct list *head) {
    struct list *temp = head;
    while (temp != NULL) {
        printf("%s ", temp->word);
        temp = temp->next;
    }
    printf("\n");
}

void delete_list(struct list **head) {
    struct list *current = *head;
    struct list *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    *head = NULL;
}

int main() {
    struct list *head = NULL;
    char input[1000], *word;
    
    fgets(input, sizeof(input), stdin);
    
    word = strtok(input, " .\n");
    while (word != NULL) {
        add_to_list(&head, word);
        word = strtok(NULL, " .\n");
    }
    
    sort_list(head);
    print_list(head);
    delete_list(&head);
    
    return 0;
}
