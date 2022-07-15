extern "C"
{
    // The library we want to test
    #include <string_c.h>
}

#include "cpp_basic_testsuit.hpp"

// Test if rmchars_string_t remove all the chars found in group from str
f_testcase test4(void)
{
    string_t str = "gyasHello World-0181typç!+!";
    char group[] = "-018agpstyç+";

    rmchars_string_t(str, group);

    return (assert_strings_are_equal(str, "Hello World!!"));
}

// Test if trim_string_t works with various whitespace chars
f_testcase test3(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "trim this"));
}

// Test if trim_string_t does not trim trimmed string
f_testcase test2(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "does not trim this"));
}

// Test if trim_string_t trims string_t str
f_testcase test1(void)
{
    string_t str = "         trim this          ";
    trim_string_t(str);
    
    return (assert_strings_are_equal(str, "trim this"));
}

int main(void)
{
    Assertion libstringTest1(&test1, "Test if trim_string_t trims string_t str");
    Assertion libstringTest2(&test2, "Test if trim_string_t does not trim trimmed string");
    Assertion libstringTest3(&test3, "Test if trim_string_t works with various whitespace chars");
    Assertion libstringTest4(&test4, "Test if rmchars_string_t remove all the chars found in group from str");

    vector<Assertion> tests = {
        libstringTest1,
        libstringTest2,
        libstringTest3,
        libstringTest4
    };

    AssertionSet testbattery(tests);

    testbattery.doAssertions();

    return 0;
}
