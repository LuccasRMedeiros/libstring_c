#include "string_c.h"

/**
 * @brief Slices a string and place it inside dest. It differs from do 
 * strncpy(dest, src + startbyte, nbytes) because it prevents buffer overrun and
 * place a NULL terminating byte.
 *
 * @param string_t dest: The string_t that will receive the sliced string
 * @param const string_t src: The string to be sliced
 * @param size_t start: The starting point
 * @param size_t end: The ending point
 */
void slice_string_t(string_t dest, const string_t src, const size_t start, const size_t end)
{
    if (end >= STRING_SIZE) // end cannot be greater than the maximum elements in a string_t
        return;

    memset(dest, 0, STRING_SIZE);
    strncpy(dest, src + start, end - start);
}
