# Run make all or just make to generate the static library
#
# To change the default STRING_SIZE call CFLAGS='-DSTRING_SIZE=n' with the make
# commands, 'n' being the new default size.

CC = gcc 

BUILD = build

SRC = $(wildcard src/*.c)

OBJECTS = $(addprefix $(BUILD)/, $(SRC:src/%.c=%.o))

CFLAGS = 

all: mkbuild $(OBJECTS)
	ar -rcs libstring_c.a $(OBJECTS)

$(BUILD)/%.o: src/%.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

mkbuild:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f libstring_c.a

re: fclean all

log_vars:
	@echo "\033[0;32m CC:      \033[1;32m$(CC)\033[0m"
	@echo "\033[0;32m BUILD:   \033[1;32m$(BUILD)\033[0m"
	@echo "\033[0;32m SRC:     \033[1;32m$(SRC)\033[0m"
	@echo "\033[0;32m OBJECTS: \033[1;32m$(OBJECTS)\033[0m"
	@echo "\033[0;32m CFLAGS:  \033[1;32m$(CFLAGS)\033[0m"

.PHONY: all clean fclean re
