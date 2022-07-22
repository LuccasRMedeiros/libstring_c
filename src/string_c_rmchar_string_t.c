#include "string_c.h"

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
