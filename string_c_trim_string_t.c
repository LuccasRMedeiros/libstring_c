#include "string_c.h"

/**
 * @brief Remove the whitespaces around the string
 *
 * @param string_t src: Which string_t is to be trimmed
 */
void trim_string_t(string_t src)
{
    size_t start = 0;
    size_t end = strlen(src);
    string_t holder;

    memset(holder, 0, sizeof (string_t));

    while (isspace(src[start]))
        ++start;

    while (isspace(src[end]))
        --end;

    const size_t limit = end - start;
    for (size_t c = 0; c < limit; ++c)
    {
        holder[c] = src[start];
        ++start;
    }

    memcpy(src, holder, sizeof(string_t));
}
