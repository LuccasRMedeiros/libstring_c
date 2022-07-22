#include "string_c.h"

// Check if the next sequence of "sub size" chars in str matches sub
static char is_substring(const string_d str, const string_d sub, size_t c)
{
    size_t sc;
    for (sc = 0; str[c] == sub[sc] && str[c]; ++sc)
        ++c;

    // When it reaches the end of sub, is understood that we found it
    if (!sub[sc])
        return 1;
    return 0;
}

/**
 * @brief Remove all the occurences of sub inside str.
 *
 * @param str: The string_t to be cleaned
 * @param sub: The sequence of chars that are to be removed from str
 * @return How many occurrences of sub were removed from str
 */
int rmsubstr_string_t(string_t str, const string_d sub)
{
    if (!str || !sub)
        return 0;

    int ret = 0;
    size_t sub_size = strlen(sub);

    for (size_t c = 0; str[c]; ++c)
    {
        if (is_substring(str, sub, c))
        {
            for (size_t rmc = 0; rmc < sub_size; ++rmc)
                lshift_string_t(str, c);

            ++ret;
        }
    }

    return ret;
}
