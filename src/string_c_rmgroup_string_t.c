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
