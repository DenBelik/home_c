#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int key;
    struct tree *left, *right;
    struct tree *parent;
} tree;

tree* create_node(int key) {
    tree *new_node = (tree*)malloc(sizeof(tree));
    new_node->key = key;
    new_node->left = new_node->right = new_node->parent = NULL;
    return new_node;
}

void insert(tree **root, int key) {
    if (*root == NULL) {
        *root = create_node(key);
        return;
    }

    tree *current = *root;
    tree *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    tree *new_node = create_node(key);
    new_node->parent = parent;

    if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
}

tree* findBrother(tree *root, int key) {
    if (root == NULL) return NULL;

    tree *current = root;
    while (current != NULL && current->key != key) {
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL || current->parent == NULL) {
        return NULL;
    }

    tree *parent = current->parent;
    if (parent->left == current && parent->right != NULL) {
        return parent->right;
    } else if (parent->right == current && parent->left != NULL) {
        return parent->left;
    }

    return NULL;
}

void free_tree(tree *root) {
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    tree *root = NULL;
    int keys[] = {10, 5, 15, 3, 7, 13, 18, 1, 6, 14, 0};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insert(&root, keys[i]);
    }

    int key_to_find = 3;
    tree *brother = findBrother(root, key_to_find);
    if (brother) {
        printf("Brother of %d is %d\n", key_to_find, brother->key);
    } else {
        printf("%d has no brother or does not exist in the tree\n", key_to_find);
    }

    free_tree(root);
    return 0;
}
