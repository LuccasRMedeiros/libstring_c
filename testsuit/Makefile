# Rebuild the test suit

default:
	make -C ../ CFLAGS='-g' redefault
	rm -f exec_test
	g++ -Wall -Wextra -Werror -g libstring_c_testsuit.cpp -I ../src -L../ -lstring_c -o exec_test
