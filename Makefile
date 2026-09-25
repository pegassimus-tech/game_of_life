CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lncurses


BUILD_DIR = ./build
TARGET = $(BUILD_DIR)/game_of_life

all: game_of_life

game_of_life:
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) game_of_life.c utilities.c game_functions.c render.c -o $(TARGET) $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

re: clean all

.PHONY: all clean re
