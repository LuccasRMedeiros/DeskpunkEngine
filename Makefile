# Deskpunk makefile to build the engine for linux
#
# To build just run "make" and it will generate everything for the engine.

NAME = deskpunk

CC = gcc

DEBUG = -g -fsanitize=address

FLAGS = -Wall -Wextra -Werror

BUILD = build

EXAMPLE = example_sdl_opengl.c

SOURCE = 

INCLUDES = 

LIBS = 

OBJECTS = $(addprefix $(BUILD)/, $(SOURCE:%.c=%.o))

COMPILE_RULES = 

all: compile_normal $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILE_RULES) $(OBJECTS) $(LIBS) main.c -o $@

example: compile_debug $(EXAMPLE)

$(EXAMPLE): $(OBJECTS) example_sdl_opengl.c
	$(COMPILE_RULES) $(OBJECTS) $(LIBS) $@ -o $(NAME)_example

$(BUILD)/%.o: %.c
	mkdir -p $(BUILD)
	$(COMPILE_RULES) $< -c -o $@

compile_normal:
	$(COMPILE_RULES) = $(CC) $(FLAGS) $(INCLUDES)

compile_debug:
	$(COMPILE_RULES) = $(CC) $(DEBUG) $(FLAGS) $(INCLUDES)

.PHONY: all example
