#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Simple stack implementation
struct stack {
    int *data;
    int size;
    int top;
};

void stack_init(struct stack *stack, int *data, int size) {
    stack->data = data;
    stack->size = size;
    stack->top = -1;

    printf("Stack initialized - Size of %d \n", stack->size);
}

void stack_peek(struct stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Top of stack: %d\n", stack->data[stack->top]);
    }
}

void stack_push(struct stack *stack, int value) {
    if (stack->top == stack->size - 1) {
        printf("Stack is full\n");
    }
    else {
        stack->top++;
        stack->data[stack->top] = value;
        printf("Pushed %d onto stack\n", value);
    }
}

void stack_pop(struct stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
    }
    else {
        printf("Popped: %d\n", stack->data[stack->top]);
        stack->top--;
    }
}

void main() {
    struct stack stack;
    stack_init(&stack, malloc(sizeof(int) * 10), 10);
    stack_push(&stack, 1);
    stack_push(&stack, 2);

    stack_peek(&stack);
    stack_push(&stack, 3);
    stack_push(&stack, 4);
    stack_pop(&stack);
    stack_pop(&stack);

    stack_peek(&stack);
}