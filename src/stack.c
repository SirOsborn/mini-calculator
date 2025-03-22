//
// Created by SamDachOsborn on 3/22/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *createStack(int size) {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  if (!stack) {
    fprintf(stderr, "Failed to allocate memory for stack\n");
    exit(EXIT_FAILURE);
  }
  stack->data = (int *)malloc(size * sizeof(int)); // Fixed memory allocation
  stack->top = -1;
  stack->maxSize = size;
  return stack;
}

void push(Stack *stack, int value) {
  if (stack->top == stack->maxSize - 1) {
    fprintf(stderr, "Stack is overflow\n");
    return;
  }
  stack->data[++stack->top] = value;
}

int pop(Stack *stack) {
  if (stack->top == -1) {
    fprintf(stderr, "Stack is underflow\n");
    return -1;
  }
  return stack->data[stack->top--];
}

int peek(Stack *stack) {
  if (stack->top == -1) {
    fprintf(stderr, "Stack is empty\n");
    return -1;
  }
  return stack->data[stack->top];
}

int isEmpty(Stack *stack) {
  return stack->top == -1;
}

void freeStack(Stack *stack) {
  free(stack->data);
  free(stack);
}