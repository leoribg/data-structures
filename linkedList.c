#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

struct linkedListNode {
    int value;
    struct linkedListNode *next;
};

typedef struct linkedListNode linkedListNode_t;
linkedListNode_t *head;
linkedListNode_t *tail;

void linkedList_init() {
    head = NULL;
    tail = NULL;
}

void linkedList_add(linkedListNode_t *node, int value) {
    node->value = value;
    node->next = NULL;

    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
}

void linkedList_insert_at_head(linkedListNode_t *node) {
    node->next = head;
    head = node;
}

void linkedList_insert_at_index(linkedListNode_t *node, int index) {
    linkedListNode_t *current = head;
    linkedListNode_t *previous = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        printf("i: %d\n", i);
        previous = current;
        current = current->next;
        printf("%d\n", current->value);
        i++;
    }

    if (current == NULL) {
        /* Add to the end of the list */
        linkedList_add(node, node->value);
    }
    else {
        /* Insert the node before the current node */
        node->next = current;
        if (previous == NULL) {
            /* Insert at the head */
            head = node;
        }
        else {
            /* Insert the node after previous node */
            previous->next = node;
        }
    }
}

void linkedList_remove_at_index(int index) {
    linkedListNode_t *current = head;
    linkedListNode_t *previous = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        /* Nothing to remove */
    }
    else {
        /* Remove the node */
        if (previous == NULL) {
            /* Remove at the head */
            head = current->next;
        }
        else {
            /* Remove current node */
            previous->next = current->next;
        }
    }
}

linkedListNode_t * linkedList_insert_after_node(linkedListNode_t *node_after, linkedListNode_t *node_to_insert) {
    node_to_insert->next = node_after->next;
    node_after->next = node_to_insert;
    return node_to_insert;
}

linkedListNode_t * linkedList_find(int value) {
    linkedListNode_t *node = head;
    while (node != NULL) {
        if (node->value == value) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

void linkedList_reverse() {
    linkedListNode_t *current = head;
    linkedListNode_t *previous = NULL;
    linkedListNode_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}

void print_linkedList() {
    linkedListNode_t *node = head;
    while (node != NULL) {
        printf("%d - ", node->value);
        node = node->next;
    }
    printf("NULL");
    printf("\n");
}

int main() {
    linkedListNode_t node1;
    linkedListNode_t node2;
    linkedListNode_t node3;
    linkedListNode_t node4;

    /* Init list */
    linkedList_init();

    /* Add them to the list */
    linkedList_add(&node3, 3);
    linkedList_add(&node2, 2);
    linkedList_add(&node1, 1);


    /* Insert at head */
    node4.value = 4;
    linkedList_insert_at_head(&node4);

    /* Print the list */
    print_linkedList();

    /* Find a node */
    linkedListNode_t *found = linkedList_find(3);
    if (found != NULL) {
        printf("Found node with value %d\n", found->value);
    }
    else {
        printf("Could not find node with value 3\n");
    }

    /* Insert after node */
    linkedListNode_t *node_temp;
    linkedListNode_t node5;
    node5.value = 5;
    node_temp = linkedList_insert_after_node(&node2, &node5);
    printf("Inserted node with value %d after node with value %d\n", node_temp->value, node2.value);

    /* Insert at index */
    linkedListNode_t node6;
    node6.value = 6;
    linkedList_insert_at_index(&node6, 3);

    /* Remove at index */
    linkedList_remove_at_index(3);

    /* Print the list */
    print_linkedList();

    /* Reverse the list */
    linkedList_reverse();

    /* Print the list */
    print_linkedList();

    return 0;
}