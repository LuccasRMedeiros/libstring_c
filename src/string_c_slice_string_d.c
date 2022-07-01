#include "string_c.h"

/**
 * @brief Slices src and return the result in form of a string_d.
 *
 * @param const string_d src: The string to be sliced
 * @param const size_t start: The starting point
 * @param const size_t end: The ending point
 * @return A string_d with suficient memory allocated to hold the result of 
 * slice. NULL if malloc fails to allocate memory.
 */
string_d slice_string_d(const string_d src, const size_t start, const size_t end)
{
    size_t slice_size = (end - start) + 1; // Consider the terminating NULL byte
    string_d ret = malloc(sizeof(string_d) * slice_size);
    if (!ret)
        return NULL;

    // strncpy does not place a terminating NULL byte, so we shorten to copy only the bytes on range
    strncpy(ret, src + start, slice_size - 1);
    ret[slice_size] = '\0';

    return ret;
}
