# Mini Calculator

This is my Data Structures & Algorithms Class' mini project for my first term of second year at CamTech. Which is a terminal-based calculator program written in C. It is designed to evaluate mathematical expressions using the the legendary  precedence **Shunting Yard Algorithm** for converting infix expressions to postfix and then evaluating them. The project is organized into a structured hierarchy for better maintainability and scalability.

## Project Structure

The project is organized as follows:

```
mini-calculator/
├── include/
│   └── calculator.h       # Header file for calculator logic
├── src/
│   ├── calculator.c       # Core logic for infix-to-postfix conversion and evaluation
│   ├── main.c             # Terminal-based input/output logic
│   ├── stack.c            # Stack implementation for memory optimization
│   └── stack.h            # Header file for stack implementation
├── Makefile               # Build system for compiling the project
└── README.md              # Project documentation
```

## Features

- **Infix to Postfix Conversion**: Uses the Shunting Yard Algorithm to convert infix expressions to postfix notation.
- **Postfix Evaluation**: Evaluates the postfix expression to compute the result.
- **Stack Optimization**: Implements a stack for efficient memory management during expression evaluation.
- **Terminal-Based Interface**: Accepts user input and displays results in the terminal.

## Requirements

- GCC (GNU Compiler Collection)
- `make` build tool

## How to Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/SirOsborn/mini-calculator.git
   cd mini-calculator
   ```

2. Build the project using `make`:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./mini_calculator
   ```

4. Clean up build files:
   ```bash
   make clean
   ```

## How It Works

1. The user inputs a mathematical expression in infix notation (e.g., `3 + 4 * 2 / ( 1 - 5 )`).
2. The program converts the infix expression to postfix notation using the Shunting Yard Algorithm.
3. The postfix expression is evaluated using a stack-based approach to compute the result.
4. The result is displayed in the terminal.
5. To exit just type `exit`.

## Files Overview

- **`calculator.h`**: Header file for the calculator logic.
- **`calculator.c`**: Contains the implementation of the infix-to-postfix conversion and postfix evaluation.
- **`main.c`**: Handles user input and output in the terminal.
- **`stack.c`**: Implements a stack for efficient memory management during evaluation.
- **`stack.h`**: Header file for the stack implementation.
- **`Makefile`**: Automates the build process for compiling the project.

## Algorithm Used

The project uses the **Shunting Yard Algorithm**, which is an efficient method for parsing mathematical expressions specified in infix notation. It converts the expression to postfix notation, which is easier to evaluate programmatically.

## Contributing

Feel free to fork the repository and submit pull requests for improvements or bug fixes.

## License

This project is open-source and available under the MIT License.