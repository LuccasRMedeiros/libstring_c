# Run make all or just make to generate the static library
#
# To change the default STRING_SIZE call CFLAGS='-DSTRING_SIZE=n' with the make
# commands, 'n' being the new default size.

CC = gcc

BUILD = build

SRC = $(wildcard src/*.c)

OBJECTS = $(addprefix $(BUILD)/, $(SRC:src/%.c=%.o))

CFLAGS = 

# default rule generate a static library called when no parameters are called
default: mkbuild $(OBJECTS)
	ar -rcs libstring_c.a $(OBJECTS)

# install rule generate a shared library and places it on system libs directory
install: CFLAGS += -fpic

install: mkbuild $(OBJECTS)
	$(CC) -shared -o libstring_c.so $(OBJECTS)

$(BUILD)/%.o: src/%.c
	$(CC) -Wall -Wextra -Werror $(CFLAGS) -c $< -o $@

mkbuild:
	mkdir -p $(BUILD)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f libstring_c.a
	rm -f libstring_c.so

redefault: fclean default

reinstall: fclean install

autotest: CFLAGS := -g

autotest: redefault
	rm -f testsuit/exec_tests
	g++ -Wall -Wextra -Werror -g testsuit/cpp_basic_testsuit.cpp testsuit/libstring_c_testsuit.cpp -I ./src -L./ -lstring_c -o testsuit/exec_tests
	testsuit/exec_tests

log_vars:
	@echo "\033[0;32m CC:      \033[1;32m$(CC)\033[0m"
	@echo "\033[0;32m BUILD:   \033[1;32m$(BUILD)\033[0m"
	@echo "\033[0;32m SRC:     \033[1;32m$(SRC)\033[0m"
	@echo "\033[0;32m OBJECTS: \033[1;32m$(OBJECTS)\033[0m"
	@echo "\033[0;32m CFLAGS:  \033[1;32m$(CFLAGS)\033[0m"

.PHONY: default install clean fclean redefault reinstall
