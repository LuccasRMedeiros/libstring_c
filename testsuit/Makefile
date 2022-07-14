# Rebuild the test suit

default:
	make -C ../ CFLAGS='-g' redefault
	rm -f exec_tests
	g++ -Wall -Wextra -Werror -g cpp_basic_testsuit.cpp libstring_c_testsuit.cpp -I ../src -L../ -lstring_c -o exec_tests
