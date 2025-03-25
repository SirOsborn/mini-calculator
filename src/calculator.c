//
// Created by SamDachOsborn on 3/22/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculator.h"
#include "stack.h"

#define MAX_EXPRESSION_LENGTH 256

// function to determine the procedence of operators
int precedence(char operator) {
  switch (operator) {
    case '+':
    case '-':
      return 1; // lowest
    case '*':
    case '/':
      return 2; // higher
    case '^':
      return 3; // highest
    default:
      return 0; // invalid
  }
}

// helper function checking if a char is an op
int isOperator(char c) {
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// convert infix to postfix (Shunting Yard Alg
char *infixToPostfix(const char *infix) { 
  // Function to convert infix expression to postfix notation
  // Handles negative numbers and multi-digit numbers

  Stack *operators = createStack(MAX_EXPRESSION_LENGTH);
  char *postfix = (char *)malloc(MAX_EXPRESSION_LENGTH * sizeof(char));
  int j = 0; // output index

  for (int i = 0; infix[i] != '\0'; i++) { // Fixed condition
    char c = infix[i];

    if (isspace(c)) {
      continue; // ignore whitespace
    }

    if (isdigit(c) || (c == '-' && (i == 0 || infix[i-1] == '(' || isOperator(infix[i-1])))) { // Handle negative numbers
      // Read the entire number (multi-digit)
      int num = 0;
      while (isdigit(c)) {
        num = num * 10 + (c - '0');
        c = infix[++i];
      }
      postfix[j++] = num; // Store the number in postfix
      i--; // Adjust index since the for loop will increment it

    } else if (c == '(') { // if open paren push to stack
      push(operators, c);
    } else if (c == ')') { // pop till open paren
      while (!isEmpty(operators) && peek(operators) != '(') {
        postfix[j++] = pop(operators);
      }
      if (!isEmpty(operators) && peek(operators) == '(') {
        pop(operators);
      } else {
        printf("Error dawgg! Unmatched parenthesis:>\n");
        free(postfix);
        freeStack(operators);
        return NULL;
      }
    } else if (isOperator(c)) { // Pop op of higher or equal precedence
      while (!isEmpty(operators) && precedence(peek(operators)) >= precedence(c)) { 
        // Pop operators from the stack to the output

        postfix[j++] = pop(operators);
      }
      push(operators, c);
    } else {
      printf("Error dawgg! Invalid character:>\n");
      free(postfix);
      freeStack(operators);
      return NULL;
    }
  }

  // pop remaining operators
  while (!isEmpty(operators)) {
    char op = pop(operators);
    if (op == '(' || op == ')') {
      printf("Error dawgg! Unmatched parenthesis:>\n");
      free(postfix);
      freeStack(operators);
      return NULL;
    }
    postfix[j++] = op;
  }
  postfix[j] = '\0'; // terminate string
  freeStack(operators);
  return postfix;
}

// evaluate postfix
int evaluatePostfix(const char *postfix) { 
  // Function to evaluate a postfix expression
  // Handles multi-digit numbers

  Stack *values = createStack(MAX_EXPRESSION_LENGTH);

  for (int i = 0; postfix[i] != '\0'; i++) {
    char c = postfix[i];

    if (isdigit(c)) {
      // push digit to stack
      // Push multi-digit numbers onto the stack
      int num = 0;
      while (isdigit(c)) {
        num = num * 10 + (c - '0');
        c = postfix[++i];
      }
      push(values, num); // Push the complete number onto the stack
      i--; // Adjust index since the for loop will increment it

    } else if (isOperator(c)) {
      // pop two values from stack and apply operator
      int b = pop(values);
      int a = pop(values);

      switch (c) {
        case '+': push(values, a + b); break;
        case '-': push(values, a - b); break;
        case '*': push(values, a * b); break;
        case '/':
          if (b == 0) { // Added division by zero check
            printf("Error dawgg! Division by zero:>\n");
            freeStack(values);
            return 0;
          }
          push(values, a / b);
          break;
        case '^': {
          int result = 1; // Fixed scope of result variable
          for (int j = 0; j < b; j++) {
            result *= a;
          }
          push(values, result);
          break;
        }
      }
    }
  }

  int result = pop(values);
  freeStack(values);
  return result;
}
