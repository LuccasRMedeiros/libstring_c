extern "C"
{
    #include <string_c.h>
}

#include <iostream>

using namespace std;

int assert_that_trim_string_t_works_with_various_whitespace_chars(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    // Return if str was correctly trimmed
    return (!strcmp(str, "trim this"));
}

int assert_that_trim_string_t_does_not_trim_trimmed_string(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    // Return if str didn't lose any data, making strcmp return 0
    return (!strcmp(str, "does not trim this"));
}

int assert_that_trim_string_t_trims_str(void)
{
    string_t str = "         trim this          ";

    trim_string_t(str);
    
    // Return if str was correctly trimmed, making strcmp return 0
    return (!strcmp(str, "trim this"));
}

class Assertion
{
    char name[64];
}

int main(void)
{
    int success = 0;

    success += assert_that_trim_string_t_trims_str();
    success += assert_that_trim_string_t_does_not_trim_trimmed_string();
    success += assert_that_trim_string_t_works_with_various_whitespace_chars();

    cout << "\e[0;34mFinished \e[1;34m3\e[0;34m tests\e[0m\n";
    cout << "\e[1;32m" << success << "\e[0;34m were successfully executed\e[0m\n";

    return success;
}
