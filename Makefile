# Deskpunk makefile to build the engine for linux
#
# To build just run "make" and it will generate everything for the engine.

NAME = deskpunk

EXAMPLE = $(NAME)_example

CC = gcc

# Set it at compile time if needed
DEBUG =

FLAGS = -Wall -Wextra -Werror -std=c11

BUILD = build

SOURCE = $(wildcard src/*.c)

INCLUDES = -I ./src

LIBS = -lSDL2 -lSDL2main

OBJECTS = $(addprefix $(BUILD)/, $(SOURCE:src/%.c=%.o))

COMPILE_RULES = $(CC) $(DEBUG) $(FLAGS) $(INCLUDES)

all: mkdbuild $(NAME)

$(NAME): $(OBJECTS)
	$(COMPILE_RULES) main.c $(OBJECTS) $(LIBS) -o $(NAME)

example: mkdbuild $(EXAMPLE)
	
$(EXAMPLE): $(OBJECTS)
	$(COMPILE_RULES) example_sdl_opengl.c $(OBJECTS) $(LIBS) -o $(NAME)_example

$(BUILD)/%.o: src/%.c
	$(COMPILE_RULES) $< -c -o $@

mkdbuild:
	mkdir -p $(BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_example

clean:
	rm -rf $(BUILD)

re: fclean all

reexample: fclean example

log_vars:
	@echo "================"
	@echo "\033[1;32mNAME:           \033[0;32m"$(NAME)
	@echo "\033[1;32mEXAMPLE:        \033[0;32m"$(EXAMPLE)
	@echo "\033[1;32mCC:             \033[0;32m"$(CC)
	@echo "\033[1;32mDEBUG:          \033[0;32m"$(DEBUG)
	@echo "\033[1;32mFLAGS:          \033[0;32m"$(FLAGS)
	@echo "\033[1;32mBUILD:          \033[0;32m"$(BUILD)
	@echo "\033[1;32mSOURCE:         \033[0;32m"$(SOURCE)
	@echo "\033[1;32mINCLUDES:       \033[0;32m"$(INCLUDES)
	@echo "\033[1;32mLIBS:           \033[0;32m"$(LIBS)
	@echo "\033[1;32mOBJECTS:        \033[0;32m"$(OBJECTS)
	@echo "\033[1;32mCOMPILES_RULES: \033[0;32m"$(COMPILE_RULES)
	@echo "\033[0m================"

.PHONY: all example clean fclean re
