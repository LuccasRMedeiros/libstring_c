extern "C"
{
    // The library we want to test
    #include <string_c.h>
}

#include "cpp_basic_testsuit.hpp"

int test3(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    // Return if str was correctly trimmed
    return (!strcmp(str, "trim this"));
}

int test2(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    // Return if str didn't lose any data, making strcmp return 0
    return (!strcmp(str, "does not trim this"));
}

int test1(void)
{
    string_t str = "         trim this          ";
    trim_string_t(str);
    
    // Return if str was correctly trimmed, making strcmp return 0
    return (!strcmp(str, "trim this"));
}

int main(void)
{
    Test libstringTest1(&test1, "Test if trim_string_t trims string_t str");
    Test libstringTest2(&test2, "Test if trim_string_t does not trim trimmed string");
    Test libstringTest3(&test3, "Test if trim_string_t works with various whitespace chars");

    Test tests[] = {
        libstringTest1,
        libstringTest2,
        libstringTest3
    };

    Testsuit testbattery(tests, sizeof (tests) / sizeof (Test));

    testbattery.execTests();

    return 0;
}
