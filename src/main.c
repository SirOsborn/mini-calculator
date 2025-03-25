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

  printf("\033[1;32mWelcome to My Batcave Dungeon Calculator!\033[0m\n");
  printf("=============================================\n");
  printf("Enter your weird math expression like 2+2 or just 'exit' and move on bruv: \n");

  printf("Enter your weird math expression like 2+2 or just 'exit' and move on bruv: ");

  while (1) {
    printf("\n\033[1;34m>>>\033[0m ");

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

    printf("\033[1;33mPostfix expression: %s\033[0m\n", postfix);

    int result = evaluatePostfix(postfix); // evaluate postfix
    printf("\033[1;36mYour result: %d\033[0m\n", result);


    free(postfix);
  }
  return 0;
}
