// Вид сверху

// В программе описана структура для хранения двоичного дерева:
// typedef struct tree {
// datatype key;
// struct tree *left, *right;
// } tree;
// Необходимо реализовать функцию, которая печатает вид дерева сверху. Функция должна строго соответствовать прототипу:

// void btUpView(tree *root)


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
} tree;

typedef struct QueueNode {
    tree *node;
    int hd;
} QueueNode;

tree* newNode(int key) {
    tree* node = (tree*)malloc(sizeof(tree));
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void btUpView(tree *root) {
    if (root == NULL) return;

    QueueNode *queue = (QueueNode*)malloc(1000 * sizeof(QueueNode));
    int front = 0, rear = 0;

    int *map = (int*)malloc(1000 * sizeof(int));
    for (int i = 0; i < 1000; i++) {
        map[i] = INT_MIN;
    }

    queue[rear].node = root;
    queue[rear].hd = 0;
    rear++;

    while (front < rear) {
        QueueNode current = queue[front];
        front++;

        tree *node = current.node;
        int hd = current.hd;

        if (map[hd + 500] == INT_MIN) {
            map[hd + 500] = node->key;
        }

        if (node->left != NULL) {
            queue[rear].node = node->left;
            queue[rear].hd = hd - 1;
            rear++;
        }

        if (node->right != NULL) {
            queue[rear].node = node->right;
            queue[rear].hd = hd + 1;
            rear++;
        }
    }

    for (int i = 0; i < 1000; i++) {
        if (map[i] != INT_MIN) {
            printf("%d ", map[i]);
        }
    }

    free(queue);
    free(map);
}

int main() {
    tree *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->left = newNode(13);
    root->right->right = newNode(18);
    root->left->left->left = newNode(1);
    root->left->right->left = newNode(6);
    root->right->left->right = newNode(14);

    btUpView(root);

    return 0;
}