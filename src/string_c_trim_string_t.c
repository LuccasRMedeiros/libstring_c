#include "string_c.h"

/**
 * @brief Remove the whitespaces around the string. Rewrite str.
 *
 * @param string_t str: Which string_t is to be trimmed
 */
void trim_string_t(string_t str)
{
    size_t start = 0;
    size_t end = strlen(str);
    string_t holder;

    memset(holder, 0, STRING_SIZE);

    while (isspace(str[start]))
        ++start;

    while (isspace(str[end]))
        --end;

    const size_t limit = end - start;
    for (size_t c = 0; c < limit; ++c)
    {
        holder[c] = str[start];
        ++start;
    }

    strcpy(str, holder);
}
