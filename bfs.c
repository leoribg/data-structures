#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Breadth-first search implementation in C

// Binary Search Tree recursive implementation
 struct binaryTreeNode {
    int value;
    struct binaryTreeNode *left;
    struct binaryTreeNode *right;
};

typedef struct binaryTreeNode binaryTreeNode_t;

binaryTreeNode_t *root; // root of the tree

binaryTreeNode_t *createBinaryTreeNode(int value) {
    binaryTreeNode_t *node = (binaryTreeNode_t *)malloc(sizeof(binaryTreeNode_t));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void binaryTree_init() {
    root = NULL;
}

void binaryTree_insert(binaryTreeNode_t *node) {
    if (root == NULL) {
        root = node;
    } else {
        binaryTreeNode_t *current = root;
        while (true) {
            if (node->value < current->value) {
                if (current->left == NULL) {
                    current->left = node;
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right == NULL) {
                    current->right = node;
                    break;
                } else {
                    current = current->right;
                }
            }
        }
    }
}

void binaryTree_lookup(int value) {
    if (root == NULL) {
        printf("Tree is empty");
    } else {
        binaryTreeNode_t *current = root;
        while (current != NULL) {
            if (current->value == value) {
                printf("Found %d in the tree ", value);
                break;
            } else if (value < current->value) {
                current = current->left;
            } else {
                current = current->right;
            }
        }
        if (current == NULL) {
            printf("Did not find %d in the tree ", value);
        }   
    }
}

void binaryTree_print(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    binaryTree_print(node->left);
    printf("%d ", node->value);
    binaryTree_print(node->right);
}

void binaryTree_printAll() {
    binaryTree_print(root);
}

/**
 * Breadth-first search implementation in C
 * 
 * @param node the root node of the tree
 * @param value the value to search for
 * @return true if the value is found, false otherwise
 */
void bfs(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    binaryTreeNode_t *queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = node;
    while (front != rear) {
        binaryTreeNode_t *current = queue[front++];
        printf("%d ", current->value);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

void dfs(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    dfs(node->left);
    dfs(node->right);
}

void dfsInOrderRecursive(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    dfsInOrderRecursive(node->left);
    printf("%d ", node->value);
    dfsInOrderRecursive(node->right);
}

void dfsPostOrderRecursive(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    dfsPostOrderRecursive(node->left);
    dfsPostOrderRecursive(node->right);
    printf("%d ", node->value);
}

void dfsPreOrderRecursive(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    printf("%d ", node->value);
    dfsPreOrderRecursive(node->left);
    dfsPreOrderRecursive(node->right);
}

void main () {
    binaryTree_init();
    binaryTree_insert(createBinaryTreeNode(100));
    binaryTree_insert(createBinaryTreeNode(2));
    binaryTree_insert(createBinaryTreeNode(30));
    binaryTree_insert(createBinaryTreeNode(44));
    binaryTree_insert(createBinaryTreeNode(75));
    binaryTree_insert(createBinaryTreeNode(16));
    binaryTree_insert(createBinaryTreeNode(71));
    binaryTree_printAll();
    binaryTree_lookup(20);
    binaryTree_lookup(21);

    printf("\n");

    bfs(root);

    printf("\n");

    dfs(root);

    printf("\n");

    dfsInOrderRecursive(root);
    printf("\n");
    dfsPreOrderRecursive(root);
    printf("\n");
    dfsPostOrderRecursive(root);
    printf("\n");
}