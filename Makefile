# Deskpunk makefile to build the engine for linux
#
# To build just run "make" and it will generate everything for the engine.

NAME = deskpunk

CC = gcc

# Set it at compile time if needed
DEBUG =

FLAGS = -Wall -Wextra -Werror

SOURCE = $(wildcard src/*.c)

INCLUDES = -I ./src 

LIBS = -lSDL2 -lSDL2main -lvulkan

OBJECTS = $(addprefix build/, $(SOURCE:src/%.c=%.o))

COMPILE_RULES = $(CC) $(DEBUG) $(FLAGS)

all: build_dir $(OBJECTS)
	$(COMPILE_RULES) ./main.c $(OBJECTS) $(LIBS) -o $(NAME)

example: build_dir $(OBJECTS)
	$(COMPILE_RULES) -std=c11 $(INCLUDES) example_sdl_opengl.c $(OBJECTS) $(LIBS) -o $(NAME)_example

build/%.o: src/%.c
	$(COMPILE_RULES) -std=c11 $(INCLUDES) $< -c -o $@

build_dir:
	mkdir -p build

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME)_example

clean:
	rm -rf build

re: fclean all

reexample: fclean example

log_vars:
	@echo "================"
	@echo "\033[1;42mNAME:           \033[0;32m"$(NAME)
	@echo "\033[1;42mEXAMPLE:        \033[0;32m"$(EXAMPLE)
	@echo "\033[1;42mCC:             \033[0;32m"$(CC)
	@echo "\033[1;42mDEBUG:          \033[0;32m"$(DEBUG)
	@echo "\033[1;42mFLAGS:          \033[0;32m"$(FLAGS)
	@echo "\033[1;42mBUILD:          \033[0;32m"$(BUILD)
	@echo "\033[1;42mSOURCE:         \033[0;32m"$(SOURCE)
	@echo "\033[1;42mINCLUDES:       \033[0;32m"$(INCLUDES)
	@echo "\033[1;42mLIBS:           \033[0;32m"$(LIBS)
	@echo "\033[1;42mOBJECTS:        \033[0;32m"$(OBJECTS)
	@echo "\033[1;42mCOMPILES_RULES: \033[0;32m"$(COMPILE_RULES)
	@echo "\033[0m================"

.PHONY: all example clean fclean re
