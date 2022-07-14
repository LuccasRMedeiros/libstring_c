extern "C"
{
    // The library we want to test
    #include <string_c.h>
}

#include "cpp_basic_testsuit.hpp"

// Test if rmchars_string_t remove all the chars found in group from str
int test4(void)
{
    string_t str = "gyasHello World-0181typç!+!";
    char group[] = "-018agpstyç!+";

    rmchars_string_t(str, group);

    return (assert_strings_are_equal(str, "Hello World!!"));
}

// Test if trim_string_t works with various whitespace chars
int test3(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "trim this"));
}

// Test if trim_string_t does not trim trimmed string
int test2(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "does not trim this"));
}

// Test if trim_string_t trims string_t str
int test1(void)
{
    string_t str = "         trim this          ";
    trim_string_t(str);
    
    return (assert_strings_are_equal(str, "trim this"));
}

int main(void)
{
    Test libstringTest1(&test1, "Test if trim_string_t trims string_t str");
    Test libstringTest2(&test2, "Test if trim_string_t does not trim trimmed string");
    Test libstringTest3(&test3, "Test if trim_string_t works with various whitespace chars");
    Test libstringTest4(&test4, "Test if rmchars_string_t remove all the chars found in group from str");

    Test tests[] = {
        libstringTest1,
        libstringTest2,
        libstringTest3,
        libstringTest4
    };

    Testsuit testbattery(tests, sizeof (tests) / sizeof (Test));

    testbattery.execTests();

    return 0;
}
