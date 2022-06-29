#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Simple queue implementation
struct queue {
    int *data;
    int size;
    int first;
    int last;
};

void queue_init(struct queue *queue, int *data, int size) {
    queue->data = data;
    queue->size = size;
    queue->first = 0;
    queue->last = -1;

    printf("Queue initialized - Size of %d \n", queue->size);
}

void queue_enqueue(struct queue *queue, int value) {
    if (queue->last == queue->size - 1) {
        printf("Queue is full\n");
    }
    else {
        queue->last++;
        queue->data[queue->last] = value;
        printf("Enqueued %d onto queue\n", value);
    }
}

void queue_dequeue(struct queue *queue) {
    if (queue->first == queue->last + 1) {
        printf("Queue is empty\n");
        queue->first = 0;
        queue->last = -1;
    }
    else {
        printf("Dequeued: %d\n", queue->data[queue->first]);
        queue->first++;
    }
}

void queue_peek(struct queue *queue) {
    if (queue->first == queue->last + 1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front of queue: %d\n", queue->data[queue->first]);
    }
}

void queue_isEmpty(struct queue *queue) {
    if (queue->first == queue->last + 1) {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue is not empty\n");
    }
}

void main() {
    struct queue queue;
    queue_init(&queue, malloc(sizeof(int) * 10), 10);
    queue_isEmpty(&queue);
    queue_enqueue(&queue, 1);
    queue_enqueue(&queue, 2);

    queue_peek(&queue);
    queue_enqueue(&queue, 3);
    queue_enqueue(&queue, 4);
    queue_isEmpty(&queue);
    queue_dequeue(&queue);
    queue_dequeue(&queue);
    queue_peek(&queue);
    queue_dequeue(&queue);
    queue_dequeue(&queue);
    queue_isEmpty(&queue);
}
