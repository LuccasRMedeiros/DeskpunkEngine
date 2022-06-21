# Deskpunk makefile to build the engine for linux
#
# To build just run "make" and it will generate everything for the engine.

NAME = deskpunk

CC = gcc

# Set it at compile time if needed
DEBUG =

FLAGS = -Wall -Wextra -Werror -std=c99

BUILD = build

EXAMPLE = example_sdl_opengl.c

SOURCE = 

INCLUDES = 

LIBS = -lSDL2 -lSDL2main

OBJECTS = $(addprefix $(BUILD)/, $(SOURCE:%.c=%.o))

COMPILE_RULES = $(CC) $(DEBUG) $(FLAGS) $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILE_RULES) $(OBJECTS) $(LIBS) main.c -o $(NAME)

example: $(OBJECTS)
	$(COMPILE_RULES) $(OBJECTS) $(EXAMPLE) $(LIBS) -o $(NAME)_example

$(BUILD)/%.o: %.c
	mkdir -p $(BUILD)
	$(COMPILE_RULES) $< -c -o $@

fclean: clean
	rm -f $(NAME)

clean:
	rm -rf $(BUILD)

re: fclean all

.PHONY: all example clean fclean re
