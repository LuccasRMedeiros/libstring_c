# Run make all or just make to generate the static library
#
# To change the default STRING_SIZE call CFLAGS='-DSTRING_SIZE=n' with the make
# commands, 'n' being the new default size.

NAME = libstring_c.a

CC = gcc 

BUILD = build

SRC = $(wildcard src/*.c)

OBJECTS = $(addprefix $(BUILD)/, $(SRC:src/%.c=%.o))

INCLUDES = -I include/

CFLAGS = 

all: mkbuild $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $(OBJECTS)

$(BUILD)%.o: src/%.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
