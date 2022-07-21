#include "string_c.h"

/**
 * @brief Remove the whitespaces around the string. Rewrite str.
 *
 * @param str: A string_t to be trimmed
 * @return How many whitespace chars where removed
 */
int trim_string_t(string_t str)
{
    if (!str)
        return 0;
    
    int ret = 0;
    size_t start = 0;
    size_t end = strlen(str);
    string_t holder;

    while (isspace(str[start]))
    {
        ++start;
        ++ret;
    }

    while (isspace(str[end - 1]))
    {
        --end;
        ++ret;
    }

    const size_t limit = end - start;
    for (size_t c = 0; c < limit; ++c)
    {
        holder[c] = str[start];
        ++start;
    }
    strncpy(str, holder, limit);
    str[limit] = '\0';

    return ret;
}
