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

// Simple queue implementation with Linked List
struct queue {
    linkedListNode_t *top;
    linkedListNode_t *bottom;
    int length;
};

void queue_init(struct queue *queue) {
    queue->top = NULL;
    queue->bottom = NULL;
    queue->length = 0;

    printf("Queue initialized \n");
}

void queue_enqueue(struct queue *queue, linkedListNode_t *node) {
    if (queue->length == 0) {
        queue->top = node;
        queue->bottom = node;
        node->next = NULL;
    }
    else {
        queue->bottom->next = node;
        queue->bottom = node;
    }
    queue->length++;
    printf("Enqueued %d onto queue\n", node->value);
}

void queue_dequeue(struct queue *queue) {
    if (queue->top == NULL) {
        printf("Queue is empty\n");
    }
    else {
        linkedListNode_t *temp = queue->top;
        queue->top = queue->top->next;
        queue->length--;
        printf("Dequeued: %d\n", temp->value);
        free(temp);
    }
    if(queue->top == queue->bottom) {
        queue->bottom = NULL;
    }
    if(queue->length == 0) {
        queue->top = NULL;
    }
}

void queue_peek(struct queue *queue) {
    if (queue->top == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front of queue: %d\n", queue->top->value);
    }
}

void queue_isEmpty(struct queue *queue) {
    if (queue->top == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is not empty\n");
    }
}

void main() {
    struct queue queue;
    queue_init(&queue);
    linkedListNode_t *node = malloc(sizeof(linkedListNode_t));
    node->value = 1;
    queue_enqueue(&queue, node);
    queue_peek(&queue);
    linkedListNode_t *node2 = malloc(sizeof(linkedListNode_t));
    node2->value = 2;
    queue_enqueue(&queue, node2);
    queue_peek(&queue);
    queue_dequeue(&queue);
    queue_peek(&queue);
    queue_isEmpty(&queue);
    queue_dequeue(&queue);
    queue_isEmpty(&queue);
}