# Run make all or just make to generate the static library
#
# To change the default STRING_SIZE call CFLAGS='-DSTRING_SIZE=n' with the make
# commands, 'n' being the new default size.

CC = gcc 

BUILD = build

SRC = $(wildcard src/*.c)

OBJECTS = $(addprefix $(BUILD)/, $(SRC:src/%.c=%.o))

INCLUDES = -I src/

CFLAGS = 

all: mkbuild $(OBJECTS)
	ar -rcs $(OBJECTS) libstring_c.a

$(BUILD)/%.o: src/%.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

mkbuild:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f libstring_c.a

re: fclean all

.PHONY: all clean fclean re
