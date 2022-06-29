#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    int value;
    struct linkedListNode *next;
} linkedListNode;

// Simple stack implementation with Linked List
struct stack {
    linkedListNode *top;
    linkedListNode *bottom;
    int length;
};

void stack_init(struct stack *stack) {
    stack->top = NULL;
    stack->bottom = NULL;
    stack->length = 0;

    printf("Stack initialized - Size of %d \n", stack->length);
}

void stack_peek(struct stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        printf("Top of stack: %d\n", stack->top->value);
    }
}

void stack_push(struct stack *stack, linkedListNode *node) {
    if (stack->top == NULL) {
        stack->top = node;
        stack->bottom = node;
        node->next = NULL;
    }
    else {
        linkedListNode *temp = stack->top;
        stack->top = node;
        node->next = temp;
    }
    stack->length++;
    printf("Pushed %d onto stack\n", node->value);
}

void stack_pop(struct stack *stack) {
    if (stack->top == NULL) {
        printf("Stack is empty\n");
    }
    else {
        linkedListNode *temp = stack->top;
        stack->top = stack->top->next;
        stack->length--;
        printf("Popped: %d\n", temp->value);
        free(temp);
        if(stack->length == 0) {
            stack->top = NULL;
            stack->bottom = NULL;
        }
    }
}

void main() {
    struct stack stack;
    stack_init(&stack);
    linkedListNode *node = malloc(sizeof(linkedListNode));
    node->value = 1;
    stack_push(&stack, node);
    stack_peek(&stack);
    stack_pop(&stack);
    stack_peek(&stack);
}