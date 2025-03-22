//
// Created by SamDachOsborn on 3/22/2025.
//

#ifndef STACK_H
#define STACK_H

typedef struct Stack {
  int *data;
  int top;
  int maxSize;
} Stack;

Stack *createStack(int Size);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
void freeStack(Stack *stack);

#endif //STACK_H
