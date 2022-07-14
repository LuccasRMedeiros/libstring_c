#include "string_c.h"

/**
 * @brief Shift all the chars inside string to the left
 *
 * @param str The string_t
 * @param c The start point
 */
static void shift_chars(string_t str, size_t c)
{
    while (str[c])
    {
        str[c] = str[c + 1];
        ++c;
    }
}

/**
 * @brief Verify if the character is in the group
 *
 * @return If the char is in group or not.
 */
static char char_is_in_group(char ch, const string_d group)
{
    while (*group)
    {
        if (ch == *group)
            return 1;
        ++(*group);
    }

    return 0;
}

/**
 * @brief Remove chars from the string str.
 *
 * @param str The string_t
 * @param group The group of chars to be removed from the string
 * @return The total amount of chars removed from the string "str"
 */
int rmchars_string_t(string_t str, const string_d group)
{
    int res = 0;
    size_t str_size = strlen(str);

    // If there is no string or no group of chars return 0
    if (!str_size || !group)
        return res;

    size_t c = 0;
    while (c < str_size)
    {
        if (char_is_in_group(str[c], group))
        {
            shift_chars(str, c);
            --str_size;
            ++res;
        }
        else
            ++c;
    }

    return res;
}
