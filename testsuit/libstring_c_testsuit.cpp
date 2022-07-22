extern "C"
{
    // The library we want to test
    #include <string_c.h>
}

#include "cpp_basic_testsuit.hpp"

// Test if rmregex_string_t remove basic pattern found in str
f_testcase test32(void)
{
    string_t str = "Delete this pattern from here";
    char expr[] = "pattern";

    rmregex_string_t(str, expr);

    return (assert_strings_are_equal(str, "Delete this  from here"));
}

// Test if rmsubstr_string_t return zero when sub is null
f_testcase test31(void)
{
    string_t str = "Ghost, the same joke cuz i'm tired of testing this code";

    int ret = rmsubstr_string_t(str, NULL);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmsubstr_string_t return zero when str is null
f_testcase test30(void)
{
    char sub[] = "Ghost";

    int ret = rmsubstr_string_t(NULL, sub);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmsubstr_string_t return zero when there aren't any occurrencies of sub in str
f_testcase test29(void)
{
    string_t str = "No occurrence of sub will be here";
    char sub[] = "banana joke never fails";

    int ret = rmsubstr_string_t(str, sub);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmsubstr_string_t return how many occurrences of sub were removed
f_testcase test28(void)
{
    string_t str = "bananais poluting bananathe bananatextbanana";
    char sub[] = "banana";

    int ret = rmsubstr_string_t(str, sub);

    return (assert_integer_values_are_equal(ret, 4));
}

// Test if rmsubstr_string_t have all occurrences of sub
f_testcase test27(void)
{
    string_t str = "bananais poluting bananathe bananatextbanana";
    char sub[] = "banana";

    rmsubstr_string_t(str, sub);

    return (assert_strings_are_equal(str, "is poluting the text"));
}

// Test if rmsubstr_string_t does not remove when sub is not a exatcly match
f_testcase test26(void)
{
    string_t str = "there is something there";
    char sub[] = "there ";

    rmsubstr_string_t(str, sub);

    return (assert_strings_are_equal(str, "is something there"));
}

// Test if rmsubstr_string_t does not remove anything when there are no matches of sub in str
f_testcase test25(void)
{
    string_t str = "Nothing to be removed here";
    char sub[] = "text";

    rmsubstr_string_t(str, sub);

    return (assert_strings_are_equal(str, "Nothing to be removed here"));
}

// Test if rmsubstr_string_t removes substring in str
f_testcase test24(void)
{
    string_t str = "This string have this unpleasant sub to be removed";
    char sub[] = "unpleasant";

    rmsubstr_string_t(str, sub);

    return (assert_strings_are_equal(str, "This string have this  sub to be removed"));
}

// Test if rmchar_string_t return zero when ch is a null byte
f_testcase test23(void)
{
    string_t str = "String";

    int ret = rmchar_string_t(str, 0);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmchar_string_t return zero when str is null
f_testcase test22(void)
{
    int ret = rmchar_string_t(NULL, 'a');

    return (assert_integer_value_is_zero(ret));
}

// Test if rmchar_string_t return zero when no occurrences of character can be found in str
f_testcase test21(void)
{
    string_t str = "Fine text";

    int ret = rmchar_string_t(str, 'a');

    return (assert_integer_value_is_zero(ret));
}

// Test if rmchar_string_t return how many characters were removed
f_testcase test20(void)
{
    string_t str = "R*e*mov*e 5 c*hars*";

    int ret = rmchar_string_t(str, '*');

    return (assert_integer_values_are_equal(ret, 5));
}

// Test if rmchar_string_t does not remove characters when there isn't characters to be removed
f_testcase test19(void)
{
    string_t str = "Clean string";

    rmchar_string_t(str, 'd');

    return (assert_strings_are_equal(str, "Clean string"));
}

// Test if rmchar_string_t removes all ocurrences of characters in string
f_testcase test18(void)
{
    string_t str = "Rdedmodve daldl";

    rmchar_string_t(str, 'd');

    return (assert_strings_are_equal(str, "Remove all"));
}

// Test if trim_string_t return how many characters were removed when it trims only the begining of string
f_testcase test17(void)
{
    string_t str = "    trim 4 in the begining";

    int ret = trim_string_t(str);

    return (assert_integer_values_are_equal(ret, 4));
}

// Test if trim_string_t return how many characters were removed when it trims only the end of string
f_testcase test16(void)
{
    string_t str = "trim 4 in the end    ";

    int ret = trim_string_t(str);

    return (assert_integer_values_are_equal(ret, 4));
}

// Test if trim_string_t trims only the begining of str
f_testcase test15(void)
{
    string_t str = "      trim the begining";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "trim the begining"));
}

// Test if trim_string_t trims only the end of str
f_testcase test14(void)
{
    string_t str = "trim the end     ";

    trim_string_t(str);

    return (assert_strings_are_equal(str, "trim the end"));
}

// Test if trim_string_t return the number of whitespaces removed for str but with diverse whitespace chars
f_testcase test13(void)
{
    string_t str = " \t\rtrim\n\v\f";

    int ret = trim_string_t(str);

    return (assert_integer_values_are_equal(ret, 6));
}

// Test if trim_string_t return the number of whitespaces removed for str
f_testcase test12(void)
{
    string_t str = "    trim 8    ";

    int ret = trim_string_t(str);

    return (assert_integer_values_are_equal(ret, 8));
}

// Test if lshift_string_t shifts string correctly
f_testcase test11(void)
{
    string_t str = " Shift it";

    lshift_string_t(str, 0);

    return (assert_strings_are_equal(str, "Shift it"));
}

// Test if rmgroup_string_t return 0 when group is null
f_testcase test10(void)
{
    string_t str = "Test 10";

    int ret = rmgroup_string_t(str, NULL);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmgroup_string_t return 0 when str is null
f_testcase test9(void)
{
    char group[] = "abcde";

    int ret = rmgroup_string_t(NULL, group);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmgroup_string_t return 0 when no ocurrences are found
f_testcase test8(void)
{
    string_t str = "Nothing to change here";
    char group[] = "?!@#$%&*()";

    int ret = rmgroup_string_t(str, group);

    return (assert_integer_value_is_zero(ret));
}

// Test if rmgroup_string_t returns the correct number of removed chars
f_testcase test7(void)
{
    string_t str = "Iut w!ill ?remyove 4";
    char group[] = "u!?y";

    int ret = rmgroup_string_t(str, group);

    return (assert_integer_values_are_equal(ret, 4));
}

// Test if rmgroup_string_t correctly removes chars from str even when such chars are repeated in group
f_testcase test6(void)
{
    string_t str = "C0oddryurec!t |this|";
    char group[] = "00ddyyuu!!||";

    rmgroup_string_t(str, group);

    return (assert_strings_are_equal(str, "Correct this"));
}

// Test if rmgroup_string_t does not remove any chars when there aren't any matches in group
f_testcase test5(void)
{
    string_t str = "Clean string +1";
    char group[] = "ABbcDdEFfGHhIJjLMmNOoPpQqRSTUuVvWwXxYyZz234567890\"'!@#$%&*()_-=";

    rmgroup_string_t(str, group);

    return (assert_strings_are_equal(str, "Clean string +1"));
}

// Test if rmgroup_string_t remove all the chars found in group from str
f_testcase test4(void)
{
    string_t str = "gyasHello World-0181typç!+!+";
    char group[] = "-018agpstyç+";

    rmgroup_string_t(str, group);

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
    Assertion libstringTest4(&test4, "Test if rmgroup_string_t remove all the chars found in group from str");
    Assertion libstringTest5(&test5, "Test if rmgroup_string_t does not remove any chars when there aren't any matches in group");
    Assertion libstringTest6(&test6, "Test if rmgroup_string_t correctly removes chars from str even when such chars are repeated in group");
    Assertion libstringTest7(&test7, "Test if rmgroup_string_t returns the correct number of removed chars");
    Assertion libstringTest8(&test8, "Test if rmgroup_string_t return 0 when no ocurrences are found");
    Assertion libstringTest9(&test9, "Test if rmgroup_string_t return 0 when str is null");
    Assertion libstringTest10(&test10, "Test if rmgroup_string_t return 0 when group is null");
    Assertion libstringTest11(&test11, "Test if lshift_string_t shifts string correctly");
    Assertion libstringTest12(&test12, "Test if trim_string_t return the number of whitespaces removed for str");
    Assertion libstringTest13(&test13, "Test if trim_string_t return the number of whitespaces removed for str but with diverse whitespace chars");
    Assertion libstringTest14(&test14, "Test if trim_string_t trims only the end of str");
    Assertion libstringTest15(&test15, "Test if trim_string_t trims only the begining of str");
    Assertion libstringTest16(&test16, "Test if trim_string_t return how many characters were removed when it trims only the end of string");
    Assertion libstringTest17(&test17, "Test if trim_string_t return how many characters were removed when it trims only the begining of string");
    Assertion libstringTest18(&test18, "Test if rmchar_string_t removes all ocurrences of characters in string");
    Assertion libstringTest19(&test19, "Test if rmchar_string_t does not remove characters when there isn't characters to be removed");
    Assertion libstringTest20(&test20, "Test if rmchar_string_t return how many characters were removed");
    Assertion libstringTest21(&test21, "Test if rmchar_string_t return zero when no occurrences of character can be found in str");
    Assertion libstringTest22(&test22, "Test if rmchar_string_t return zero when str is null");
    Assertion libstringTest23(&test23, "Test if rmchar_string_t return zero when ch is a null byte");
    Assertion libstringTest24(&test24, "Test if rmsubstr_string_t removes substring in str");
    Assertion libstringTest25(&test25, "Test if rmsubstr_string_t does not remove anything when there are no matches of sub in str");
    Assertion libstringTest26(&test26, "Test if rmsubstr_string_t does not remove when sub is not a exatcly match");
    Assertion libstringTest27(&test27, "Test if rmsubstr_string_t have all occurrences of sub");
    Assertion libstringTest28(&test28, "Test if rmsubstr_string_t return how many occurrences of sub were removed");
    Assertion libstringTest29(&test29, "Test if rmsubstr_string_t return zero when there aren't any occurrencies of sub in str");
    Assertion libstringTest30(&test30, "Test if rmsubstr_string_t return zero when str is null");
    Assertion libstringTest31(&test31, "Test if rmsubstr_string_t return zero when sub is null");
    Assertion libstringTest32(&test32, "Test if rmregex_string_t remove basic pattern found in str");

    vector<Assertion> tests = {
        libstringTest1, libstringTest2, libstringTest3, libstringTest4,
        libstringTest5, libstringTest6, libstringTest7, libstringTest8,
        libstringTest9, libstringTest10, libstringTest11, libstringTest12,
        libstringTest13, libstringTest14, libstringTest15, libstringTest16,
        libstringTest17, libstringTest18, libstringTest19, libstringTest20,
        libstringTest21, libstringTest22, libstringTest23, libstringTest24,
        libstringTest25, libstringTest26, libstringTest27, libstringTest28,
        libstringTest29, libstringTest30, libstringTest31,
        libstringTest32,
    };

    AssertionSet testbattery(tests);

    testbattery.doAssertions();

    return 0;
}
