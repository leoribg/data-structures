#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

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
        printf("Tree is empty\n");
    } else {
        binaryTreeNode_t *current = root;
        while (current != NULL) {
            if (value < current->value) {
                current = current->left;
            } else if (value > current->value) {
                current = current->right;
            } else {
                printf("Found %d\n", current->value);
                return;
            }
        }
        printf("%d not found\n", value);
    }
}

void binaryTree_print(binaryTreeNode_t *node) {
    if (node == NULL) {
        return;
    }
    printf("Value: %d\n", node->value);
    printf("Left: ");
    printf("%d\n", node->left == NULL ? -1 : node->left->value);
    printf("Right: ");
    printf("%d\n", node->right == NULL ? -1 : node->right->value);
    binaryTree_print(node->left);
    binaryTree_print(node->right);
}

void binaryTree_delete(binaryTreeNode_t *node)
{
    if (node == NULL)
    {
        return;
    }
    binaryTreeNode_t *parent = NULL;
    binaryTreeNode_t *current = root;
    while (current != NULL)
    {
        if (node->value < current->value)
        {
            parent = current;
            current = current->left;
        }
        else if (node->value > current->value)
        {
            parent = current;
            current = current->right;
        }
        else
        {
            // found node, delete it
            if (current->left == NULL && current->right == NULL)
            {
                // no children
                if (parent == NULL)
                {
                    // root node
                    root = NULL;
                }
                else if (parent->left == current)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            else if (current->left != NULL && current->right == NULL)
            {
                // left child only
                if (parent == NULL)
                {
                    // root node
                    root = current->left;
                }
                else if (parent->left == current)
                {
                    parent->left = current->left;
                }
                else
                {
                    parent->right = current->left;
                }
            }
            else if (current->left == NULL && current->right != NULL)
            {
                // right child only
                if (parent == NULL)
                {
                    // root node
                    root = current->right;
                }
                else if (parent->left == current)
                {
                    parent->left = current->right;
                }
                else
                {
                    parent->right = current->right;
                }
            }
            else
            {
                // two children
                binaryTreeNode_t *successor = current->right;
                while (successor->left != NULL)
                {
                    successor = successor->left;
                }
                break;
            }
        }
    }
}

void main()
{
    binaryTree_init();
    binaryTreeNode_t *node1 = createBinaryTreeNode(9);
    binaryTreeNode_t *node2 = createBinaryTreeNode(4);
    // binaryTreeNode_t *node3 = createBinaryTreeNode(20);
    // binaryTreeNode_t *node4 = createBinaryTreeNode(1);
    // binaryTreeNode_t *node5 = createBinaryTreeNode(6);
    // binaryTreeNode_t *node6 = createBinaryTreeNode(15);
    // binaryTreeNode_t *node7 = createBinaryTreeNode(170);

    binaryTree_insert(node1);
    binaryTree_insert(node2);
    // binaryTree_insert(node3);
    // binaryTree_insert(node4);
    // binaryTree_insert(node5);
    // binaryTree_insert(node6);
    // binaryTree_insert(node7);

    binaryTree_delete(node2);

    binaryTree_print(root);
}