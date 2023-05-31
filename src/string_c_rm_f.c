#include "string_c.h"

/**
 * @brief Verify if the character is in the group
 *
 * @return If the char is in group or not.
 */
static char char_is_in_group(const char ch, const string_d group)
{
    for (size_t c =0; group[c]; ++c)
    {
        if (ch == group[c])
            return 1;
    }

    return 0;
}

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
 * @brief Remove all ocurrences of one char and shift the string
 *
 * @param str: The string intended to be cleaned
 * @param ch: The character that is to be removed
 * @return How many chars were removed
 */
int rmchar_string_t(string_t str, const char ch)
{
    // When str or ch are null/zero return 0
    if (!str || !ch)
        return 0;

    int res = 0;
    size_t str_size = strlen(str);

    size_t c = 0;
    while (c < str_size)
    {
        if (str[c] == ch)
        {
            lshift_string_t(str, c);
            --str_size;
            ++res;
        }
        else
            ++c;
    }

    return res;
}

/**
 * @brief Remove chars from the string str.
 *
 * @param str The string_t
 * @param group The group of chars to be removed from the string
 * @return How many chars were removed from the string "str"
 */
int rmgroup_string_t(string_t str, const string_d group)
{
    // When there is no string or no group of chars return 0
    if (!str || !group)
        return 0;

    int res = 0;
    size_t str_size = strlen(str);

    size_t c = 0;
    while (c < str_size) // Only iterate when the character is intended to be on str
    {
        if (char_is_in_group(str[c], group))
        {
            lshift_string_t(str, c);
            --str_size;
            ++res;
        }
        else
            ++c;
    }

    return res;
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
