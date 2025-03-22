CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
SRC = src/calculator.c src/main.c src/stack.c
OBJ = $(SRC:.c=.o)
TARGET = mini_calculator

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
