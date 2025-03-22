//
// Created by SamDachOsborn on 3/22/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.h"

#define MAX_INPUT_LENGTH 256

int main() {
  char input[MAX_INPUT_LENGTH];

  printf("Wellcome Homies to My Batcave Dungeon Calculator!\n");
  printf("Enter your weird math expression like 2+2 or just 'exit' and move on bruv: ");

  while (1) {
    printf("\n>>>");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';  // remove trailing newline character

    if (strcmp(input, "exit") == 0) {
      printf("Goodbye broooooo!\n");
      break;
    }

    // processing input
    char *postfix = infixToPostfix(input); // convert infix to postfix
    if (!postfix) {
      printf("Error dawgg! I just cant :// \n");
      continue;
    }

    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix(postfix); // evaluate postfix
    printf("Your damn result: %d\n", result);

    free(postfix);
  }
  return 0;
}